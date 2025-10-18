#ifndef LINECHARTSLIDERYAXISVIEW_HPP
#define LINECHARTSLIDERYAXISVIEW_HPP

#include <gui_generated/linechartslideryaxis_screen/LineChartSliderYAxisViewBase.hpp>
#include <gui/linechartslideryaxis_screen/LineChartSliderYAxisPresenter.hpp>

class LineChartSliderYAxisView : public LineChartSliderYAxisViewBase
{
public:
    LineChartSliderYAxisView();
    virtual ~LineChartSliderYAxisView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    int tickCounter;
    void handleTickEvent();
    int16_t lastValue;
    int16_t generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta);
//    void LineChartSliderYAxisView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    virtual void setYAxisRange(int value);

};
#endif // LINECHARTSLIDERYAXISVIEW_HPP
