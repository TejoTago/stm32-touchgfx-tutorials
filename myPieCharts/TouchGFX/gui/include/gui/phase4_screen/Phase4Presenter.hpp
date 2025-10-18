#ifndef PHASE4PRESENTER_HPP
#define PHASE4PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Phase4View;

class Phase4Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Phase4Presenter(Phase4View& v);

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

    virtual ~Phase4Presenter() {}

private:
    Phase4Presenter();

    Phase4View& view;
};

#endif // PHASE4PRESENTER_HPP
