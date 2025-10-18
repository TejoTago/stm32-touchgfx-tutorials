#ifndef LINECHARTSLIDERYAXISPRESENTER_HPP
#define LINECHARTSLIDERYAXISPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LineChartSliderYAxisView;

class LineChartSliderYAxisPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LineChartSliderYAxisPresenter(LineChartSliderYAxisView& v);

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

    virtual ~LineChartSliderYAxisPresenter() {}

private:
    LineChartSliderYAxisPresenter();

    LineChartSliderYAxisView& view;
};

#endif // LINECHARTSLIDERYAXISPRESENTER_HPP
