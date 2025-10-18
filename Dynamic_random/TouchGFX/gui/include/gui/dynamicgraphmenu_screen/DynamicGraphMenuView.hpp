#ifndef DYNAMICGRAPHMENUVIEW_HPP
#define DYNAMICGRAPHMENUVIEW_HPP

#include <gui_generated/dynamicgraphmenu_screen/DynamicGraphMenuViewBase.hpp>
#include <gui/dynamicgraphmenu_screen/DynamicGraphMenuPresenter.hpp>

class DynamicGraphMenuView : public DynamicGraphMenuViewBase
{
public:
    DynamicGraphMenuView();
    virtual ~DynamicGraphMenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

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
        void updateLineVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementLine& line);
        void updateDotsVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementDots& dots);
        void updateGraphElements(touchgfx::ToggleButton& lineToggle,
                                 touchgfx::GraphElementLine& line,
                                 touchgfx::ToggleButton& dotsToggle,
                                 touchgfx::GraphElementDots& dots,
                                 touchgfx::GraphScroll<31>& graph);
        void updateBlueGraph();
        void updateGreenGraph();
};

#endif // DYNAMICGRAPHMENUVIEW_HPP
