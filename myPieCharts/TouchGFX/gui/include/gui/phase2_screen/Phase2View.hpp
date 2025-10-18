#ifndef PHASE2VIEW_HPP
#define PHASE2VIEW_HPP

#include <gui_generated/phase2_screen/Phase2ViewBase.hpp>
#include <gui/phase2_screen/Phase2Presenter.hpp>

class Phase2View : public Phase2ViewBase
{
public:
    Phase2View();
    virtual ~Phase2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    // Callback for pie chart clicks
    touchgfx::Callback<Phase2View, const touchgfx::Container&, const touchgfx::ClickEvent&> pieChartClickedCallback;

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
};

#endif // PHASE2VIEW_HPP
