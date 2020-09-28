#include "../Include/Coretimer.h"
#include "../Include/GenericTypeDefs.h"
#include "../Include/HardwareProfile/HardwareProfile.h"

#include <stdbool.h>
#include <xc.h>

/*============================================================================*/
#define COUNT_PER_MICROSEC          (CORETIMER_FREQ/1000000UL)

uint32_t CoreTimer_CountGet(void)
{
    return _CP0_GET_COUNT();
}

void CoreTimer_CountSet(uint32_t val)
{
   _CP0_SET_COUNT(val);
}

void CoreTimer_DelayUs(uint32_t us)
{
    uint32_t targetCount;
    uint32_t bakupCount;
    
    // Assert "us" not zero. This must be caught during debug phase.
    ASSERT(us!=0);
    // backup current count of the core timer.
    bakupCount = CoreTimer_CountGet();
    // Core timer increments every 2 sys clock cycles.
    // Calculate the counts required to complete "us".
    targetCount = COUNT_PER_MICROSEC * us;
    // Restart core timer.
    CoreTimer_CountSet(0);
    // Wait till core timer completes the count.
    while(CoreTimer_CountGet() < targetCount);

    // Restore count back.
    CoreTimer_CountSet(bakupCount + targetCount);
}