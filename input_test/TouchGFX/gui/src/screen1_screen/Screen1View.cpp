#include <gui/screen1_screen/Screen1View.hpp>
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

void Screen1View::verify()
{
	GPIO_PinState input_pin = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", (int)input_pin);
	textArea1.invalidate();

}
