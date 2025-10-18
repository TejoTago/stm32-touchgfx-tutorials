#ifndef SCREENLOGOPRESENTER_HPP
#define SCREENLOGOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenLogoView;

class ScreenLogoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenLogoPresenter(ScreenLogoView& v);

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

    virtual ~ScreenLogoPresenter() {}

private:
    ScreenLogoPresenter();

    ScreenLogoView& view;
};

#endif // SCREENLOGOPRESENTER_HPP
