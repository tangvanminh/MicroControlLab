/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define INTERRUPT_CYCLE		10

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;

void set_timer0_ms(int num);
void set_timer1_ms(int num);
void set_timer2_ms(int num);

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
