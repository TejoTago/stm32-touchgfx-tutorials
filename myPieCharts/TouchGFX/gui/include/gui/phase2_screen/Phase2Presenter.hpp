#ifndef PHASE2PRESENTER_HPP
#define PHASE2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Phase2View;

class Phase2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Phase2Presenter(Phase2View& v);

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

    virtual ~Phase2Presenter() {}

private:
    Phase2Presenter();

    Phase2View& view;
};

#endif // PHASE2PRESENTER_HPP
