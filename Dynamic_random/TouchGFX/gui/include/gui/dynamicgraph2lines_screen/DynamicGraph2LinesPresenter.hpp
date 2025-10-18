#ifndef DYNAMICGRAPH2LINESPRESENTER_HPP
#define DYNAMICGRAPH2LINESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DynamicGraph2LinesView;

class DynamicGraph2LinesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DynamicGraph2LinesPresenter(DynamicGraph2LinesView& v);

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

    virtual ~DynamicGraph2LinesPresenter() {}

private:
    DynamicGraph2LinesPresenter();

    DynamicGraph2LinesView& view;
};

#endif // DYNAMICGRAPH2LINESPRESENTER_HPP
