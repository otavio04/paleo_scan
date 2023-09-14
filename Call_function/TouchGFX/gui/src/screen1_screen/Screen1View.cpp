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

void Screen1View::function1()
{
	f();
	//HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

