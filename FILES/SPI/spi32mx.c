#include "spi32mx.h"
#include "../PERIPHERAL/PERIPHERAL.h"
#include "../GPIO/gpio.h"
#include "../BOARD_PINOUT/board_pinout.h"

#define  _XTAL_FREQ                   80000000
/*============================================================================*/
#ifdef PIC32MM
void SpiInit(spiconfig_t* spiConfig)
{
    SPI1CONbits.ON = 0x00;
    if(spiConfig->masterMode == SPI_MASTER_MODE)
    {
        SPI1CONbits.MSTEN = 0x01;
    }else
    {
        SPI1CONbits.MSTEN = 0x00;
    }
    
    switch(spiConfig->clockMode)
    {
        case 0:
            SPI1CONbits.CKP = 0x00;
            SPI1CONbits.CKE = 0x01;
            SPI1CONbits.SMP = 0x00;
            break;
        case 1:
            SPI1CONbits.CKP = 0x00;
            SPI1CONbits.CKE = 0x00;
            SPI1CONbits.SMP = 0x01;
            break;
        case 2:
            SPI1CONbits.CKP = 0x01;
            SPI1CONbits.CKE = 0x01;
            SPI1CONbits.SMP = 0x00;
            break;
        case 3:
            SPI1CONbits.CKP = 0x01;
            SPI1CONbits.CKE = 0x00;
            SPI1CONbits.SMP = 0x01;
            break;
    }
    
    if(spiConfig->SSPinMode == SPI_HARDWARE_SS)
    {
        SPI1CONbits.SSEN = 0x01;
    }else
    {
        SPI1CONbits.SSEN = 0x00;
    }
    switch(spiConfig->commWidth)
    {
        case SPI_COMM_WIDTH_8:
            SPI1CONbits.MODE32 = 0;
            SPI1CONbits.MODE16 = 0;
            break;
        case SPI_COMM_WIDTH_16:
            SPI1CONbits.MODE32 = 0;
            SPI1CONbits.MODE16 = 1;
            break;
        case SPI_COMM_WIDTH_32:
            SPI1CONbits.MODE32 = 1;
            SPI1CONbits.MODE16 = 0;
            break; 
    }
    uint32_t t_brg;
    uint32_t baudHigh;
    uint32_t baudLow;
    uint32_t errorHigh;
    uint32_t errorLow;
    
    uint32_t desiredBaudRate = spiConfig->baudRate;

    t_brg = (((_XTAL_FREQ/desiredBaudRate)/2u) - 1u);  

    baudHigh = _XTAL_FREQ / (2u * (t_brg + 1u));
    baudLow = _XTAL_FREQ / (2u * (t_brg + 2u));
    errorHigh = baudHigh - desiredBaudRate;
    errorLow = desiredBaudRate - baudLow; 
    if (errorHigh > errorLow)
    {
        t_brg++;
    }   
    
    SPI1BRG = t_brg;
    SPI1CONbits.FRMEN = 0;
    SPI1CONbits.ENHBUF = 0;
    SPI1CONbits.STXISEL = 0x00;
    SPI1CONbits.SRXISEL = 0x00;
    
    uint32_t dummy = 0u;                 
    while(0u != SPI1STATbits.SPIRBF)
    {             
        dummy = SPI1BUF;
    }                                                                           
    (void)dummy;
    SPI1STATbits.SPIROV = 0;
    SPI1CONbits.ON = 1;
}

void SpiWrite(void* transBuffer, uint8_t lengthBuffer)
{
    char* data = (char*)transBuffer;
    unsigned char dummy;
    while(!SPI1STATbits.SPITBE);
    
    dummy = SPI1BUF;
    SPI1BUF = *data;
    
    while(!SPI1STATbits.SPIRBF);
    dummy = SPI1BUF;
}

