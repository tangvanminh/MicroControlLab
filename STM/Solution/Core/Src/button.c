/*
 * button.c
 *
 *  Created on: Oct 14, 2022
 *      Author: MINH
 */
#include "button.h"

int button0_flag = 0;
int button1_flag = 0;
int button2_flag = 0;

int button0_press_count = 100;
int button1_press_count = 100;
int button2_press_count = 100;


int debounceButtonBuffer1[NUM_OF_BUTTONS];
int debounceButtonBuffer2[NUM_OF_BUTTONS];
int debounceButtonBuffer3[NUM_OF_BUTTONS];

int keyReg[NUM_OF_BUTTONS];

void getKeyInput(){
	// BUTTON 0: MODE BUTTON
	debounceButtonBuffer1[0] = debounceButtonBuffer2[0];
	debounceButtonBuffer2[0] = debounceButtonBuffer3[0];
	debounceButtonBuffer3[0] = HAL_GPIO_ReadPin(MODE_BUTTON_GPIO_Port,MODE_BUTTON_Pin);

	if(debounceButtonBuffer1[0]==debounceButtonBuffer2[0]
	   && debounceButtonBuffer2[0] == debounceButtonBuffer3[0]){
		if(keyReg[0]!=debounceButtonBuffer1[0]){
			keyReg[0]=debounceButtonBuffer1[0];

			if(keyReg[0] == BUTTON_PRESSED){
				button0_press_count = 100;
				button0_flag = 1;
			}
		}else{
			button0_press_count--;
			if(button0_press_count == 0){
				keyReg[0] = BUTTON_RELEASED;
			}
		}
	}

	//BUTTON 1: ADJUST BUTTON
	debounceButtonBuffer1[1] = debounceButtonBuffer2[1];
	debounceButtonBuffer2[1] = debounceButtonBuffer3[1];
	debounceButtonBuffer3[1] = HAL_GPIO_ReadPin(ADJUST_BUTTON_GPIO_Port,ADJUST_BUTTON_Pin);

	if(debounceButtonBuffer1[1]==debounceButtonBuffer2[1]
		   && debounceButtonBuffer2[1] == debounceButtonBuffer3[1]){
			if(keyReg[1]!=debounceButtonBuffer1[1]){
				keyReg[1]=debounceButtonBuffer1[1];

				if(keyReg[1] == BUTTON_PRESSED){
					button1_press_count = 100;
					button1_flag = 1;
				}
			}else{
				button1_press_count--;
				if(button1_press_count == 0){
					keyReg[1] = BUTTON_RELEASED;
				}
			}
		}


	//BUTTON 2: SET BUTTON
	debounceButtonBuffer1[2] = debounceButtonBuffer2[2];
	debounceButtonBuffer2[2] = debounceButtonBuffer3[2];
	debounceButtonBuffer3[2] = HAL_GPIO_ReadPin(SET_BUTTON_GPIO_Port,SET_BUTTON_Pin);

	if(debounceButtonBuffer1[2]==debounceButtonBuffer2[2]
		   && debounceButtonBuffer2[2] == debounceButtonBuffer3[2]){
			if(keyReg[2]!=debounceButtonBuffer1[2]){
				keyReg[2]=debounceButtonBuffer1[2];

				if(keyReg[2] == BUTTON_PRESSED){
					button2_press_count = 100;
					button2_flag = 1;
				}
			}else{
				button2_press_count--;
				if(button2_press_count == 0){
					keyReg[2] = BUTTON_RELEASED;
				}
			}
		}

}

