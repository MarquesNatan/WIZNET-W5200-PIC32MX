/*
 * File:   main.c
 * Author: Natan
 *
 * Created on 27 de Julho de 2020, 15:10
 */
// PIC32MM0256GPM064 Configuration Bit Settings
// 'C' source line configurations statements

// PIC32MX795F512L Configuration Bit Settings

// 'C' source line config statements

#if defined TESTE
/*** DEVCFG0 ***/

#pragma config DEBUG =      OFF
#pragma config ICESEL =     ICS_PGx2
#pragma config PWP =        OFF
#pragma config BWP =        OFF
#pragma config CP =         OFF

/*** DEVCFG1 ***/

#pragma config FNOSC =      PRIPLL
#pragma config FSOSCEN =    OFF
#pragma config IESO =       ON
#pragma config POSCMOD =    XT
#pragma config OSCIOFNC =   OFF
#pragma config FPBDIV =     DIV_1
#pragma config FCKSM =      CSECMD
#pragma config WDTPS =      PS128
#pragma config FWDTEN =     OFF
/*** DEVCFG2 ***/

#pragma config FPLLIDIV =   DIV_2
#pragma config FPLLMUL =    MUL_20
#pragma config FPLLODIV =   DIV_1
#pragma config UPLLIDIV =   DIV_2
#pragma config UPLLEN =     ON
/*** DEVCFG3 ***/

#pragma config USERID =     0xffff
#pragma config FSRSSEL =    PRIORITY_7
#pragma config FMIIEN =     OFF
#pragma config FETHIO =     ON
#pragma config FCANIO =     ON
#pragma config FUSBIDIO =   ON
#pragma config FVBUSONIO =  ON
#endif
#include <xc.h>


#include <stdint.h>
#include <stddef.h>

/*============================================================================*/
#include "FILES/PERIPHERAL/PERIPHERAL.h"
#include "FILES/SPI/spi32mx.h"
#include "FILES/TIMER/timer.h"

/*============================================================================*/
#include "FILES/WIZNET/wiznetinit.h"
#include "FILES/APP_SOCKET/app_socket.h"
/*============================================================================*/
#include "FILES/BOARD_PINOUT/board_pinout.h"
#include "FILES/GPIO/gpio.h"
#include "FILES/NVM/nvm.h"
#include "FILES/SPI/spi32mx_drv.h"

extern wiznetConfig ;
extern wizNetTimeout;  
spiconfig_t spiConfig = 
{
    .masterMode = SPI_MASTER_MODE, 
    .clockMode  = SPI1_CLOCK_MODE, 
    .SSPinMode  = SPI1_SS_MODE, 
    .commWidth  = SPI1_COMM_WIDTH, 
    .baudRate   = SPI1_BAUDRATE
};
socket_config_t socketConfig =
{
    .interfaceId    = WIZ_INTERFACE_ID, 
    .socketNumber   = WIZ_SOCK_NUMBER, 
    .type           = TYPE_CONNECTION, 
    .connectionFlag = WIZ_SOCK_FLAG, 
    .protocol       = TYPE_PROTOCOL, 
    .localPort      = PORT_5000 
};

#define SPI_INDEX     3

void main(void){
     
    TRISBbits.TRISB0 = 0x00;
    TRISBbits.TRISB1 = 0x00;
    TRISBbits.TRISB2 = 0x00;
    
    int i, j;
    
    while(1)
    {
        LATBbits.LATB0 = 0x00;
        LATBbits.LATB1 = 0x00;
        LATBbits.LATB2 = 0x00;
        
        for(i = 0; i < 200; i++)
        {
            for(j = 0; j < 200; j++)
            {
           
            }
        }
        LATBbits.LATB0 = 0x01;
        LATBbits.LATB1 = 0x01;
        LATBbits.LATB2 = 0x01;
        for(i = 0; i < 1000; i++)
        {
            for(j = 0; j < 1000; j++)
            {
           
            }
        }
    }
    uint8_t ip[4] = {0, 0, 0, 0};
    uint8_t mac[6] = {0, 0, 0, 0, 0, 0};
    
    PeripheralInit(NULL);
    // SpiInit(&spiConfig);
    SPI_3_INIT(&spiConfig);
    TimerInit();
    /* int WiznetInit(uint8_t* wizTxSize, uint8_t* wizRxSize, wiz_NetInfo* wizNetConfig,
                     wiz_NetTimeout* wizNetTimeout) */
    
    WiznetInit(NULL, NULL, &wiznetConfig, &wizNetTimeout);
    
    WiznetGetIp(ip);
    WiznetGetMac(mac);
    
    if(ip[0] != WIZ_IP_OCT_1 || ip[1] != WIZ_IP_OCT_2 || ip[2] != WIZ_IP_OCT_3 ||
       ip[3] != WIZ_IP_OCT_4)
    {
        while(1){}
    }
    
    if(mac[0] != WIZ_MAC_OCT_1 || mac[1] != WIZ_MAC_OCT_2 || mac[2] != WIZ_MAC_OCT_3 || 
       mac[3] != WIZ_MAC_OCT_4 || mac[4] != WIZ_MAC_OCT_5 || mac[5] != WIZ_MAC_OCT_6)
    {
        while(1){}
    }
    
    while(1)
    {
        loopbackTCP(&socketConfig);
        
    }
    return;
    
}
