#ifndef DYNAMICGRAPH1PRESENTER_HPP
#define DYNAMICGRAPH1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DynamicGraph1View;

class DynamicGraph1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    DynamicGraph1Presenter(DynamicGraph1View& v);

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

    virtual ~DynamicGraph1Presenter() {}

private:
    DynamicGraph1Presenter();

    DynamicGraph1View& view;
};

#endif // DYNAMICGRAPH1PRESENTER_HPP
