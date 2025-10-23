#ifndef BARCHARTTOGGLEBUTTONSPRESENTER_HPP
#define BARCHARTTOGGLEBUTTONSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BarChartToggleButtonsView;

class BarChartToggleButtonsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    BarChartToggleButtonsPresenter(BarChartToggleButtonsView& v);

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

    virtual ~BarChartToggleButtonsPresenter() {}

private:
    BarChartToggleButtonsPresenter();

    BarChartToggleButtonsView& view;
};

#endif // BARCHARTTOGGLEBUTTONSPRESENTER_HPP
