#include <gui/screen1_screen/Screen1View.hpp>
#include <stm32f4xx.h>
#include <main.h>

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

void Screen1View::Led()
{
	HAL_GPIO_TogglePin(D10_GPIO_Port, D10_Pin);
	HAL_Delay(100);
}