uint8_t SpiRead(uint8_t* receiveBuffer, uint8_t lengthBuffer)
{
     
    while(!SPI1STATbits.SPITBE);
   //  while(!SPI1STATbits.SPIRBE);
    SPI1BUF = 0x00;
    
    while(!SPI1STATbits.SPIRBF);
    *receiveBuffer = SPI1BUF;
}
#endif /*PIC32MM*/

#ifdef PIC32MX

void SPI_3_INIT(spiconfig_t* spiConfig)
{                                                           
    /*  disable the SPI (ON):              */                                  
    /*      1 = SPI Peripheral is enabled  */                                  
    /*      0 = SPI Peripheral is disabled */                                  
    SPI3CONbits.ON = 0;                                                
                                                                               
    /*  Set up Master or Slave Mode (MSTEN): */                                
    /*      1 = Master mode */                                                 
    /*      0 = Slave mode */
    if(spiConfig->masterMode == SPI_MASTER_MODE)
        SPI3CONbits.MSTEN = 1;
    else
        SPI3CONbits.MSTEN = 0;
                                                                                                                                                      
    /*  Set up if the SPI is allowed to run */                                 
    /*  while the rest of the CPU is in idle mode (SIDL): */                   
    /*      1 = Discontinue operation when CPU enters in Idle mode */          
    /*      0 = Continue operation in Idle mode */                                                                                         
    SPI3CONbits.SIDL = 0;                                          
                                                                                                                                                   
    /*  Set up close Polarity (CKP): */                                        
    /*      1 = Idle state for clock is a high level; */                       
    /*           active state is a low level */                                
                                                                               
    /*      0 = Idle state for clock is a low level; */                        
    /*           active state is a high level */                               
    /*  Set output data phase (CKE): */                                        
                                                                               
    /*      1 = Serial output data changes on transition from */               
    /*          active clock state to Idle clock state (see CKP bit) */        
    /*      0 = Serial output data changes on transition from Idle clock state */
    /*          to active clock state (see CKP bit) */ 
    switch(spiConfig->clockMode)
    {
        case SPI_CLOCK_MODE_0:
            SPI3CONbits.CKP = 0;                                       
            SPI3CONbits.CKE = 1;                                       
            SPI3CONbits.SMP = 0;             
            break;
        case SPI_CLOCK_MODE_1:
            SPI3CONbits.CKP = 0;                                       
            SPI3CONbits.CKE = 0;                                       
            SPI3CONbits.SMP = 1;              
            break;
        case SPI_CLOCK_MODE_2:
            SPI3CONbits.CKP = 1;                                       
            SPI3CONbits.CKE = 1;                                       
            SPI3CONbits.SMP = 0;              
            break;
        case SPI_CLOCK_MODE_3:
            SPI3CONbits.CKP = 1;                                       
            SPI3CONbits.CKE = 0;                                       
            SPI3CONbits.SMP = 1;              
            break;            
    }                                        
                                                                 
    /*  Enable the SSx Pin on slave side if needed (SSEN); */                  
    /*  1 = SSx pin used for Slave mode */                                     
    /*  0 = SSx pin not used for Slave mode */                                 
    /* (pin is controlled by port function) */
    if(spiConfig->SSPinMode == SPI_HARDWARE_SS)
        SPI3CONbits.SSEN = 1;
    else
        SPI3CONbits.SSEN = 0;
                                                                      
    /*  Communication Width Selection: */                                      
    /*  MODE32 | MODE16 | Communication */                                     
    /*     1   |    x   |   32-bit */                                          
    /*     0   |    1   |   16-bit */                                          
    /*     0   |    0   |    8-bit */
    switch(spiConfig->commWidth)
    {
        case SPI_COMM_WIDTH_8:
            SPI3CONbits.MODE32 = 0;                                        
            SPI3CONbits.MODE16 = 0;            
            break;
        case SPI_COMM_WIDTH_16:
            SPI3CONbits.MODE32 = 0;                                        
            SPI3CONbits.MODE16 = 1;             
            break;
        case SPI_COMM_WIDTH_32:
            SPI3CONbits.MODE32 = 1;                                        
            SPI3CONbits.MODE16 = 0;            
            break;      
    }                                    
                         
    /*  BRG = (clockFrequency/(2 * baudRate)) - 1 */                           
    /*  This is standard formula for calculating baud rate. */                 
    uint32_t t_brg;                                                            
    uint32_t baudHigh;                                                         
    uint32_t baudLow;                                                          
    uint32_t errorHigh;                                                        
    uint32_t errorLow;
    
    uint32_t desiredBaudRate = spiConfig->baudRate;

    t_brg = (((_XTAL_FREQ/desiredBaudRate)/2u) - 1u);  

    baudHigh = _XTAL_FREQ / (2u * (t_brg + 1u));
    baudLow = _XTAL_FREQ / (2u * (t_brg + 2u));
    errorHigh = baudHigh - desiredBaudRate;
    errorLow = desiredBaudRate - baudLow; 
    if (errorHigh > errorLow)
    {
        t_brg++;
    }                                                                                                                                                    
    SPI3BRG = t_brg;
                                                                                                                                                               
    /*  Set Procotol Type Selection  */                                        
    /*  (FRMEN) */                                                             
    /*      1 = Framed SPI support is enabled */                               
    /* (SSx pin used as FSYNC input/output) */                                 
    /*      0 = Framed SPI support is disabled (Standard Type) */                                              
    SPI3CONbits.FRMEN = 0;                                                                                       
                                                                                                                                                                                
    /*  Set SPI Buffer Type (ENHBUF): */                                       
    /*      1 = Enhanced Buffer mode is enabled */                             
    /*      0 = Enhanced Buffer mode is disabled (Standard Buffer Type) */                                                                           
    SPI3CONbits.ENHBUF = 0;                                        
    /* @@P */                                                              
    /* SPI Transmit Buffer Empty Interrupt Mode (STXISEL): */              
    /* Interrupt is generated when the buffer is completely empty */       
    SPI3CONbits.STXISEL = 0x00;                                    

    /*  SPI Receive Buffer Full Interrupt Mode (SRXISEL): */               
    /*  Interrupt is generated when the buffer is not empty */             
    SPI3CONbits.SRXISEL = 0x00;                                    
                                                                               
    /* Clear SPI Buffer */                                                     
    uint32_t dummy = 0u;                                                       
                                                                               
    /* For enhanced buffer mode, Read the SPIxBUF till RX FIFO gets empty */                                                                        
    while(0u != SPI3STATbits.SPIRBE)                               
    {                                                                      
        /* Read the SPIxBUF to flush it */                                 
        dummy = SPI3BUF;                                           
    }                                                                      
                                                             
    /* Neglect unused variable */                                              
    (void)dummy;                                                               
                                                                               
    SPI3STATbits.SPIROV = 0;                                           
                                                                               
    /* Note: We do not enable the SPI here, */                                 
    /* that will be done by the first client. */                               
                                                                               
    /*  Enable the SPI (ON):              */                                   
    /*      1 = SPI Peripheral is enabled  */                                  
    /*      0 = SPI Peripheral is disabled */                                  
    SPI3CONbits.ON = 1;                         
}

void SpiWrite(void* transBuffer, uint8_t lengthBuffer)
{
    char* data = (char*)transBuffer;
    unsigned char dummy;
    while(!SPI3STATbits.SPITBE);
    
    dummy = SPI3BUF;
    SPI3BUF = *data;
    
    while(!SPI3STATbits.SPIRBF);
    dummy = SPI3BUF;
}

uint8_t SpiRead(uint8_t* receiveBuffer, uint8_t lengthBuffer)
{
     
    while(!SPI3STATbits.SPITBE);
   //  while(!SPI1STATbits.SPIRBE);
    SPI3BUF = 0x00;
    
    while(!SPI3STATbits.SPIRBF);
    *receiveBuffer = SPI3BUF;
}

#endif /*PIC32MX*/