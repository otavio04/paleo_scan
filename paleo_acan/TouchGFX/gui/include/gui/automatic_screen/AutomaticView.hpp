#ifndef AUTOMATICVIEW_HPP
#define AUTOMATICVIEW_HPP

#include <gui_generated/automatic_screen/AutomaticViewBase.hpp>
#include <gui/automatic_screen/AutomaticPresenter.hpp>

class AutomaticView : public AutomaticViewBase
{
public:
    AutomaticView();
    virtual ~AutomaticView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // AUTOMATICVIEW_HPP
