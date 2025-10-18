#ifndef DYNAMICGRAPHSLIDERYVIEW_HPP
#define DYNAMICGRAPHSLIDERYVIEW_HPP

#include <gui_generated/dynamicgraphslidery_screen/DynamicGraphSliderYViewBase.hpp>
#include <gui/dynamicgraphslidery_screen/DynamicGraphSliderYPresenter.hpp>

class DynamicGraphSliderYView : public DynamicGraphSliderYViewBase
{
public:
    DynamicGraphSliderYView();
    virtual ~DynamicGraphSliderYView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    // Slider callback for Y-axis control
    virtual void sliderYAxisValueChanged(int value);
    touchgfx::Callback<DynamicGraphSliderYView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    void onSliderYChanged(const touchgfx::Slider& src, int value);

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

//        void setYAxis();
};

#endif // DynamicGraphSliderYVIEW_HPP
