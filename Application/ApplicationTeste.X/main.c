/* 
 * File:   main.c
 * Author: Natan
 *
 * Created on September 28, 2020, 6:52 PM
 */
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
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Coretimer.h"

#define Led_B0_Test                 LATBbits.LATB0
#define Led_B1_Test                 LATBbits.LATB1
#define Led_B2_Test                 LATBbits.LATB2


#define InitTestLed()       do{                                                \
							TRISBbits.TRISB0 = 0;                              \
							LATBbits.LATB0 = 0;                                \
                            TRISBbits.TRISB1 = 0;                              \
							LATBbits.LATB1 = 0;                                \
                            TRISBbits.TRISB2 = 0;                              \
							LATBbits.LATB2 = 0;                                \
						}while(0)

#define BlinkLedB0() do{                                                               \
                             Led_B0_Test = ((CoreTimer_CountGet() & 0x00800000) != 0);\
                            }while(0)

#define BlinkLedB1() do{                                                               \
                             Led_B1_Test = ((CoreTimer_CountGet() & 0x00400000)== 0);\
                            }while(0)
#define BlinkLedB2() do{                                                               \
                             Led_B2_Test = ((CoreTimer_CountGet() & 0x00800000) != 0);\
                            }while(0)

/*
 * 
 */
int main(int argc, char** argv) {
    
    InitTestLed();
    while(1)
    {
        BlinkLedB0();
        BlinkLedB1();
        BlinkLedB2();
        
    }
    return (EXIT_SUCCESS);
}

