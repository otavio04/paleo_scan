#ifndef CALIBRATIONVIEW_HPP
#define CALIBRATIONVIEW_HPP

#include <gui_generated/calibration_screen/CalibrationViewBase.hpp>
#include <gui/calibration_screen/CalibrationPresenter.hpp>

class CalibrationView : public CalibrationViewBase
{
public:
    CalibrationView();
    virtual ~CalibrationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void center_c();
    virtual void pict_c();
    virtual void start_c();
    virtual void plus_c();
    virtual void minus_c();
    virtual void init_c();
protected:
};

#endif // CALIBRATIONVIEW_HPP
