#include "PortInit.h"
#include <xc.h>

void portInit()
{
    TRISA = 0x00;
    TRISC = 0x00; // Set RC2 as output
    TRISB = 0x00;
}