#ifndef LINECHARTSLIDERXAXISPRESENTER_HPP
#define LINECHARTSLIDERXAXISPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LineChartSliderXAxisView;

class LineChartSliderXAxisPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LineChartSliderXAxisPresenter(LineChartSliderXAxisView& v);

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

    virtual ~LineChartSliderXAxisPresenter() {}

private:
    LineChartSliderXAxisPresenter();

    LineChartSliderXAxisView& view;
};

#endif // LINECHARTSLIDERXAXISPRESENTER_HPP
