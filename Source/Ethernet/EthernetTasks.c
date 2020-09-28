/*********************************************************************
 *
 *                  PIC32 Boot Loader
 *
 *********************************************************************
 * FileName:        EthernetTasks.c
 * Dependencies:
 * Processor:       PIC32
 *
 * Compiler:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * $Id:  $
 * $Name: $
 **********************************************************************/
/*
#include "Include\GenericTypeDefs.h"
#include "Include\HardwareProfile\HardwareProfile.h"
#include "Include\Bootloader.h"
#include "Include\FrameWork\Framework.h"
#include <stdlib.h>
#include <plib.h>
// Include all headers for any enabled TCPIP Stack functions
#include "Include\TCPIP Stack\TCPIP.h"
*/

#include "../../Include/GenericTypeDefs.h"
#include "../../Include/HardwareProfile/HardwareProfile.h"
#include "../../Include/BootLoader.h"
#include "../../Include/Framework/Framework.h"
#include "../../Include/Ethernet/EthernetTasks.h"
#include "../../Include/Coretimer.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "../../Include/Wiznet/socket.h"
#include "../../Include/HardwareProfile/HardwareProfile_PIC32MX.h"
/*============================================================================*/
#define TX_BUFF_SIZE        128
#define RX_BUFF_SIZE        FRAMEWORK_BUFF_SIZE

/*============================================================================*/
uint8_t socketNumber = 0;

wiz_NetInfo wiznetNetInfo;

uint8_t broadcastAddr[4] = {255, 255, 255, 255};
uint8_t hostAddr[4] = {0xFF, 0xFF, 0xFF, 0xFF};

uint8_t wiznetTxSize[8] = {                8, 8,
                                            0, 0,
                                            0, 0,
                                            0, 0};

uint8_t wiznetRxSize[8] = {                8, 8,
                                            0, 0,
                                            0, 0,
                                            0, 0};

wiz_NetInfo wiznetConfig =
{
    .mac = {MAC_ADDR_BYTE1 ,MAC_ADDR_BYTE2 ,MAC_ADDR_BYTE3 ,MAC_ADDR_BYTE4 ,MAC_ADDR_BYTE5 , MAC_ADDR_BYTE6},
    .ip = {IP_ADDR_BYTE1, IP_ADDR_BYTE2, IP_ADDR_BYTE3, IP_ADDR_BYTE4},
    .sn = {IP_MASK_BYTE1, IP_MASK_BYTE2, IP_MASK_BYTE3, IP_MASK_BYTE4},
    .gw = {IP_GATE_BYTE1, IP_GATE_BYTE2, IP_GATE_BYTE3, IP_GATE_BYTE4},
    .dhcp = NETINFO_STATIC
};

uint8_t rxBuff[RX_BUFF_SIZE] = {0};
uint8_t txBuff[TX_BUFF_SIZE] = {0};
/*============================================================================*/
void selectWiznet()
{
    WIZ_CS_IO = 0;
}

void deselectWiznet()
{
    WIZ_CS_IO = 1;
}

void spiWiznetWriteByte(uint8_t data)
{
    uint8_t dummy;

    while(!WIZ_SPISTATbits.SPITBE);

    dummy = WIZ_SSPBUF;
    WIZ_SSPBUF = data;

    while(!WIZ_SPISTATbits.SPIRBF);
    
    dummy = WIZ_SSPBUF;
}

