#ifndef RADIOBUTTONSEMAPHORENEWPRESENTER_HPP
#define RADIOBUTTONSEMAPHORENEWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RadioButtonSemaphoreNewView;

class RadioButtonSemaphoreNewPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    RadioButtonSemaphoreNewPresenter(RadioButtonSemaphoreNewView& v);

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

    virtual ~RadioButtonSemaphoreNewPresenter() {}

private:
    RadioButtonSemaphoreNewPresenter();

    RadioButtonSemaphoreNewView& view;
};

#endif // RADIOBUTTONSEMAPHORENEWPRESENTER_HPP
