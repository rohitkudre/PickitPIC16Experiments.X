/* 
 * File:   Timer.h
 * Author: rohit
 *
 * Created on May 18, 2019, 3:56 PM
 */

#ifndef TIMER_H
#define	TIMER_H
#include <stdint.h>

extern volatile uint16_t secCounter;
extern volatile uint32_t milliSec;
extern volatile uint32_t sec;

void Timer0Init(void);
void getSec(void);
void getmSec(void);

#endif	/* TIMER_H */

