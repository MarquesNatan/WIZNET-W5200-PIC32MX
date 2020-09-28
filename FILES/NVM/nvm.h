#ifndef NVM_H
#define NVM_H


#define FLASH_WRITE_ROW_SIZE_IN_INSTRUCTIONS  128
#define FLASH_ERASE_PAGE_SIZE_IN_INSTRUCTIONS (FLASH_WRITE_ROW_SIZE_IN_INSTRUCTIONS*8)

#define FLASH_WRITE_ROW_SIZE_IN_PC_UNITS (FLASH_WRITE_ROW_SIZE_IN_INSTRUCTIONS*4)
#define FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS  (FLASH_ERASE_PAGE_SIZE_IN_INSTRUCTIONS*4)

#define FLASH_ERASE_PAGE_MASK    (~((FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS) - 1)) 

/*============================================================================*/
uint32_t NVM_Write_Row (void* address, void* data);
uint32_t NVM_Write_Word (void* address, uint32_t data);
uint32_t NVM_Erase_Page(void* address);
uint32_t NVM_Socket(uint32_t data, uint32_t address);
int32_t NVM_Teste(void);
/*============================================================================*/




#endif