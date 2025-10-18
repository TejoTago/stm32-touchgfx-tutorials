#ifndef PHASE1PRESENTER_HPP
#define PHASE1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Phase1View;

class Phase1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Phase1Presenter(Phase1View& v);

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

    virtual ~Phase1Presenter() {}

private:
    Phase1Presenter();

    Phase1View& view;
};

#endif // PHASE1PRESENTER_HPP
