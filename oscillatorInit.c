#include "OscillatorSetup.h"
#include <xc.h>

void oscillatorInit() 
{
    OSCCON = 0x72; // Frequency 8 MHz with 4xPLL disabled
}
