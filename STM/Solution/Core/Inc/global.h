/*
 * global.h
 *
 *  Created on: Oct 14, 2022
 *      Author: MINH
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "softwaretimer.h"
#include "display.h"

#define INIT			0
#define RUNNING_RED 	1
#define RUNNING_YELLOW	2
#define RUNNING_GREEN	3

#define ADJUST_RED		11
#define	ADJUST_YELLOW	12
#define	ADJUST_GREEN	13

extern int status;
extern int led7segBuffer[4];
extern int red_count;
extern int yellow_count;
extern int green_count;

extern int increasing_num;

#endif /* INC_GLOBAL_H_ */
