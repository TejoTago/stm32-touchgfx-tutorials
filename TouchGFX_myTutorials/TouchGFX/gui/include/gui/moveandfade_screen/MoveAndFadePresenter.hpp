#ifndef MOVEANDFADEPRESENTER_HPP
#define MOVEANDFADEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MoveAndFadeView;

class MoveAndFadePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MoveAndFadePresenter(MoveAndFadeView& v);

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

    virtual ~MoveAndFadePresenter() {}

private:
    MoveAndFadePresenter();

    MoveAndFadeView& view;
};

#endif // MOVEANDFADEPRESENTER_HPP
