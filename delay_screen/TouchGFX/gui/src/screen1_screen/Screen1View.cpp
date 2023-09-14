#include <gui/screen1_screen/Screen1View.hpp>
#include <main.h>
#include <stm32f4xx_hal_tim.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx.h>


Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::f()
{
	int count = 0;
    while(count < 10){
    	count++;
    	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
    	DWT_Delay(1000000);
    	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
    	DWT_Delay(1000000);
    }
}
