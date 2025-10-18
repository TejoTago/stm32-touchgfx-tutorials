#ifndef WIRELESSICONPRESENTER_HPP
#define WIRELESSICONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WirelessIconView;

class WirelessIconPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    WirelessIconPresenter(WirelessIconView& v);

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

    virtual ~WirelessIconPresenter() {}

private:
    WirelessIconPresenter();

    WirelessIconView& view;
};

#endif // WIRELESSICONPRESENTER_HPP
