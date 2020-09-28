#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
/*============================================================================*/

void TimerInit(void);
void TimerStart(uint8_t onOff);
uint8_t TimerWaitMS(uint8_t timeMs);

/*============================================================================*/
#endif /*TIMER_H*/