uint8_t spiWiznetReadByte()
{
    uint8_t data;

    while(!WIZ_SPISTATbits.SPITBE);
    WIZ_SSPBUF = 0x00;
    while(!WIZ_SPISTATbits.SPIRBF);
    data = WIZ_SSPBUF;
    return data;
}
/*============================================================================*/
/********************************************************************
* Function: 	Wiznet Setup()
*
* Precondition: 
*
* Input: 		None.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview: 	Loads application configured IP address and MAC address.
*
*			
* Note:		 	None.
********************************************************************/
void WiznetSetup(void)
{
    int wizStatus;
    
    

    /* Initialize Wiznet SPI */
    WIZ_CS_TRIS = 0;
    WIZ_RST_TRIS = 0;

    /*  disable the SPI (ON):              */
    /*      1 = SPI Peripheral is enabled  */
    /*      0 = SPI Peripheral is disabled */
    WIZ_SPICONbits.ON = 0;

    /*  Set up Master or Slave Mode (MSTEN): */
    /*      1 = Master mode */
    /*      0 = Slave mode */
    WIZ_SPICONbits.MSTEN = 1;

    /*  Set up if the SPI is allowed to run */
    /*  while the rest of the CPU is in idle mode (SIDL): */
    /*      1 = Discontinue operation when CPU enters in Idle mode */
    /*      0 = Continue operation in Idle mode */
    WIZ_SPICONbits.SIDL = 0;

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
 
    WIZ_SPICONbits.CKP = 1;
    WIZ_SPICONbits.CKE = 0;
    WIZ_SPICONbits.SMP = 1;

    /*  Enable the SSx Pin on slave side if needed (SSEN); */
    /*  1 = SSx pin used for Slave mode */
    /*  0 = SSx pin not used for Slave mode */
    /* (pin is controlled by port function) */
    WIZ_SPICONbits.SSEN = 0;

    /*  Communication Width Selection: */
    /*  MODE32 | MODE16 | Communication */
    /*     1   |    x   |   32-bit */
    /*     0   |    1   |   16-bit */
    /*     0   |    0   |    8-bit */
    WIZ_SPICONbits.MODE32 = 0;
    WIZ_SPICONbits.MODE16 = 0;
          

    /*  BRG = (clockFrequency/(2 * baudRate)) - 1 */
    /*  This is standard formula for calculating baud rate. */
    uint32_t t_brg;
    uint32_t baudHigh;
    uint32_t baudLow;
    uint32_t errorHigh;
    uint32_t errorLow;
    uint32_t pbClk = SYS_FREQ;

    uint32_t desiredBaudRate = 40000000UL;



    t_brg = (((pbClk/desiredBaudRate)/2u) - 1u);

    baudHigh = pbClk / (2u * (t_brg + 1u));
    baudLow = pbClk / (2u * (t_brg + 2u));
    errorHigh = baudHigh - desiredBaudRate;
    errorLow = desiredBaudRate - baudLow;

    if (errorHigh > errorLow)
    {
        t_brg++;
    }
    WIZ_SPIBRG = t_brg;

    /*  Set Procotol Type Selection  */
    /*  (FRMEN) */
    /*      1 = Framed SPI support is enabled */
    /* (SSx pin used as FSYNC input/output) */
    /*      0 = Framed SPI support is disabled (Standard Type) */
    WIZ_SPICONbits.FRMEN = 0;

    /*  Set SPI Buffer Type (ENHBUF): */
    /*      1 = Enhanced Buffer mode is enabled */
    /*      0 = Enhanced Buffer mode is disabled (Standard Buffer Type) */
    WIZ_SPICONbits.ENHBUF = 0;
    /* @@P */
    /* SPI Transmit Buffer Empty Interrupt Mode (STXISEL): */
    /* Interrupt is generated when the buffer is completely empty */
    WIZ_SPICONbits.STXISEL = 0x00;

    /*  SPI Receive Buffer Full Interrupt Mode (SRXISEL): */
    /*  Interrupt is generated when the buffer is not empty */
    WIZ_SPICONbits.SRXISEL = 0x00;

    /* Clear SPI Buffer */
    uint32_t dummy = 0u;

    /* For enhanced buffer mode, Read the SPIxBUF till RX FIFO gets empty */
    while(0u != WIZ_SPISTATbits.SPIRBE)
    {
        /* Read the SPIxBUF to flush it */
        dummy = WIZ_SSPBUF;
    }

    /* Neglect unused variable */
    (void)dummy;

    WIZ_SPISTATbits.SPIROV = 0;

    /* Note: We do not enable the SPI here, */
    /* that will be done by the first client. */

    /*  Enable the SPI (ON):              */
    /*      1 = SPI Peripheral is enabled  */
    /*      0 = SPI Peripheral is disabled */
    WIZ_SPICONbits.ON = 1;
    
    /* Reset Wiznet */
    WIZ_RST_IO = 0;

    /* Delay min 40us */
    CoreTimer_DelayUs(100);

    /* Start Wiznet */
    WIZ_RST_IO = 1;

    /* Delay min 150ms */
    CoreTimer_DelayUs(250000);

    reg_wizchip_cris_cbfunc(NULL, NULL);
    reg_wizchip_cs_cbfunc(selectWiznet, deselectWiznet);
    reg_wizchip_spi_cbfunc(spiWiznetReadByte,spiWiznetWriteByte);

    wizStatus = wizchip_init(wiznetTxSize, wiznetRxSize);
    
    // Sets the defaults contained in wiznetConfig
    wizchip_setnetinfo(&wiznetConfig);
}
/********************************************************************
* Function: 	ethernetInit()
*
* Precondition: 
*
* Input: 		peripheral bus clock (Not used).
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview: 	Initializes the IP address, TCPIP stack, creates UDP socket.
*
*			
* Note:		 	None.
********************************************************************/
void ethernetInit(UINT pbClk)
{
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)))
		#error("TODO: For PIC32MX1xx/PIC32MX2xx devices, user should take care of mapping the ports to required pins");
		/* Example Code (if SPI2 is the interface)
	    PPSInput(3,SDI2,RPn); // SDI2 mapping, where RPn = RPA2, RPB6....
    	
    	PPSOutput(2,RPn,SDO2);// SDO2 mapping, where RPn = RPA1, RPB5....
    
    	//Do not forget to switch-off corrresponding "analog selection".
    	ANSELx = 0;
    	*/
