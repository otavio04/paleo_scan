/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MANUALVIEWBASE_HPP
#define MANUALVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/manual_screen/ManualPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class ManualViewBase : public touchgfx::View<ManualPresenter>
{
public:
    ManualViewBase();
    virtual ~ManualViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void dist_up()
    {
        // Override and implement this function in Manual
    }

    virtual void dist_down()
    {
        // Override and implement this function in Manual
    }

    virtual void move_up()
    {
        // Override and implement this function in Manual
    }

    virtual void move_left()
    {
        // Override and implement this function in Manual
    }

    virtual void move_down()
    {
        // Override and implement this function in Manual
    }

    virtual void move_right()
    {
        // Override and implement this function in Manual
    }

    virtual void picture_m()
    {
        // Override and implement this function in Manual
    }

    virtual void init_m()
    {
        // Override and implement this function in Manual
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Container container4;
    touchgfx::Box box1;
    touchgfx::ButtonWithIcon btn_return_m;
    touchgfx::Container container1;
    touchgfx::ButtonWithIcon btn_move_left;
    touchgfx::ButtonWithIcon btn_move_down;
    touchgfx::ButtonWithIcon btn_move_right;
    touchgfx::ButtonWithIcon btn_move_up;
    touchgfx::TextArea textArea1;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::Container container2;
    touchgfx::TextArea textArea2;
    touchgfx::TextAreaWithOneWildcard txt_dist;
    touchgfx::ButtonWithIcon btn_dist_down;
    touchgfx::ButtonWithIcon btn_dist_up;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::ScalableImage scalableImage1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  >  btn_p_m;
    touchgfx::Container container3;
    touchgfx::TextArea textArea1_1;
    touchgfx::Line line1_2;
    touchgfx::PainterRGB565 line1_2Painter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXT_DIST_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txt_distBuffer[TXT_DIST_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ManualViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<ManualViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // MANUALVIEWBASE_HPP
