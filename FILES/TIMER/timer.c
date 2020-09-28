#include "timer.h"
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
/*============================================================================*/
#define PIC32MX795F512L
#if defined PIC32MM0256GPM064
#include <proc/p32mm0256gpm064.h>
void TimerInit(void)
{
    PR1 = 0x1F3F;
    T1CON = 0x8000;
    T1CONbits.ON = 0x00;
}

void TimerStart(uint8_t onOff)
{
    if((onOff == 0x01) || (onOff == 0x00))
    {
        T1CONbits.ON = onOff;
    }
}

uint8_t TimerWaitMS(uint8_t timeMs)
{
    uint8_t timeCount = 0;
    TMR1 = 0x00;
    TimerStart(1);
    TRISCbits.TRISC3 = 0x00;
    LATCbits.LATC3 = 0x01;
    do
    {
        if(IFS0bits.T1IF == 0x01)
        {
            if(timeCount == timeMs)
            {
                TimerStart(0);
                return;
            }
            else
            {
                timeCount++;
            }
            
            IFS0bits.T1IF = 0x00;
        }
    }while(timeCount != timeMs);
    LATCbits.LATC3 = 0x00;
}
#elif defined PIC32MX795F512L

void TimerInit(void)
{
    T1CON = 0x8000;
    T1CONbits.ON = 0x00;
}

void TimerStart(uint8_t onOff)
{
    if((onOff == 0x01) || (onOff == 0x00))
    {
        T1CONbits.ON = onOff;
    }
}

uint8_t TimerWaitMS(uint8_t timeMs)
{
    uint8_t timeCount = 0;
    TMR1 = 0x00;
    TimerStart(1);
    TRISCbits.TRISC3 = 0x00;
    LATCbits.LATC3 = 0x01;
    do
    {
        if(IFS0bits.T1IF == 0x01)
        {
            if(timeCount == timeMs)
            {
                TimerStart(0);
                return;
            }
            else
            {
                timeCount++;
            }
            
            IFS0bits.T1IF = 0x00;
        }
    }while(timeCount != timeMs);
    LATCbits.LATC3 = 0x00;
}


#endif
/*PIC32MM0256GPM064*/ 


