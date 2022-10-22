/*
 * fsm_normal.c
 *
 *  Created on: Oct 14, 2022
 *      Author: MINH
 */
#include "fsm_normal.h"

int deletion_count = 0;

void fsm_normal_run(){
	switch (status){
	case INIT:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);

		status = RUNNING_RED;
		setTimer0_ms(red_count*1000);
		setTimer1_ms(1000);
		break;
	case RUNNING_RED:
		if(timer1_flag == 1) {
			setTimer1_ms(1000);
			deletion_count ++;
		}
		updateFirstCouple7SEGBuffer(red_count-deletion_count);
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

		if(deletion_count <= green_count){
			updateSecondCouple7SEGBuffer(green_count - deletion_count);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);

		}else if(deletion_count <= green_count + yellow_count){
			updateSecondCouple7SEGBuffer(green_count + yellow_count - deletion_count);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
		}else {
			updateSecondCouple7SEGBuffer(green_count + yellow_count + red_count - deletion_count);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		}

		if(button0_flag == 1){
			button0_flag = 0;
			deletion_count = 0;
			setTimer1_ms(500);
			status = ADJUST_RED;
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		}

		if(timer0_flag == 1){
			status = RUNNING_GREEN;
			deletion_count = 0;
			setTimer1_ms(1000);
			setTimer0_ms(green_count *1000);
		}
		break;
	case RUNNING_GREEN:

		if(timer1_flag == 1) {
			setTimer1_ms(1000);
			deletion_count ++;
		}
		update7SEGBuffer(green_count-deletion_count, green_count+yellow_count-deletion_count);
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);


		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);


		if(button0_flag == 1){
			button0_flag = 0;
			deletion_count = 0;
			setTimer1_ms(250);
			status = ADJUST_RED;
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		}

		if(timer0_flag == 1){
			status = RUNNING_YELLOW;
			deletion_count = 0;
			setTimer1_ms(1000);
			setTimer0_ms(yellow_count *1000);
		}
		break;
	case RUNNING_YELLOW:

		if(timer1_flag == 1) {
			setTimer1_ms(1000);
			deletion_count ++;
		}

		update7SEGBuffer(yellow_count-deletion_count, yellow_count-deletion_count);

		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);

		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);



		if(button0_flag == 1){
			button0_flag = 0;
			deletion_count = 0;
			setTimer1_ms(500);
			status = ADJUST_RED;
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		}

		if(timer0_flag == 1){
			status = RUNNING_RED;
			deletion_count = 0;
			setTimer1_ms(1000);
			setTimer0_ms(red_count *1000);
		}
		break;
	default:
		break;
	}
}

