/*
 * display.h
 *
 *  Created on: Oct 14, 2022
 *      Author: MINH
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "global.h"

void update7SEGBuffer(int num1, int num2);
void updateFirstCouple7SEGBuffer(int num1);
void updateSecondCouple7SEGBuffer(int num2);
void display7SEG();
void update7SEG(int num);
void assignPin7SEG(int num);

#endif /* INC_DISPLAY_H_ */
