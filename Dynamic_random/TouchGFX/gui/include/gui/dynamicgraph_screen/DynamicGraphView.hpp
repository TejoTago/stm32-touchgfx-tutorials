#ifndef DYNAMICGRAPHVIEW_HPP
#define DYNAMICGRAPHVIEW_HPP

#include <gui_generated/dynamicgraph_screen/DynamicGraphViewBase.hpp>
#include <gui/dynamicgraph_screen/DynamicGraphPresenter.hpp>

class DynamicGraphView : public DynamicGraphViewBase
{
public:
    DynamicGraphView();
    virtual ~DynamicGraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    // UI update handlers
    void updateBlueGraph();
    void updateGreenGraph();

    void setBlue(bool state);
    void setGreen(bool state);

protected:
    int tickCounter;
    // Previous values for delta-based simulation
    int16_t lastBlueValue;
    int16_t lastGreenValue;

    // Tick handler
    void handleTickEvent();

    // Delta-based random generator
    int16_t generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta);

    // Graph visibility helper
    void updateGraphState(touchgfx::ToggleButton& toggle, touchgfx::GraphScroll<31>& graph, bool state);
};

#endif // DYNAMICGRAPHVIEW_HPP
