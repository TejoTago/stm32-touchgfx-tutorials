#ifndef DYNAMICGRAPHSLIDEMENUPRESENTER_HPP
#define DYNAMICGRAPHSLIDEMENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DynamicGraphSlideMenuView;

class DynamicGraphSlideMenuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DynamicGraphSlideMenuPresenter(DynamicGraphSlideMenuView& v);

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

    virtual ~DynamicGraphSlideMenuPresenter() {}

private:
    DynamicGraphSlideMenuPresenter();

    DynamicGraphSlideMenuView& view;
};

#endif // DYNAMICGRAPHSLIDEMENUPRESENTER_HPP
