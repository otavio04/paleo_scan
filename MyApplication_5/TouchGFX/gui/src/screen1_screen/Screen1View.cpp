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

void Screen1View::mais()
{
	counter = f(counter);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%u", counter);
    textArea1.invalidate();
}

void Screen1View::menos()
{
    counter--;
    if(counter < 0){
    	counter = 0;
    }
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%u", counter);
    textArea1.invalidate();
}
