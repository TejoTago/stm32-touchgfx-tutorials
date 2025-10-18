#ifndef PIECHARTPRESENTER_HPP
#define PIECHARTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PieChartView;

class PieChartPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PieChartPresenter(PieChartView& v);

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

    virtual ~PieChartPresenter() {};
    virtual void mcuLoadUpdated(uint8_t mcuLoadValue);

private:
    PieChartPresenter();

    PieChartView& view;
};

#endif // PIECHARTPRESENTER_HPP
