#include <gui/calibration_screen/CalibrationView.hpp>
#include <main.h>

int num_pic = 15;

int max_pulses_x_c = 87446;
int max_pulses_y_c = 56196;

void motor_x_c(void){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)0);		//pulse LOW
	DWT_Delay(488);
//		delayMicroseconds(time_x);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)1);		//pulse HIGH
	DWT_Delay(488);
//		delayMicroseconds(time_x);

}

void motor_y_c(void){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)1);		//pulse LOW
	DWT_Delay(1250);
//		delayMicroseconds(time_x);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)0);		//pulse HIGH
	DWT_Delay(1250);
//		delayMicroseconds(time_x);

}

void camera_c(int delay){
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)0);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)1);
}

void vertex_c(int dx, int dy){

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)(!dx));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);				//enable
	HAL_Delay(1);
	if(dx == 0){
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)){
			motor_x_c();
		}
	}else{
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)){
			motor_x_c();
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);				//desable



	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(!dy));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	if(dy == 0){
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)){
			motor_y_c();
		}
	}else{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)){
			motor_y_c();
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable

}

void go_center(){

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)(0));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);				//enable
	HAL_Delay(1);
	int count = 0;
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) && count < (int)(max_pulses_x_c / 2)){
		count++;
		motor_x_c();
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);				//desable



	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(0));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	count = 0;
	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) && count < (int)(max_pulses_y_c / 2)){
		count++;
		motor_y_c();
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable

}

void pict_delayed(int delay_c, int n_pict){

	for(int i = 0; i < n_pict; i++){
		for(int j = 0; j < delay_c; j++){
			buzzer(500);
			HAL_Delay(500);
		}
		camera_c(500);
	}
}

CalibrationView::CalibrationView()
{

}

void CalibrationView::setupScreen()
{
    CalibrationViewBase::setupScreen();
}

void CalibrationView::tearDownScreen()
{
    CalibrationViewBase::tearDownScreen();
}

void CalibrationView::init_c(){
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", num_pic);
	textArea2.invalidate();
}

void CalibrationView::plus_c(){
	num_pic += 1;

	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", num_pic);
	textArea2.invalidate();
}

void CalibrationView::minus_c(){
	num_pic -= 1;
	if(num_pic < 1){
		num_pic = 1;
	}

	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", num_pic);
	textArea2.invalidate();
}

void CalibrationView::center_c()
{
	vertex_c(0, 0);
	go_center();
}

void CalibrationView::pict_c()
{
	camera_c(500);
}

void CalibrationView::start_c()
{
	vertex_c(0, 0);
	go_center();
	pict_delayed(5, num_pic); //(delay sec, number pict)
	vertex_c(0, 0);
}
