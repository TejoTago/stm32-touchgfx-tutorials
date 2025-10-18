#ifndef PHASE5PRESENTER_HPP
#define PHASE5PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Phase5View;

class Phase5Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Phase5Presenter(Phase5View& v);

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

    virtual ~Phase5Presenter() {}

private:
    Phase5Presenter();

    Phase5View& view;
};

#endif // PHASE5PRESENTER_HPP
