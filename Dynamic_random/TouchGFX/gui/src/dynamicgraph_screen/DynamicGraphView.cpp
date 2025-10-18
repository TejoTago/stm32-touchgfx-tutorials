#include <gui/dynamicgraph_screen/DynamicGraphView.hpp>
#include <cstdlib>  // rand(), srand()
//#include <ctime>    // time()


DynamicGraphView::DynamicGraphView()
    : tickCounter(0), lastBlueValue(0), lastGreenValue(0)
{
    //srand(static_cast<unsigned int>(time(nullptr))); // Seed random generator
	srand(tickCounter);
}

void DynamicGraphView::setupScreen()
{
    DynamicGraphViewBase::setupScreen();
}

void DynamicGraphView::tearDownScreen()
{
    DynamicGraphViewBase::tearDownScreen();
}

void DynamicGraphView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 10 == 0)
    {
        dynamicGraphBlue.addDataPoint(generateDeltaValue(lastBlueValue, -20, 100, 5));
        dynamicGraphGreen.addDataPoint(generateDeltaValue(lastGreenValue, -20, 100, 5));
    }
}

int16_t DynamicGraphView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
{
    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
    int16_t newValue = lastValue + delta;

    // Clamp to min/max
    if (newValue < min) newValue = min;
    if (newValue > max) newValue = max;

    lastValue = newValue;
    return newValue;
}

void DynamicGraphView::updateGraphState(touchgfx::ToggleButton& toggle, touchgfx::GraphScroll<31>& graph, bool state)
{
    toggle.forceState(state);
    graph.setVisible(state);
    toggle.invalidate();
    graph.invalidate();
}

void DynamicGraphView::updateBlueGraph()
{
    bool state = toggleBlue.getState();
    presenter->setBlue(state);
    updateGraphState(toggleBlue, dynamicGraphBlue, state);
}

void DynamicGraphView::updateGreenGraph()
{
    bool state = toggleGreen.getState();
    presenter->setGreen(state);
    updateGraphState(toggleGreen, dynamicGraphGreen, state);
}

void DynamicGraphView::setBlue(bool state)
{
    updateGraphState(toggleBlue, dynamicGraphBlue, state);
}

void DynamicGraphView::setGreen(bool state)
{
    updateGraphState(toggleGreen, dynamicGraphGreen, state);
}
