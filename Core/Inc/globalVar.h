/*
 * globalVar.h
 *
 *  Created on: 5 thg 11, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBALVAR_H_
#define INC_GLOBALVAR_H_

#include "main.h"

#define RESET_BUTTON  	0
#define INC_BUTTON		1
#define DEC_BUTTON		2

#define TIMEOUT_FOR_BUTTON		10000   //10s
#define TIME_INVOKE_FSM			10		//10ms

extern int saveBuffer;
extern int number;

extern int Increase_MODE_1;
extern int Decrease_MODE_1;

extern int Decrease_MODE_2;

#endif /* INC_GLOBALVAR_H_ */
