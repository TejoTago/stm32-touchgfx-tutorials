#ifndef DYNAMICGRAPHPRESENTER_HPP
#define DYNAMICGRAPHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DynamicGraphView;

class DynamicGraphPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DynamicGraphPresenter(DynamicGraphView& v);

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

    virtual ~DynamicGraphPresenter() {}
    void setBlue(bool state);
    void setGreen(bool state);

private:
    DynamicGraphPresenter();

    DynamicGraphView& view;
};

#endif // DYNAMICGRAPHPRESENTER_HPP
