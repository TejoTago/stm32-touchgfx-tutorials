#include <gui/phase3_screen/Phase3View.hpp>
#include <touchgfx/Math3D.hpp>

Phase3View::Phase3View():
    pieChartClickedCallback(this, &Phase3View::pieChartClickHandler),
    serie1Selected(false),
    serie2Selected(false),
    serie1Value(50),
    serie2Value(50),
    originalCenterX(120),
    originalCenterY(120)
{

}

void Phase3View::setupScreen()
{
    Phase3ViewBase::setupScreen();

    // Make the container clickable
    pieChartContainer.setClickAction(pieChartClickedCallback);
    serie1.setCenter(originalCenterX, originalCenterY);
    serie2.setCenter(originalCenterX, originalCenterY);

    // Initialize both text areas with percentage values
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d", serie1Value);
    serie1Percentage.setVisible(false);
    serie1Percentage.invalidate();

    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d", serie2Value);
    serie2Percentage.setVisible(false);
    serie2Percentage.invalidate();
}

void Phase3View::tearDownScreen()
{
    Phase3ViewBase::tearDownScreen();
}

void Phase3View::pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt)
{
    // Only respond to RELEASED events
    if (evt.getType() != ClickEvent::RELEASED)
    {
        return;
    }

    // Get click coordinates
    int16_t clickX = evt.getX();
    int16_t clickY = evt.getY();

    // Determine which slice was clicked (returns 1 or 2, or 0 if outside)
    int clickedSlice = getClickedSlice(clickX, clickY);

    if (clickedSlice == 1)
    {
        // Toggle Serie1
        serie1Selected = !serie1Selected;
        serie1Percentage.setVisible(serie1Selected);
        serie1Percentage.invalidate();

        // NEW: Move Serie1 outward if selected, back to center if deselected
        moveSlice(serie1, 0, 100, serie1Selected);
    }
    else if (clickedSlice == 2)
    {
        // Toggle Serie2
        serie2Selected = !serie2Selected;
        serie2Percentage.setVisible(serie2Selected);
        serie2Percentage.invalidate();

        // NEW: Move Serie2 outward if selected, back to center if deselected
        moveSlice(serie2, 101, 360, serie2Selected);
    }
}

int Phase3View::getClickedSlice(int16_t clickX, int16_t clickY)
{
    // Center point of the pie chart
    const int16_t centerX = 120;
    const int16_t centerY = 120;
    const int16_t radius = 60;

    // Calculate distance from center
    int16_t deltaX = clickX - centerX;
    int16_t deltaY = clickY - centerY;
    int distanceSquared = (deltaX * deltaX) + (deltaY * deltaY);
    int radiusSquared = radius * radius;

    // Check if click is within the circle
    if (distanceSquared > radiusSquared)
    {
        return 0;  // Outside the circle
    }

    // Calculate angle of click using TouchGFX's angle function
    int angleInDegrees = CWRUtil::angle(deltaX, deltaY);

    // Serie1: 180° to 360° (right half)
    // Serie2: 0° to 180° (left half)

    if (angleInDegrees >= 0 && angleInDegrees <= 100)
    {
        return 1;  // Serie1 was clicked
    }
    else if (angleInDegrees > 100 && angleInDegrees <= 360)
    {
        return 2;  // Serie2 was clicked
    }

    return 0;
}

void Phase3View::moveSlice(touchgfx::Circle& slice, int arcStart, int arcEnd, bool moveOut)
{
//    // Original center position
//    const int16_t centerX = 120;
//    const int16_t centerY = 120;

    if (moveOut)
    {
        // Calculate the middle angle of the slice
        int arcAngle = arcEnd - arcStart;  // Total angle of the slice
        int middleAngle = arcStart + (arcAngle / 2);  // Middle of the arc

        // Calculate offset using trigonometry
        // Move 15 pixels in the direction of the middle angle
        int offsetX = (CWRUtil::toQ5(15) * CWRUtil::sine(middleAngle)).to<int>();
        int offsetY = -(CWRUtil::toQ5(15) * CWRUtil::cosine(middleAngle)).to<int>();

        // Set new center position (offset from original)
        slice.setCenter(originalCenterX + offsetX, originalCenterY + offsetY);
    }
    else
    {
        // Move back to center
        slice.setCenter(originalCenterX, originalCenterY);
    }

    // Trigger redraw
//    slice.invalidate();
    pieChartContainer.invalidate();
}
