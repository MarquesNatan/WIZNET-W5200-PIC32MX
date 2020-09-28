#ifndef SPI32MX_H
#define SPI32MX_H

#include <stdint.h>
/*============================================================================*/
#define SPI_MASTER_MODE                 0x01
#define SPI_SLAVE_MODE                  0x00

#define SPI_CLOCK_MODE_0                0x00
#define SPI_CLOCK_MODE_1                0x01
#define SPI_CLOCK_MODE_2                0x02
#define SPI_CLOCK_MODE_3                0x03


#define SPI_HARDWARE_SS                 0x01
#define SPI_SOFTWARE_SS                 0x00



#define SPI_COMM_WIDTH_8                0x00
#define SPI_COMM_WIDTH_16               0x01
#define SPI_COMM_WIDTH_32               0x03

#define SPI_BAUDRATE                     4000000

/*============================================================================*/

#define SPI1_MODE                       SPI_MASTER_MODE
#define SPI1_CLOCK_MODE                 SPI_CLOCK_MODE_3
#define SPI1_SS_MODE                    SPI_SOFTWARE_SS
#define SPI1_COMM_WIDTH                 SPI_COMM_WIDTH_8
#define SPI1_BAUDRATE                   SPI_BAUDRATE


/*============================================================================*/
typedef struct 
{
    uint8_t masterMode;
    uint8_t clockMode;
    uint8_t SSPinMode;
    uint8_t commWidth;
    uint32_t baudRate;
    
}spiconfig_t;
/*============================================================================*/
void SpiInit(spiconfig_t* spiConfig);

/*============================================================================*/
void SpiWrite(void* transBuffer, uint8_t lengthBuffer);
uint8_t SpiRead(uint8_t* receiveBuffer, uint8_t lengthBuffer);
/*============================================================================*/
#endif /*SPI32MX_H*/