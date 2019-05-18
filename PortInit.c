#include "PortInit.h"
#include <xc.h>

void portInit()
{
    TRISCbits.TRISC2 = 0; // Set RC2 as output
}