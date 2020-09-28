/*********************************************************************
 *
 *	Hardware specific definitions for:
 *    - PIC32 USB Starter Kit II
 *    - PIC32MX795F512L
 *    - Ethernet PICtail Plus (ENC28J60)
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    Compiler.h
 * Processor:       PIC32
 * Compiler:        Microchip C32 v1.11 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2010 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder		09/16/2010	Regenerated for specific boards
 ********************************************************************/
#ifndef __HARDWARE_PROFILE_PIC32MX_
#define __HARDWARE_PROFILE_PIC32MX_

#include <xc.h>


// Specify which SPI to use for the ENC28J60 or ENC624J600.  SPI1 is 
// the topmost slot with pin 1 on it.  SPI2 is the middle slot 
// starting on pin 33.
#define ENC_IN_SPI1
//#define ENC_IN_SPI2

#if defined(DEMO_BOARD_USB_STARTER_KIT)
	#if defined(ENC_IN_SPI1)
		#error "SPI1 is not supported for PIC32 USB Starter Kit. Enable macro ENC_IN_SPI2"
	#endif
#endif

#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)))
		#error("TODO: For PIC32MX1xx/PIC32MX2xx devices, user has to take care of mapping the ports to required pins using PPS");
#endif

// Defines macros for the I / O pins  -> SPI Register
    #define WIZ_CS_TRIS			(TRISBbits.TRISB12)
	#define WIZ_CS_IO			(LATBbits.LATB12)
	#define WIZ_RST_TRIS		(TRISGbits.TRISG12)
	#define WIZ_RST_IO			(LATGbits.LATG12)

	// SPI SCK, SDI, SDO pins are automatically controlled by the 
	#define WIZ_SPI_IF			(IFS0bits.SPI3RXIF)
	#define WIZ_SSPBUF			(SPI3BUF)
	#define WIZ_SPICON			(SPI3CON)
	#define WIZ_SPICONbits		(SPI3CONbits)
	#define WIZ_SPIBRG			(SPI3BRG)
	#define WIZ_SPISTATbits		(SPI3STATbits)

    #define WIZ_SPI_IE1bits     (IEC0bits.SPI3RXIE)
    #define WIZ_SPI_TX1bits     (IEC0bits.SPI3TXIE)
    #define WIZ_SPI_RX1bits     (IEC0bits.SPI3EIE)

// Defines macros (functions) for the indication LEDs
#define ReadSwitchStatus()  (1)

#define rLED            LATBbits.LATB2
#define yLED            LATBbits.LATB1

#define InitHeartbeatLED()       do{                                           \
							TRISBbits.TRISB2 = 0;                              \
							LATBbits.LATB2 = 0;                                \
						}while(0)
#define InitProgrammingModeLED()       do{                                     \
                                            TRISBbits.TRISB1 = 0;              \
                                            LATBbits.LATB1 = 0;                \
                                        }while(0)

#define BlinkHeartbeatLED() do{                                                \
                             rLED = ((CoreTimer_CountGet() & 0x00800000) != 0);\
                            }while(0)
#define BlinkProgrammingModeLED() do{                                          \
                                   yLED = ((CoreTimer_CountGet() & 0x00800000) == 0);\
                                  }while(0)


#endif /* __HARDWARE_PROFILE_PIC32MX_ */