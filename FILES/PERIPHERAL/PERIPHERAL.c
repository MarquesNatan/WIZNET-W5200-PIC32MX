#include "PERIPHERAL.h"
#include "../BOARD_PINOUT/board_pinout.h"
#include "../GPIO/gpio.h"

/*============================================================================*/

void PeripheralInit(void* args)
{
    // CONFIGURE_PIN_DIGITAL(type, port, mask) 
    // DIGITAL_PIN_WRITE(value, port, mask)
    
    /* Configure pins SPI Port as OUTPUT and INPUT */
    CONFIGURE_PIN_DIGITAL(OUTPUT_PIN, SPI1_MOSI_PORT, SPI1_MOSI_MASK);
    CONFIGURE_PIN_DIGITAL(OUTPUT_PIN, SPI1_SCK_PORT, SPI1_SCK_MASK);
    CONFIGURE_PIN_DIGITAL(OUTPUT_PIN, SPI1_CS_PORT, SPI1_CS_MASK);
    CONFIGURE_PIN_DIGITAL(INPUT_PIN, SPI1_MISO_PORT, SPI1_MISO_MASK);
    
    /* Configure reset pin wiznet module D1 */
    CONFIGURE_PIN_DIGITAL(OUTPUT_PIN, WIZ_RST_PORT, WIZ_RST_MASK);
    CONFIGURE_PIN_DIGITAL(OUTPUT_PIN, WIZ_PWRDOWN_PORT, WIZ_PWRDOWN_MASK);
    
    DIGITAL_PIN_WRITE(PIN_LOW, WIZ_PWRDOWN_PORT, WIZ_PWRDOWN_MASK);
    
}

/*============================================================================*/
void SpiSelect(void)
{
    DIGITAL_PIN_WRITE(PIN_LOW, SPI1_CS_PORT, SPI1_CS_MASK);
}

void SpiDeselect(void)
{
    DIGITAL_PIN_WRITE(PIN_HIGH, SPI1_CS_PORT, SPI1_CS_MASK);
}
/*============================================================================*/

void WiznetReset(void)
{
    DIGITAL_PIN_WRITE(PIN_LOW, WIZ_RST_PORT, WIZ_RST_MASK);   
}

void WiznetStart(void)
{
    DIGITAL_PIN_WRITE(PIN_HIGH, WIZ_RST_PORT, WIZ_RST_MASK);
}