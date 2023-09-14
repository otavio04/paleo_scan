#ifndef MANUALVIEW_HPP
#define MANUALVIEW_HPP

#include <gui_generated/manual_screen/ManualViewBase.hpp>
#include <gui/manual_screen/ManualPresenter.hpp>

class ManualView : public ManualViewBase
{
public:
    ManualView();
    virtual ~ManualView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void dist_up();
    virtual void dist_down();
    virtual void move_up();
    virtual void move_left();
    virtual void move_down();
    virtual void move_right();
    virtual void picture_m();
    virtual void init_m();
protected:
};

#endif // MANUALVIEW_HPP
