/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH
 */
#include "software_timer.h"

int timer0_flag = 0;
int timer1_flag = 0;
int timer2_flag = 0;

int timer0_counter = 0;
int timer1_counter = 0;
int timer2_counter = 0;

void set_timer0_ms(int num){
	timer0_flag = 0;
	timer0_counter = num/INTERRUPT_CYCLE;
}

void set_timer1_ms(int num){
	timer1_flag = 0;
	timer1_counter = num/INTERRUPT_CYCLE;
}

void set_timer2_ms(int num){
	timer2_flag = 0;
	timer2_counter = num/INTERRUPT_CYCLE;
}

void timer_run(){
	timer0_counter--;
	timer1_counter--;
	timer2_counter--;

	if(timer0_counter == 0){
		timer0_flag = 1;
	}

	if(timer1_counter == 0){
		timer1_flag = 1;
	}

	if(timer2_counter == 0){
		timer2_flag = 1;
	}

}
