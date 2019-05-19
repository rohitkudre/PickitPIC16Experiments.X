/* 
 * File:   LEDApplication.h
 * Author: rohit
 *
 * Created on May 18, 2019, 3:46 PM
 */

#ifndef LEDAPPLICATION_H
#define	LEDAPPLICATION_H

#include <stdint.h>
#include <xc.h>

#define LED_ON_TIME 2000
#define LED_OFF_TIME 2000

typedef enum LEDStates
{
    LED_ON = 0,
    LED_OFF,
    LED_WAIT
} LEDStates;

typedef struct LEDData
{
    LEDStates LEDCurrentState;
    uint32_t LEDOnTime;
    uint32_t LEDOffTime;
} LEDData;

void LEDProcess(void);
void LEDinit(void);

LEDData ledData;
#endif	/* LEDAPPLICATION_H */