#endif
	// Enable multi-vectored interrupts
    __builtin_enable_interrupts();
    
    // Configurate Wiznet wiz820io
    WiznetSetup();
    
    // Open UDP Socket
    socket(socketNumber, Sn_MR_UDP, UDP_BTL_PORT, 0);
    
    // Get information
    wizchip_getnetinfo(&wiznetNetInfo);
} 



/********************************************************************
* Function: 	ethernetTasks()
*
* Precondition: 
*
* Input: 		None.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview:     Receive packets from UDP and send packets on UDP.
*
*			
* Note:		 	None.
********************************************************************/
void ethernetTasks(void)
{
	
	static uint8_t remoteaddr[4];
    static uint8_t* sendAddr = broadcastAddr;
    static uint16_t remotePort = UDP_BTL_PORT;
    
	int32_t nBytes = 0;
	uint32_t txLen = 0;
	int32_t avlBytes = 0;
    uint16_t recvPort;
    

	// Check if bootloader has something to send out to PC.
	txLen = FRAMEWORK_GetTransmitFrame(txBuff);


    // Check if it is time to broadcast the board.
    
	if(txLen)
	{

		while(nBytes < txLen)
		{
            nBytes += sendto(socketNumber, txBuff + nBytes, txLen - nBytes, sendAddr, remotePort);
		}
        // Make sure all bytes are transmitted.
	}
	else
	{
		avlBytes =  wiz_bytes_to_read(socketNumber);;

		if(avlBytes > sizeof(rxBuff))
		{
			// PC application is pumping more data than device can handle.
			avlBytes = sizeof(rxBuff);
		}

	    if(avlBytes)
		{
            nBytes = recvfrom(socketNumber, rxBuff, avlBytes, remoteaddr, &recvPort);
	  		if(nBytes)
	  		{
                //Check if package received is from wiznet itself
                remotePort = recvPort;
                // Pass the bytes to frame work.
                sendAddr = remoteaddr;
                if(GetBootStatus() == UPGRADE)
                {
                    FRAMEWORK_BuildRxFrame(rxBuff, nBytes);
                }
                else if(GetBootStatus() == WAIT)
                {
                    if(nBytes == sizeof(ENTER_UPGRADE_COMMAND))
                    {
                        rxBuff[nBytes - 1] = '\0';
                        if(strcmp(rxBuff, ENTER_UPGRADE_COMMAND) == 0)
                        {
                            SetTrigger();
                        }
                    }
                }
                
		  	}
		}

	}
}


/********************************************************************
* Function: 	disableInterrupt()
*
* Precondition: 
*
* Input: 		None.
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview:     Disables all interrupts used by ethernet.
*
*			
* Note:		 	None.
********************************************************************/
void disableInterrupt(void)
{
	
	IEC0bits.T1IE = 0;	
	
}	

