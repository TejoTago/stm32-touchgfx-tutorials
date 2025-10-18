#ifndef LINECHARTSLIDERXAXISVIEW_HPP
#define LINECHARTSLIDERXAXISVIEW_HPP

#include <gui_generated/linechartsliderxaxis_screen/LineChartSliderXAxisViewBase.hpp>
#include <gui/linechartsliderxaxis_screen/LineChartSliderXAxisPresenter.hpp>

class LineChartSliderXAxisView : public LineChartSliderXAxisViewBase
{
public:
    LineChartSliderXAxisView();
    virtual ~LineChartSliderXAxisView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    int tickCounter;
    void handleTickEvent();
    int16_t lastValue;
    int16_t generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta);
    virtual void setXAxisRange(int value);
};

#endif // LINECHARTSLIDERXAXISVIEW_HPP
