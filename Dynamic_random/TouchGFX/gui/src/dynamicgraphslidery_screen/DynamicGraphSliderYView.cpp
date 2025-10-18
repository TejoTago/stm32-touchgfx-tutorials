#include <gui/DynamicGraphSliderY_screen/DynamicGraphSliderYView.hpp>
#include <cstdlib>

DynamicGraphSliderYView::DynamicGraphSliderYView()
    : tickCounter(0), lastBlueValue(0), lastGreenValue(0), last0Value(0)
{
	srand(tickCounter);
}

void DynamicGraphSliderYView::setupScreen()
{
    DynamicGraphSliderYViewBase::setupScreen();
    toggleBlueLine.forceState(true);
    toggleBlueDots.forceState(true);
    toggleGreenLine.forceState(true);
    toggleGreenDots.forceState(true);
    toggleBox.forceState(false);
    toggleGrid.forceState(false);
    updateBlueGraph();
    updateGreenGraph();
    customizeScreen();

    // Initialize Y-axis range with slider default value
    sliderYAxisValueChanged(sliderY.getValue());
    sliderValueChangedCallback = touchgfx::Callback<DynamicGraphSliderYView, const touchgfx::Slider&, int>(
        this, &DynamicGraphSliderYView::onSliderYChanged);

    sliderY.setNewValueCallback(sliderValueChangedCallback);

}

void DynamicGraphSliderYView::tearDownScreen()
{
    DynamicGraphSliderYViewBase::tearDownScreen();
}

void DynamicGraphSliderYView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 10 == 0)
    {
        dynamicGraphBlue.addDataPoint(generateDeltaValue(lastBlueValue, -20, 100, 5));
        dynamicGraphGreen.addDataPoint(generateDeltaValue(lastGreenValue, -20, 100, 5));
        dynamicGraph0.addDataPoint(generateDeltaValue(last0Value, -20, 100, 5));
    }
}

int16_t DynamicGraphSliderYView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
{
    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
    int16_t newValue = lastValue + delta;

    // Clamp to min/max
    if (newValue < min) newValue = min;
    if (newValue > max) newValue = max;

    lastValue = newValue;
    return newValue;
}

void DynamicGraphSliderYView::updateLineVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementLine& line)
{
    line.setAlpha(toggle.getState() ? 255 : 0);
    line.invalidate();
}

void DynamicGraphSliderYView::updateDotsVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementDots& dots)
{
    dots.setAlpha(toggle.getState() ? 255 : 0);
    dots.invalidate();
}

void DynamicGraphSliderYView::updateGraphElements(touchgfx::ToggleButton& lineToggle,
                                               touchgfx::GraphElementLine& line,
                                               touchgfx::ToggleButton& dotsToggle,
                                               touchgfx::GraphElementDots& dots,
                                               touchgfx::GraphScroll<31>& graph)
{
	updateLineVisibility(lineToggle, line);
    updateDotsVisibility(dotsToggle, dots);
    graph.invalidate();
}

void DynamicGraphSliderYView::updateBlueGraph()
{
	updateGraphElements(toggleBlueLine, dynamicGraphBlueLine1,
	                    toggleBlueDots, dynamicGraphBlueDots1,
	                    dynamicGraphBlue);

    dynamicGraphBlue.invalidate();
}

void DynamicGraphSliderYView::updateGreenGraph()
{
	updateGraphElements(toggleGreenLine, dynamicGraphGreenLine1,
	                    toggleGreenDots, dynamicGraphGreenDots1,
	                    dynamicGraphGreen);
    dynamicGraphGreen.invalidate();
}

void DynamicGraphSliderYView::customizeScreen()
{
    if (toggleBox.getState() == false)
    {
        box1.setAlpha(0);
    }
    else
    {
        box1.setAlpha(255);
    }

    if (toggleGrid.getState() == false)
    {
    	dynamicGraph0MajorYAxisGrid.setAlpha(0);
    }
    else
    {
    	dynamicGraph0MajorYAxisGrid.setAlpha(255);
    }
    dynamicGraph0.invalidate();
}

//void DynamicGraphSliderYView::setYAxis()
//{
//
//}

void DynamicGraphSliderYView::sliderYAxisValueChanged(int value)
{
    // Set Y-axis range for all graphs
    dynamicGraphBlue.setGraphRangeY(-20, value);
    dynamicGraphGreen.setGraphRangeY(-20, value);
    dynamicGraph0.setGraphRangeY(-20, value);

    // Adjust grid and label intervals based on range
    if (value > 199)
    {
        dynamicGraph0MajorYAxisLabel.setInterval(50);
        dynamicGraph0MajorYAxisGrid.setInterval(50);
    }
    else if (value > 100)
    {
        dynamicGraph0MajorYAxisLabel.setInterval(20);
        dynamicGraph0MajorYAxisGrid.setInterval(20);
    }
    else
    {
        dynamicGraph0MajorYAxisLabel.setInterval(10);
        dynamicGraph0MajorYAxisGrid.setInterval(10);
    }

    // Invalidate to redraw
    dynamicGraphBlue.invalidate();
    dynamicGraphGreen.invalidate();
    dynamicGraph0.invalidate();
    dynamicGraph0MajorYAxisLabel.invalidate();
    dynamicGraph0MajorYAxisGrid.invalidate();
}

void DynamicGraphSliderYView::onSliderYChanged(const touchgfx::Slider& src, int value)
{
    sliderYAxisValueChanged(value);
}
