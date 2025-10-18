#ifndef DYNAMICGRAPHSLIDERYPRESENTER_HPP
#define DYNAMICGRAPHSLIDERYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DynamicGraphSliderYView;

class DynamicGraphSliderYPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DynamicGraphSliderYPresenter(DynamicGraphSliderYView& v);

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

    virtual ~DynamicGraphSliderYPresenter() {}

private:
    DynamicGraphSliderYPresenter();

    DynamicGraphSliderYView& view;
};

#endif // DYNAMICGRAPHSLIDERYPRESENTER_HPP
