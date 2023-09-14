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

void Screen1View::f_start()
{
    f_start1();
}

void Screen1View::f_minus()
{
    f_minus1();
}

void Screen1View::f_plus()
{
    f_plus1();
}
