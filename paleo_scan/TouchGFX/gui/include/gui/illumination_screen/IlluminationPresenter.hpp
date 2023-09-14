#ifndef ILLUMINATIONPRESENTER_HPP
#define ILLUMINATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class IlluminationView;

class IlluminationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    IlluminationPresenter(IlluminationView& v);

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

    virtual ~IlluminationPresenter() {};

private:
    IlluminationPresenter();

    IlluminationView& view;
};

#endif // ILLUMINATIONPRESENTER_HPP
