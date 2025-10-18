#ifndef BARCHARTVIEW_HPP
#define BARCHARTVIEW_HPP

#include <gui_generated/barchart_screen/BarChartViewBase.hpp>
#include <gui/barchart_screen/BarChartPresenter.hpp>

class BarChartView : public BarChartViewBase
{
public:
    BarChartView();
    virtual ~BarChartView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

protected:
    //virtual void fQuarters();
    int tickCounter;
    int currentSetIndex;
    //bool barsUpdated;
    void updateBars(int setIndex);

};

#endif // BARCHARTVIEW_HPP
