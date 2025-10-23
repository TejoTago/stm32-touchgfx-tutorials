#ifndef BARCHARTTOGGLEBUTTONSVIEW_HPP
#define BARCHARTTOGGLEBUTTONSVIEW_HPP

#include <gui_generated/barcharttogglebuttons_screen/BarChartToggleButtonsViewBase.hpp>
#include <gui/barcharttogglebuttons_screen/BarChartToggleButtonsPresenter.hpp>

class BarChartToggleButtonsView : public BarChartToggleButtonsViewBase
{
public:
    BarChartToggleButtonsView();
    virtual ~BarChartToggleButtonsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    // Override the virtual function from base class
    virtual void selectQuarter();

protected:
    void updateColumnHeights(int quarter);

    // Store shape points as member variables so they persist in memory
    touchgfx::AbstractShape::ShapePoint<float> col1Points[4];
    touchgfx::AbstractShape::ShapePoint<float> col2Points[4];
    touchgfx::AbstractShape::ShapePoint<float> col3Points[4];
    touchgfx::AbstractShape::ShapePoint<float> col4Points[4];
};

#endif // BARCHARTTOGGLEBUTTONSVIEW_HPP
