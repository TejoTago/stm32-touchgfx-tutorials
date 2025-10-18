#ifndef PHASE3PRESENTER_HPP
#define PHASE3PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Phase3View;

class Phase3Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Phase3Presenter(Phase3View& v);

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

    virtual ~Phase3Presenter() {}

private:
    Phase3Presenter();

    Phase3View& view;
};

#endif // PHASE3PRESENTER_HPP
