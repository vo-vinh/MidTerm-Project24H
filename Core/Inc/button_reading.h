/*
 * button_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_READING_H_
#define INC_BUTTON_READING_H_

#include "main.h"

#define N0_OF_BUTTONS 				       3

#define BUTTON_PORT							GPIOA
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   300


void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_3s(unsigned char index);

#endif /* INC_BUTTON_READING_H_ */
