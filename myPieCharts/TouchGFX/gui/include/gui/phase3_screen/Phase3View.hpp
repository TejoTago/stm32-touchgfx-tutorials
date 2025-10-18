#ifndef PHASE3VIEW_HPP
#define PHASE3VIEW_HPP

#include <gui_generated/phase3_screen/Phase3ViewBase.hpp>
#include <gui/phase3_screen/Phase3Presenter.hpp>

class Phase3View : public Phase3ViewBase
{
public:
    Phase3View();
    virtual ~Phase3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    // Callback for pie chart clicks
    touchgfx::Callback<Phase3View, const touchgfx::Container&, const touchgfx::ClickEvent&> pieChartClickedCallback;

    // Click handler function
    void pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt);

    // Variables to track which slice is selected
    bool serie1Selected;
    bool serie2Selected;

    // The percentage values for each slice
    int serie1Value;
    int serie2Value;

    // Helper function to determine which slice was clicked
    int getClickedSlice(int16_t clickX, int16_t clickY);

    // NEW: Helper function to move a slice outward or back to center
    void moveSlice(touchgfx::Circle& slice, int arcStart, int arcEnd, bool moveOut);

    int16_t originalCenterX;
    int16_t originalCenterY;
};

#endif
