#include <gui/phase2_screen/Phase2View.hpp>

Phase2View::Phase2View():
pieChartClickedCallback(this, &Phase2View::pieChartClickHandler),
serie1Selected(false),
serie2Selected(false),
serie1Value(50),
serie2Value(50)
{

}

void Phase2View::setupScreen()
{
    Phase2ViewBase::setupScreen();
    // Make the container clickable
    pieChartContainer.setClickAction(pieChartClickedCallback);

    // Initialize both text areas with percentage values
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d", serie1Value);
    serie1Percentage.setVisible(false);
    serie1Percentage.invalidate();

    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d", serie2Value);
    serie2Percentage.setVisible(false);
    serie2Percentage.invalidate();

}

void Phase2View::tearDownScreen()
{
    Phase2ViewBase::tearDownScreen();
}

void Phase2View::pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt)
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
    }
    else if (clickedSlice == 2)
    {
        // Toggle Serie2
        serie2Selected = !serie2Selected;
        serie2Percentage.setVisible(serie2Selected);
        serie2Percentage.invalidate();
    }
    // If clickedSlice == 0, click was outside both slices, do nothing
}

int Phase2View::getClickedSlice(int16_t clickX, int16_t clickY)
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
    // Returns angle in degrees from 0-360
    int angleInDegrees = CWRUtil::angle(deltaX, deltaY);

    // Serie1: 180° to 360° (right half)
    // Serie2: 0° to 180° (left half)

    if (angleInDegrees >= 0 && angleInDegrees <= 100)
    {
        return 1;  // Serie1 was clicked
    }
    else if (angleInDegrees >= 100 && angleInDegrees < 360)
    {
        return 2;  // Serie2 was clicked
    }

    return 0;  // Shouldn't reach here, but safe fallback
}
