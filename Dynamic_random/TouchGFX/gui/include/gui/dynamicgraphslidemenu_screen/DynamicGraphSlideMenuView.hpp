#ifndef DYNAMICGRAPHSLIDEMENUVIEW_HPP
#define DYNAMICGRAPHSLIDEMENUVIEW_HPP

#include <gui_generated/dynamicgraphslidemenu_screen/DynamicGraphSlideMenuViewBase.hpp>
#include <gui/dynamicgraphslidemenu_screen/DynamicGraphSlideMenuPresenter.hpp>

class DynamicGraphSlideMenuView : public DynamicGraphSlideMenuViewBase
{
public:
    DynamicGraphSlideMenuView();
    virtual ~DynamicGraphSlideMenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    int tickCounter;
        // Previous values for delta-based simulation
        int16_t lastBlueValue;
        int16_t lastGreenValue;
        int16_t last0Value;

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
        //void update0Graph();
        void customizeScreen();
};

#endif // DYNAMICGRAPHSLIDEMENUVIEW_HPP
