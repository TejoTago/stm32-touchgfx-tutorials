#include <gui/DynamicGraph2Lines_screen/DynamicGraph2LinesView.hpp>
#include <cstdlib>  // rand(), srand()
//#include <ctime>    // time()


DynamicGraph2LinesView::DynamicGraph2LinesView()
    : tickCounter(0), lastBlueValue(0), lastVioletValue(0)
{
    //srand(static_cast<unsigned int>(time(nullptr))); // Seed random generator
	srand(tickCounter);
}

void DynamicGraph2LinesView::setupScreen()
{
    DynamicGraph2LinesViewBase::setupScreen();
//    if (!dynamicGraph.isGraphElementAdded(dynamicGraphLine1)) {
//        dynamicGraph.addGraphElement(dynamicGraphLine1);
//        dynamicGraph.addGraphElement(dynamicGraphDots1);
//        dynamicGraph.addGraphElement(dynamicGraphLine2);
//        dynamicGraph.addGraphElement(dynamicGraphDots2);

    toggleL1.forceState(true);
    toggleD1.forceState(true);
    toggleL2.forceState(true);
    toggleD2.forceState(true);
//    dynamicGraph.addGraphElement(dynamicGraphLine1); //Simulator Crashed!!
//    dynamicGraph.addGraphElement(dynamicGraphDots1);
//    dynamicGraph.addGraphElement(dynamicGraphLine2);
//    dynamicGraph.addGraphElement(dynamicGraphDots2);
    updateGraph();
}

void DynamicGraph2LinesView::tearDownScreen()
{
    DynamicGraph2LinesViewBase::tearDownScreen();
//    dynamicGraph.removeGraphElement(dynamicGraphLine1);
//    dynamicGraph.removeGraphElement(dynamicGraphDots1);
//    dynamicGraph.removeGraphElement(dynamicGraphLine2);
//    dynamicGraph.removeGraphElement(dynamicGraphDots2);
}

void DynamicGraph2LinesView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 10 == 0)
    {
        int16_t valueBlue = generateDeltaValue(lastBlueValue, -20, 100, 5);
         int16_t valueViolet = generateDeltaValue(lastVioletValue, -20, 100, 5) + 10;

//         dynamicGraphLine1.addDataPoint(value1);
//         dynamicGraphDots1.addDataPoint(value1);
//
//         dynamicGraphLine2.addDataPoint(value2);
//         dynamicGraphDots2.addDataPoint(value2);
         dynamicGraph.addDataPoint(valueBlue); // This will go to all elements in the graph
         dynamicGraph.addDataPoint(valueViolet);

         dynamicGraph.invalidate();
    }
}

int16_t DynamicGraph2LinesView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
{
    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
    int16_t newValue = lastValue + delta;

    // Clamp to min/max
    if (newValue < min) newValue = min;
    if (newValue > max) newValue = max;

    lastValue = newValue;
    return newValue;
}

void DynamicGraph2LinesView::updateLineVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementLine& line)
{
    line.setAlpha(toggle.getState() ? 255 : 0);
    line.invalidate();
}

void DynamicGraph2LinesView::updateDotsVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementDots& dots)
{
    dots.setAlpha(toggle.getState() ? 255 : 0);
    dots.invalidate();
}

void DynamicGraph2LinesView::updateGraphElements(touchgfx::ToggleButton& lineToggle,
                                               touchgfx::GraphElementLine& line,
                                               touchgfx::ToggleButton& dotsToggle,
                                               touchgfx::GraphElementDots& dots,
                                               touchgfx::GraphScroll<31>& graph)
{
	updateLineVisibility(lineToggle, line);
    updateDotsVisibility(dotsToggle, dots);
//    dynamicGraph.invalidate();
}

void DynamicGraph2LinesView::updateGraph()
{
    updateGraphElements(toggleL1, dynamicGraphLine1, toggleD1, dynamicGraphDots1,dynamicGraph);
//    dynamicGraph.invalidate();
    updateGraphElements(toggleL2, dynamicGraphLine2, toggleD2, dynamicGraphDots2, dynamicGraph);
    dynamicGraph.invalidate();
}

