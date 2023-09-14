#include <gui/manual_screen/ManualView.hpp>
#include <main.h>

int max_pulses_x = 87446;
int max_pulses_y = 56196;

int pulses_cm_x = max_pulses_x / 85.35;
int pulses_cm_y = max_pulses_y / 69.75;

int value_dist_m = 10;

int convert_cm2pulses(int cm, char xy){
	int converted = 0;
	if(xy == 'x'){
		converted = pulses_cm_x * cm;
	}else{
		converted = pulses_cm_y * cm;
	}
	return converted;
}

void init_motors_cam(void){
//	motor_x
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)1);		//No pulse
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)1);  		//Back
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);			//Lock
//	motor_y
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)0);			//No pulse
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)1);  		//Back
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);		//Lock
//	camera
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)1);

}

void motor_x(void){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)0);		//pulse LOW
	DWT_Delay(488);
//		delayMicroseconds(time_x);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)1);		//pulse HIGH
	DWT_Delay(488);
//		delayMicroseconds(time_x);

}

void motor_y(void){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)1);		//pulse LOW
	DWT_Delay(1250);
//		delayMicroseconds(time_x);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)0);		//pulse HIGH
	DWT_Delay(1250);
//		delayMicroseconds(time_x);

}

void camera(int delay){
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)0);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)1);
}


ManualView::ManualView()
{

}

void ManualView::setupScreen()
{
    ManualViewBase::setupScreen();
}

void ManualView::tearDownScreen()
{
    ManualViewBase::tearDownScreen();
}


void ManualView::dist_up()
{
	value_dist_m += 1;

	//send number
	Unicode::snprintf(txt_distBuffer, TXT_DIST_SIZE, "%d", value_dist_m);
	txt_dist.invalidate();
}

void ManualView::dist_down()
{
	value_dist_m -= 1;
	if(value_dist_m < 0){
		value_dist_m = 0;
	}

	//send number
	Unicode::snprintf(txt_distBuffer, TXT_DIST_SIZE, "%d", value_dist_m);
	txt_dist.invalidate();
}

void ManualView::move_up()
{

	int pulses = pulses_cm_y * value_dist_m;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)0);  			//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	for(int i = 0; i < pulses; i++){
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)){
			motor_y();
		}else{
			break;
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable

}

void ManualView::move_left()
{

	int pulses = pulses_cm_x * value_dist_m;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)0);  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	for(int i = 0; i < pulses; i++){
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)){
			motor_x();
		}else{
			break;
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);			//desable

}

void ManualView::move_down()
{

	int pulses = pulses_cm_y * value_dist_m;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)1);  			//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	for(int i = 0; i < pulses; i++){
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)){
			motor_y();
		}else{
			break;
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable

}

void ManualView::move_right()
{

	int pulses = pulses_cm_x * value_dist_m;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)1);  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	for(int i = 0; i < pulses; i++){
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)){
			motor_x();
		}else{
			break;
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);			//desable

}

void ManualView::picture_m()
{

	camera(1000);

}

void ManualView::init_m()
{

	init_motors_cam();
	//send number
	Unicode::snprintf(txt_distBuffer, TXT_DIST_SIZE, "%d", value_dist_m);
	txt_dist.invalidate();

}
