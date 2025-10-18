#include <gui/phase1_screen/Phase1View.hpp>

Phase1View::Phase1View():
pieChartClickedCallback(this, &Phase1View::pieChartClickHandler),
serie1Selected(false),
serie1Value(100)
{

}

void Phase1View::setupScreen()
{
    Phase1ViewBase::setupScreen();
    // Make the container clickable
    pieChartContainer.setClickAction(pieChartClickedCallback);

    // Initialize the text with the percentage value
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d", serie1Value);
    serie1Percentage.invalidate();
}

void Phase1View::tearDownScreen()
{
    Phase1ViewBase::tearDownScreen();
}

void Phase1View::pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt)
{
    // Only respond to RELEASED events (when finger lifts up)
    if (evt.getType() != ClickEvent::RELEASED)
    {
        return;  // Ignore PRESSED and CANCEL events
    }
	// Toggle selection state
    serie1Selected = !serie1Selected;

    // Show or hide the text based on selection
    if (serie1Selected)
    {
        serie1Percentage.setVisible(true);

    }
    else
    {
        serie1Percentage.setVisible(false);
    }

    // Redraw the text area
    serie1Percentage.invalidate();
}
