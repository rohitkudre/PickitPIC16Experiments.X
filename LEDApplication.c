#include "LEDApplication.h"
#include "PinDefs.h"
#include "Timer.h"

void LEDProcess()
{
    
    switch(ledData.LEDCurrentState)
    {
        case LED_OFF:
            LED = 0;
            ledData.LEDOffTime = milliSec;
            ledData.LEDCurrentState = LED_WAIT;
            break;
            
        case LED_ON:
            LED = 1;
            ledData.LEDOnTime = milliSec;
            ledData.LEDCurrentState = LED_WAIT;
            break;
            
        case LED_WAIT:
            if (ledData.LEDOnTime > 0)
            {
                if (milliSec - ledData.LEDOnTime >= LED_ON_TIME)
                {
                    ledData.LEDOnTime = 0;
                    ledData.LEDCurrentState = LED_OFF;
                }
            } 
            
            else if (ledData.LEDOffTime > 0)
            {
                if (milliSec - ledData.LEDOffTime >= LED_OFF_TIME)
                {
                    ledData.LEDOffTime = 0;
                    ledData.LEDCurrentState = LED_ON;
                }
            }
            else 
            {
                ledData.LEDCurrentState = LED_ON;
            }
            
            break;
    }
}

void LEDinit()
{
    LED = 1;
    ledData.LEDCurrentState = LED_ON;
    ledData.LEDOnTime = 0;
    ledData.LEDOffTime = 0;
}