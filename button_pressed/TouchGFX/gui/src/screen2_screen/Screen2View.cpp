#include <gui/screen2_screen/Screen2View.hpp>
#include <main.h>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::init()
{
	button1.setTouchable(true);
    for(int i = 0; i < 20; i++){
    	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", i);
    	textArea1.invalidate();
    	HAL_Delay(1000);
    }
}
