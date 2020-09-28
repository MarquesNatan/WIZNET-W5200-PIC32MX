#include <xc.h>
#include <sys/kmem.h>
#include"nvm.h"
/*============================================================================*/
#define NVM_PROGRAM_FLASH         0x05      // 0101 = Program Flash (PFM) erase operation: erases PFM, if all pages are not write-protected
#define NVM_PAGE_ERASE            0x04      // 0100 = Page erase operation: erases page selected by NVMADDR, if it is not write-protected
#define NVM_ROW_PROGRAM           0x03      // 0011 = Row program operation: programs row selected by NVMADDR, if it is not write-protected
#define NVM_WORD_PROGRAM          0x01      // 0001 = Word program operation: programs word selected by NVMADDR, if it is not write-protected
#define NVM_NO_OP                 0x00      // 0000 = No operation
/*============================================================================*/
#define NVM_WR                    0x0008000
#define NVM_WREN                  0x0004000
#define NVM_WRERR                 0x0002000
#define NVM_LVDERR                0x0001000
/*============================================================================*/
static const uint32_t __attribute__((space(prog), address(0xBD07F000))) flashTestPage;
/*============================================================================*/
uint32_t NVM_Unlock(uint32_t nvmop)
{
    uint32_t status;
    // Suspend or Disable all Interrupts
    asm volatile("di %0" : "=r" (status));
    // Enable Flash Write/Erase Operations and Select
    // Flash operation to perform
    NVMCON = nvmop | NVM_WREN;
    // Write Keys
    NVMKEY = 0xAA996655;
    NVMKEY = 0x556699AA;
    // Start the operation using the Set Register
    NVMCONSET = NVM_WR;
    // Wait for operation to complete
    while (NVMCON & NVM_WR);
    // Restore Interrupts
    if(status & 0x00000001)
    {
        asm volatile("ei");
    }
    else
    {
        asm volatile("di");
    }
    // Disable NVM write enable
    NVMCONCLR = NVM_WREN;
    // Return WRERR and LVDERR Error Status Bits
    return (NVMCON & (NVM_LVDERR | NVM_WRERR));
}
/*============================================================================*/
uint32_t NVM_Write_Word (void* address, uint32_t data)
{
    uint32_t res;
    // Load data into NVMDATA register
#if defined NVMDATA
    NVMDATA = data;
#else
    NVMDATA0 = data;
#endif
    // Load address to program into NVMADDR register
    NVMADDR = KVA_TO_PA(address);
    // Unlock and Write Word
    res = NVM_Unlock(NVM_WORD_PROGRAM);
    // Return Result
    return res;
}

/*============================================================================*/
uint32_t NVM_Write_Row (void* address, void* data)
{
    uint32_t res;
    // Set NVMADDR to Start Address of row to program
    NVMADDR = KVA_TO_PA(address);
    // Set NVMSRCADDR to the SRAM data buffer Address
    NVMSRCADDR = (uint32_t)KVA_TO_PA(data);
    // Unlock and Write Row
    res = NVM_Unlock(NVM_ROW_PROGRAM);
    // Return Result
    return res;
}
/*============================================================================*/
uint32_t NVM_Erase_Page(void* address)
{
    uint32_t res;
    // Set NVMADDR to the Start Address of page to erase
    NVMADDR = KVA_TO_PA(address);
    // Unlock and Erase Page
    res = NVM_Unlock(NVM_PAGE_ERASE);
    // Return Result
    return res;
}
/*============================================================================*/
uint32_t NVM_Clear_Error (void)
{
    uint32_t res;
    // Unlock and Write
    res = NVM_Unlock(NVM_NO_OP);
    // Return Result
    return res;
}
/*============================================================================*/

uint32_t NVM_Read_Word(void* address)
{
    uint32_t res;
    res = *(uint32_t*)address;
    return res;
}

int32_t NVM_Teste(void)
{
    int32_t data = 0xAABBCC;
    int32_t result;
    result = NVM_Erase_Page((void*)&flashTestPage);
    result = NVM_Write_Word((void*)&flashTestPage, data);
    
    result = NVM_Read_Word((void*)&flashTestPage);
    
    return result;  
}