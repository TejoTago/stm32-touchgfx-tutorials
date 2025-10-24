#ifndef LOLLIPOPPRESENTER_HPP
#define LOLLIPOPPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class lollipopView;

class lollipopPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    lollipopPresenter(lollipopView& v);

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

    virtual ~lollipopPresenter() {}

private:
    lollipopPresenter();

    lollipopView& view;
};

#endif // LOLLIPOPPRESENTER_HPP
