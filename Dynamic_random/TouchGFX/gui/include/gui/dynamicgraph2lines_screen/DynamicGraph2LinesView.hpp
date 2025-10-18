#ifndef DYNAMICGRAPH2LINESVIEW_HPP
#define DYNAMICGRAPH2LINESVIEW_HPP

#include <gui_generated/dynamicgraph2lines_screen/DynamicGraph2LinesViewBase.hpp>
#include <gui/dynamicgraph2lines_screen/DynamicGraph2LinesPresenter.hpp>

class DynamicGraph2LinesView : public DynamicGraph2LinesViewBase
{
public:
    DynamicGraph2LinesView();
    virtual ~DynamicGraph2LinesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    int tickCounter;
        // Previous values for delta-based simulation
        int16_t lastBlueValue;
        int16_t lastVioletValue;

        // Tick handler
        void handleTickEvent();

        // Delta-based random generator
        int16_t generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta);

        // Graph visibility helper
        void updateLineVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementLine& line);
        void updateDotsVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementDots& dots);
        void updateGraphElements(touchgfx::ToggleButton& lineToggle,
                                 touchgfx::GraphElementLine& line,
                                 touchgfx::ToggleButton& dotsToggle,
                                 touchgfx::GraphElementDots& dots,
								 touchgfx::GraphScroll<31>& graph);
        void updateGraph();
};

#endif // DYNAMICGRAPH2LINESVIEW_HPP
