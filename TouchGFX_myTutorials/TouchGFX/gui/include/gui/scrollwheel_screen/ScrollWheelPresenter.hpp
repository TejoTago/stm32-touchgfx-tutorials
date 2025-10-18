#ifndef SCROLLWHEELPRESENTER_HPP
#define SCROLLWHEELPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScrollWheelView;

class ScrollWheelPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScrollWheelPresenter(ScrollWheelView& v);

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

    virtual ~ScrollWheelPresenter() {}

private:
    ScrollWheelPresenter();

    ScrollWheelView& view;
};

#endif // SCROLLWHEELPRESENTER_HPP
