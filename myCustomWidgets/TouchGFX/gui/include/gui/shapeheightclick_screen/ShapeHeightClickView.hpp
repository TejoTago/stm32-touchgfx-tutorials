#ifndef SHAPEHEIGHTCLICKVIEW_HPP
#define SHAPEHEIGHTCLICKVIEW_HPP

#include <gui_generated/shapeheightclick_screen/ShapeHeightClickViewBase.hpp>
#include <gui/shapeheightclick_screen/ShapeHeightClickPresenter.hpp>

class ShapeHeightClickView : public ShapeHeightClickViewBase
{
public:
    ShapeHeightClickView();
    virtual ~ShapeHeightClickView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
   // virtual void handleTickEvent(); // Called every frame
    virtual void handleClickEvent(const ClickEvent& evt);
    virtual void handleDragEvent(const DragEvent& evt); // Called on drag
protected:
    int initialTouchY;
    touchgfx::AbstractShape::ShapePoint<float> shapePoints[4];
    float currentHeight = 35.0f; // Initial height (135 - 100)
    bool shapeTouched = false;

    touchgfx::AbstractShape::ShapePoint<float> shape2Points[4];
    float currentHeight2 = 35.0f;
    bool shape2Touched = false;
    int initialTouchY2 = 0;
};

#endif // SHAPEHEIGHTCLICKVIEW_HPP
