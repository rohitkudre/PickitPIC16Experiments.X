#include "Timer.h"
#include <xc.h>

void Timer0Init()
{
    OPTION_REG = 0x42; // Prescale of 1:8, Increment on low-to-high, internal clock
                      // Interrupt on rising edge, disable weak pull ups.
}
