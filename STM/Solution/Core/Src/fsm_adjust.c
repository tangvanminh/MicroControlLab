/*
 * fsm_adjust.c
 *
 *  Created on: Oct 14, 2022
 *      Author: MINH
 */
#include "fsm_adjust.h"

void fsm_adjust_run(){
	switch (status){
	case ADJUST_RED:
		//todo
		update7SEGBuffer(2, increasing_num);

		if(timer1_flag==1){
			setTimer1_ms(250);
			HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_RED2_Pin);
		}

		if(button0_flag == 1){
			button0_flag = 0;
			increasing_num = 1;
			status = ADJUST_GREEN;
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		}

		if(button1_flag == 1){
			button1_flag = 0;
			increasing_num++;
			if(increasing_num == 100){
				increasing_num = 1;
			}
		}

		if(button2_flag == 1){
			button2_flag = 0;
			red_count = increasing_num;
		}
		break;
	case ADJUST_GREEN:
		//todo

		update7SEGBuffer(3, increasing_num);

		if(timer1_flag==1){
			setTimer1_ms(250);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN2_Pin);
		}

		if(button0_flag == 1){
			button0_flag = 0;
			increasing_num = 1;
			status = ADJUST_YELLOW;
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			increasing_num++;
			if(increasing_num == 100){
				increasing_num = 1;
			}
		}

		if(button2_flag == 1){
			button2_flag = 0;
			green_count = increasing_num;
		}
		break;
	case ADJUST_YELLOW:
		//todo
		update7SEGBuffer(4, increasing_num);

		if(timer1_flag==1){
			setTimer1_ms(250);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW2_Pin);
		}

		if(button0_flag == 1){
			button0_flag = 0;
			increasing_num = 1;
			status = RUNNING_RED;
			setTimer0_ms(red_count*1000);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			increasing_num++;
			if(increasing_num == 100){
				increasing_num = 1;
			}
		}

		if(button2_flag == 1){
			button2_flag = 0;
			yellow_count = increasing_num;
		}
		break;
	default:
		break;
	}
}

