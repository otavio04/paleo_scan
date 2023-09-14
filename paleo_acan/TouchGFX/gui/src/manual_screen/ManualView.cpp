#include <gui/manual_screen/ManualView.hpp>
#include "stm32f4xx_hal.h"

ManualView::ManualView()
{

}

void motor(int dir){

	if(dir == 1){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);	//dir
	}else{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);	//dir
	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); 		//ena unlock

	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, GPIO_PIN_RESET); 		//Pulse LOW
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, GPIO_PIN_SET); 		//Pulse HIGH
	HAL_Delay(1);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); 		//ena lock
}

void rodar(){

	for(int i = 0; i < 1000; i++){
		motor(0);
	}
}

void ManualView::setupScreen()
{
    ManualViewBase::setupScreen();
}

void ManualView::tearDownScreen()
{
    ManualViewBase::tearDownScreen();
}

void ManualView::capture()
{
	rodar();
}


