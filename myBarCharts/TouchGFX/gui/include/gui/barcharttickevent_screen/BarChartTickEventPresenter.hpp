#ifndef BARCHARTTICKEVENTPRESENTER_HPP
#define BARCHARTTICKEVENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BarChartTickEventView;

class BarChartTickEventPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    BarChartTickEventPresenter(BarChartTickEventView& v);

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

    virtual ~BarChartTickEventPresenter() {}

private:
    BarChartTickEventPresenter();

    BarChartTickEventView& view;
};

#endif // BARCHARTTICKEVENTPRESENTER_HPP
