#ifndef AUTOMATICPRESENTER_HPP
#define AUTOMATICPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AutomaticView;

class AutomaticPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AutomaticPresenter(AutomaticView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~AutomaticPresenter() {};

private:
    AutomaticPresenter();

    AutomaticView& view;
};

#endif // AUTOMATICPRESENTER_HPP
