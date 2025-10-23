#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
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

#endif // SCREEN1VIEW_HPP
