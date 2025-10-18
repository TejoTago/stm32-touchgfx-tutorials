#ifndef BARCHARTPRESENTER_HPP
#define BARCHARTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BarChartView;

class BarChartPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    BarChartPresenter(BarChartView& v);

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

    virtual ~BarChartPresenter() {}

private:
    BarChartPresenter();

    BarChartView& view;
};

#endif // BARCHARTPRESENTER_HPP
