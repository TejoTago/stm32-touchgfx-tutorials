#ifndef MOVEWIDGETWITHMIXINPRESENTER_HPP
#define MOVEWIDGETWITHMIXINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MoveWidgetWithMixinView;

class MoveWidgetWithMixinPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MoveWidgetWithMixinPresenter(MoveWidgetWithMixinView& v);

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

    virtual ~MoveWidgetWithMixinPresenter() {}

private:
    MoveWidgetWithMixinPresenter();

    MoveWidgetWithMixinView& view;
};

#endif // MOVEWIDGETWITHMIXINPRESENTER_HPP
