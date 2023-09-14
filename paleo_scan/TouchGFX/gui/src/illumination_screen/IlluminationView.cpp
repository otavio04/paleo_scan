#include <gui/illumination_screen/IlluminationView.hpp>

 #include <touchgfx/Color.hpp>
#include <main.h>
#include <math.h>

#define MAX_LED 117
#define USE_BRIGHTNESS 1
#define PI 3.14159265
uint16_t pwmData[(24*MAX_LED)+50];
int datasentflag=0;

uint8_t LED_Data[MAX_LED][4];
uint8_t LED_Mod[MAX_LED][4];  // for brightness

IlluminationView::IlluminationView()
{

}

void Set_LED (int LEDnum, int Red, int Green, int Blue)
{
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = Green;
	LED_Data[LEDnum][2] = Red;
	LED_Data[LEDnum][3] = Blue;
}

void Set_Brightness (int brightness)  // 0-45
{
#if USE_BRIGHTNESS

	if (brightness > 45) brightness = 45;
	for (int i=0; i<MAX_LED; i++)
	{
		LED_Mod[i][0] = LED_Data[i][0];
		for (int j=1; j<4; j++)
		{
			float angle = 90-brightness;  // in degrees
			angle = angle*PI / 180;  // in rad
			LED_Mod[i][j] = (LED_Data[i][j])/(tan(angle));
		}
	}

#endif

}

void WS2812_Send (void)
{
	uint32_t indx=0;
	uint32_t color;


	for (int i= 0; i<MAX_LED; i++)
	{
#if USE_BRIGHTNESS
		color = ((LED_Mod[i][1]<<16) | (LED_Mod[i][2]<<8) | (LED_Mod[i][3]));
#else
		color = ((LED_Data[i][1]<<16) | (LED_Data[i][2]<<8) | (LED_Data[i][3]));
#endif

		for (int i=23; i>=0; i--)
		{
			if (color&(1<<i))
			{
				pwmData[indx] = 150;  // 2/3 of 225
			}

			else pwmData[indx] = 75;  // 1/3 of 225

			indx++;
		}

	}

	for (int i=0; i<50; i++)
	{
		pwmData[indx] = 0;
		indx++;
	}

	pwm_on(pwmData, indx);
	while (!datasentflag){};
	datasentflag = 0;
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	pwm_off();
	datasentflag=1;
}

void tur_on_led(int ratio){

	switch (ratio){
	case 1:
		for(int i = 0; i < MAX_LED; i++){
			if(i == 0){
				Set_LED(i, 0, 0, 0);
			}else{
				Set_LED(i, 255, 255, 255);
			}
		}
		break;

	case 34:
		for(int i = 0; i < MAX_LED; i++){
			if(i == 0){
				Set_LED(i, 0, 0, 0);
			}else{
				if(i%4 == 0){
					Set_LED(i, 0, 0, 0);
				}else{
					Set_LED(i, 255, 255, 255);
				}
			}
		}
		break;

	case 12:
		for(int i = 0; i < MAX_LED; i++){
			if(i%2 == 0){
				Set_LED(i, 0, 0, 0);
			}else{
				Set_LED(i, 255, 255, 255);
			}
		}
		break;

	case 14:
		for(int i = 0; i < MAX_LED; i++){
			if(i == 0){
				Set_LED(i, 0, 0, 0);
			}else{
				if((i-1)%4 == 0){
					Set_LED(i, 255, 255, 255);
				}else{
					Set_LED(i, 0, 0, 0);
				}
			}
		}
		break;

	case 0:
		for(int i = 0; i < MAX_LED; i++){
			Set_LED(i, 0, 0, 0);
		}
		break;
	}



	Set_Brightness(45);
	WS2812_Send();
}

void IlluminationView::setupScreen()
{
    IlluminationViewBase::setupScreen();
}

void IlluminationView::tearDownScreen()
{
    IlluminationViewBase::tearDownScreen();
}

void IlluminationView::i_1()
{
	tur_on_led(1);
}

void IlluminationView::i_34()
{
	tur_on_led(34);
}

void IlluminationView::i_12()
{
	tur_on_led(12);
}

void IlluminationView::i_14()
{
	tur_on_led(14);
}

void IlluminationView::i_0()
{
	tur_on_led(0);
}
