#include "InterruptHandler.h"
#include "Timer.h"
#include <xc.h>

volatile uint16_t secCounter = 0;
volatile uint32_t milliSec = 0;
volatile uint32_t sec = 0;

void __interrupt () timer0Interrupt()
{
    if (TMR0IF == 1)
    {
        TMR0IF = 0;
        milliSec ++;
        secCounter ++;
        if (secCounter == 1000)
        {
            sec ++;
            secCounter = 0;
        }
    }
}


void InterruptInit()
{
    INTCON = 0xA0;
}
