/*
 * display.c
 *
 *  Created on: Oct 14, 2022
 *      Author: MINH
 */
#include "display.h"
int display_led_num = 3;

void update7SEGBuffer(int num1, int num2){
	led7segBuffer[0] = num1/10;
	led7segBuffer[1] = num1%10;
	led7segBuffer[2] = num2/10;
	led7segBuffer[3] = num2%10;
}
void updateFirstCouple7SEGBuffer(int num1){
	led7segBuffer[0] = num1/10;
	led7segBuffer[1] = num1%10;
}
void updateSecondCouple7SEGBuffer(int num2){
	led7segBuffer[2] = num2/10;
	led7segBuffer[3] = num2%10;
}
void display7SEG(){
	if(timer2_flag == 1){
		setTimer2_ms(250);
		display_led_num = (display_led_num+1)%4;
		update7SEG(display_led_num);
	}
}

void update7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, EN1_Pin|EN2_Pin|EN3_Pin|EN4_Pin, SET);
		assignPin7SEG(led7segBuffer[0]);
		HAL_GPIO_WritePin(GPIOB, EN1_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, EN1_Pin|EN2_Pin|EN3_Pin|EN4_Pin, SET);
		assignPin7SEG(led7segBuffer[1]);
		HAL_GPIO_WritePin(GPIOB, EN2_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, EN1_Pin|EN2_Pin|EN3_Pin|EN4_Pin, SET);
		assignPin7SEG(led7segBuffer[2]);
		HAL_GPIO_WritePin(GPIOB, EN3_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, EN1_Pin|EN2_Pin|EN3_Pin|EN4_Pin, SET);
		assignPin7SEG(led7segBuffer[3]);
		HAL_GPIO_WritePin(GPIOB, EN4_Pin, RESET);
		break;
	default:
		break;
	}
}

void assignPin7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
		break;
	default:
		break;
	}
}
