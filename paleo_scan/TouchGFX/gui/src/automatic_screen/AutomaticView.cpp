#include <gui/automatic_screen/AutomaticView.hpp>
#include <main.h>

int n_pict_h = 10;	//cm
int n_pict_v = 5;	//cm
int n_offs_h = 5;	//cm
int n_offs_v = 5;	//cm

int offs_max_x = 80/2;
int offs_max_y = 65/2;

int max_pulses_x_a = 87446;
int max_pulses_y_a = 56196;

int pulses_cm_x_a = max_pulses_x_a / 85.35;
int pulses_cm_y_a = max_pulses_y_a / 69.75;

int convert_cm2pulses_a(int cm, char xy){
	int converted = 0;
	if(xy == 'x'){
		converted = pulses_cm_x_a * cm;
	}else{
		converted = pulses_cm_y_a * cm;
	}
	return converted;
}

void init_motors_cam_a(void){
//	motor_x
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)1);		//No pulse
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)1);  		//Back
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);			//Lock
//	motor_y
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)0);			//No pulse
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)1);  		//Back
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);		//Lock
//	camera
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)1);			//No Picture
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)1);			//No Picture

}

void motor_x_a(void){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)0);		//pulse LOW
	DWT_Delay(488);
//		delayMicroseconds(time_x);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, (GPIO_PinState)1);		//pulse HIGH
	DWT_Delay(488);
//		delayMicroseconds(time_x);

}

void motor_y_a(void){

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)1);		//pulse LOW
	DWT_Delay(1250);
//		delayMicroseconds(time_x);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (GPIO_PinState)0);		//pulse HIGH
	DWT_Delay(1250);
//		delayMicroseconds(time_x);

}

void vertex(int dx, int dy){

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)(!dx));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);				//enable
	HAL_Delay(1);
	if(dx == 0){
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)){
			motor_x_a();
		}
	}else{
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)){
			motor_x_a();
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);				//desable



	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(!dy));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
	HAL_Delay(1);
	if(dy == 0){
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)){
			motor_y_a();
		}
	}else{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)){
			motor_y_a();
		}
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable

}

void camera_a(int delay){
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)0);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (GPIO_PinState)1);
}

AutomaticView::AutomaticView()
{

}

void AutomaticView::setupScreen()
{
    AutomaticViewBase::setupScreen();
}

void AutomaticView::tearDownScreen()
{
    AutomaticViewBase::tearDownScreen();
}

void AutomaticView::btn_pict_h_p()
{
	n_pict_h += 1;

	//send number
	Unicode::snprintf(pict_hBuffer, PICT_H_SIZE, "%d", n_pict_h);
	pict_h.invalidate();
}

void AutomaticView::btn_pict_h_m()
{
	n_pict_h -= 1;
	if(n_pict_h < 2){
		n_pict_h = 2;
	}

	//send number
	Unicode::snprintf(pict_hBuffer, PICT_H_SIZE, "%d", n_pict_h);
	pict_h.invalidate();
}

void AutomaticView::btn_pict_v_p()
{
	n_pict_v += 1;

	//send number
	Unicode::snprintf(pict_vBuffer, PICT_V_SIZE, "%d", n_pict_v);
	pict_v.invalidate();
}

void AutomaticView::btn_pict_v_m()
{
	n_pict_v -= 1;
	if(n_pict_v < 2){
		n_pict_v = 2;
	}

	//send number
	Unicode::snprintf(pict_vBuffer, PICT_V_SIZE, "%d", n_pict_v);
	pict_v.invalidate();
}

void AutomaticView::btn_offs_h_p()
{
	n_offs_h += 1;
	if(n_offs_h > offs_max_x){
		n_offs_h = offs_max_x;
	}

	//send number
	Unicode::snprintf(offs_hBuffer, OFFS_H_SIZE, "%d", n_offs_h);
	offs_h.invalidate();
}

void AutomaticView::btn_offs_h_m()
{
	n_offs_h -= 1;
	if(n_offs_h < 0){
		n_offs_h = 0;
	}

	//send number
	Unicode::snprintf(offs_hBuffer, OFFS_H_SIZE, "%d", n_offs_h);
	offs_h.invalidate();
}

void AutomaticView::btn_offs_v_p()
{
	n_offs_v += 1;
	if(n_offs_v > offs_max_y){
		n_offs_v = offs_max_y;
	}

	//send number
	Unicode::snprintf(offs_vBuffer, OFFS_V_SIZE, "%d", n_offs_v);
	offs_v.invalidate();
}

void AutomaticView::btn_offs_v_m()
{
	n_offs_v -= 1;
	if(n_offs_v < 0){
		n_offs_v = 0;
	}

	//send number
	Unicode::snprintf(offs_vBuffer, OFFS_V_SIZE, "%d", n_offs_v);
	offs_v.invalidate();
}

void AutomaticView::btn_start_auto()
{

	vertex(0, 0);

	int pulses_start_x = (n_offs_h * pulses_cm_x_a);
	int pulses_start_y = (n_offs_v * pulses_cm_y_a);

	int pulses_x = (max_pulses_x_a - 2 * pulses_start_x) / (n_pict_h - 1);
	int pulses_y = (max_pulses_y_a - 2 * pulses_start_y) / (n_pict_v - 1);

	int dx = 1;
	int dy = 1;

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)(!dx));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);				//enable
	for(int i = 0; i < pulses_start_x; i++){
	  motor_x_a();
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);				//desable


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(!dy));  		//direction
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
	for(int j = 0; j < pulses_start_y; j++){
	  motor_y_a();
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable


	for(int j = 0; j < n_pict_v; j++){
	  for(int i = 0; i < n_pict_h; i++){

		camera_a(1000);
		if(i < n_pict_h - 1){
		  int count = 0;

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (GPIO_PinState)(!dx));  		//direction
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)1);				//enable
		  HAL_Delay(1);
		  if(dx == 0){
			  while(count < pulses_x && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)){
				count++;
				motor_x_a();
			  }
		  }else{
			  while(count < pulses_x && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)){
				count++;
				motor_x_a();
			  }
		  }
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)0);				//desable

		}
	  }
	  dx = !dx;

	  if(j < n_pict_v - 1){
		int count = 0;

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(!dy));  		//direction
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)1);			//enable
		HAL_Delay(1);
		if(dy == 0){
		  while(count < pulses_y && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)){
			count++;
			motor_y_a();
		  }
		}else{
		  while(count < pulses_y && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)){
			count++;
			motor_y_a();
		  }
		}
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)0);			//desable

	  }
	}

	vertex(0, 0);
	for(int i = 0; i < 5; i++){
		buzzer(500);
		HAL_Delay(500);
	}
}

void AutomaticView::init_pict()
{
	swipeContainer1.setTouchable(false);

	init_motors_cam_a();

	vertex(0, 0); //return to origin

	Unicode::snprintf(pict_hBuffer, OFFS_H_SIZE, "%d", n_pict_h);
	pict_h.invalidate();

	Unicode::snprintf(pict_vBuffer, PICT_V_SIZE, "%d", n_pict_v);
	pict_v.invalidate();

	Unicode::snprintf(offs_hBuffer, OFFS_H_SIZE, "%d", n_offs_h);
	offs_h.invalidate();

	Unicode::snprintf(offs_vBuffer, OFFS_V_SIZE, "%d", n_offs_v);
	offs_v.invalidate();

	swipeContainer1.setSelectedPage(1);

}
