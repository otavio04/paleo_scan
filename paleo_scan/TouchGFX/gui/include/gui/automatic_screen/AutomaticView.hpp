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
    virtual void btn_pict_h_p();
    virtual void btn_pict_h_m();
    virtual void btn_pict_v_p();
    virtual void btn_pict_v_m();
    virtual void btn_offs_h_p();
    virtual void btn_offs_h_m();
    virtual void btn_offs_v_p();
    virtual void btn_offs_v_m();
    virtual void btn_start_auto();
    virtual void init_pict();
protected:
};

#endif // AUTOMATICVIEW_HPP
