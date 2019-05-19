#include "PortInit.h"
#include <xc.h>

void portInit()
{
    TRISA = 0x00;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC4 = 0;
    TRISB = 0x00;
}