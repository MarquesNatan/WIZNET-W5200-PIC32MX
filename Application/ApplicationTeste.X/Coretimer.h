#ifndef CORE_TIMER_H
#define CORE_TIMER_H

#include <stdint.h>
#define SYS_FREQ (80000000L)
#define CORETIMER_FREQ (SYS_FREQ/2)

uint32_t CoreTimer_CounterGet();
void CoreTimer_CountSet(uint32_t val);
void CoreTimer_DelayUs(uint32_t us);

#endif /* CORE_TIMER_H */