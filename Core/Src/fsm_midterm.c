/*
 * fsm_midterm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "fsm_midterm.h"

#include "globalVar.h"

enum MODE {MODE0, MODE1, MODE2};

enum MODE mode = MODE0;

//timeout for button is 10s, while time invoking fsm is 10ms
// so we create a counter

uint16_t Time_counter	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;

void MODE_0_manual(){
	if(is_button_pressed(RESET_BUTTON)){
		Time_counter	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		number = 0;
	}
	else if(is_button_pressed(INC_BUTTON)){
		Time_counter	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		if (number + 1 > 9) {
			number = 0;
		}
		else {
			number = number + 1;
		}
	}
	else if(is_button_pressed(DEC_BUTTON)){
		Time_counter	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		if (number - 1 < 0) {
			number = 9;
		}
		else {
			number = number - 1;
		}
	}
}
void fsm_simple_buttons_run(){
	switch(mode){
	case MODE0:
		MODE_0_manual();
		if(is_button_pressed_3s(INC_BUTTON) || is_button_pressed_3s(DEC_BUTTON)){
			mode = MODE1;
		}
		if(Time_counter == 0){
			saveBuffer = number;
			mode = MODE2;
		}
		Time_counter--;
		break;
	case MODE1:
		if(is_button_pressed_3s(INC_BUTTON)) {
			Increase_MODE_1 = 1;
		}
		else if(is_button_pressed_3s(DEC_BUTTON)){
			Decrease_MODE_1 = 1;
		}
		else {
			Increase_MODE_1 = 0;
			Decrease_MODE_1 = 0;
			mode = MODE0;
		}
		break;
	case MODE2:
		Decrease_MODE_2 = 1;
		if(is_button_pressed(INC_BUTTON) || is_button_pressed(DEC_BUTTON)){
			Decrease_MODE_2 = 0;
			number = saveBuffer;
			mode = MODE0;
		}
		break;
	default:
		break;
	}
}
