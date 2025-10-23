#ifndef BARCHARTTICKEVENTVIEW_HPP
#define BARCHARTTICKEVENTVIEW_HPP

#include <gui_generated/barcharttickevent_screen/BarChartTickEventViewBase.hpp>
#include <gui/barcharttickevent_screen/BarChartTickEventPresenter.hpp>

class BarChartTickEventView : public BarChartTickEventViewBase
{
public:
    BarChartTickEventView();
    virtual ~BarChartTickEventView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    // Handle tick event for timer-based updates
    virtual void handleTickEvent();

protected:
    void updateColumnHeightsRandom();

    // Store shape points as member variables so they persist in memory
    touchgfx::AbstractShape::ShapePoint<float> col1Points[4];
    touchgfx::AbstractShape::ShapePoint<float> col2Points[4];
    touchgfx::AbstractShape::ShapePoint<float> col3Points[4];
    touchgfx::AbstractShape::ShapePoint<float> col4Points[4];

    // Timer control variables
    uint16_t tickCounter;
    uint16_t updateCounter;
    bool animationActive;
    int analogSeconds;
};

#endif // BARCHARTTICKEVENTVIEW_HPP
