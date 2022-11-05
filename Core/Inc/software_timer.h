/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "button_reading.h"

extern int timer1_flag;
extern int timer2_flag;

void SetTimer_0(uint16_t duration);
void SetTimer_1(uint16_t duration);

void RunSoftwareTimer(void);

uint8_t FlagTimer_0(void); //return timer1 flag
uint8_t FlagTimer_1(void); //return timer2 flag

#endif /* INC_SOFTWARE_TIMER_H_ */
