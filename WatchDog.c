#include "WatchDog.h"
#include <xc.h>

void watchDogInit()
{
    WDTCON = 0x19;
}
