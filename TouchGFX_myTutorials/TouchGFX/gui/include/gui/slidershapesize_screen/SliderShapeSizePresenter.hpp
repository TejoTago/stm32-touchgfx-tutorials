#ifndef SLIDERSHAPESIZEPRESENTER_HPP
#define SLIDERSHAPESIZEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SliderShapeSizeView;

class SliderShapeSizePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SliderShapeSizePresenter(SliderShapeSizeView& v);

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

    virtual ~SliderShapeSizePresenter() {}

private:
    SliderShapeSizePresenter();

    SliderShapeSizeView& view;
};

#endif // SLIDERSHAPESIZEPRESENTER_HPP
