#ifndef ILLUMINATIONVIEW_HPP
#define ILLUMINATIONVIEW_HPP

#include <gui_generated/illumination_screen/IlluminationViewBase.hpp>
#include <gui/illumination_screen/IlluminationPresenter.hpp>

class IlluminationView : public IlluminationViewBase
{
public:
    IlluminationView();
    virtual ~IlluminationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void i_1();
    virtual void i_34();
    virtual void i_12();
    virtual void i_14();
    virtual void i_0();
protected:
};

#endif // ILLUMINATIONVIEW_HPP
