#ifndef PHASE4VIEW_HPP
#define PHASE4VIEW_HPP

#include <gui_generated/phase4_screen/Phase4ViewBase.hpp>
#include <gui/phase4_screen/Phase4Presenter.hpp>

class Phase4View : public Phase4ViewBase
{
public:
    Phase4View();
    virtual ~Phase4View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    // Virtual function called when radio button selection changes
    virtual void updateQuarterData();
protected:
    // Callback for pie chart clicks
    touchgfx::Callback<Phase4View, const touchgfx::Container&, const touchgfx::ClickEvent&> pieChartClickedCallback;

    // Click handler function
    void pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt);

    // Variables to track which slice is selected
    bool serie1Selected;
    bool serie2Selected;
    bool serie3Selected;
    bool serie4Selected;
    bool serie5Selected;
    bool serie6Selected;

    bool allSlicesExpanded;

    // The percentage values for each slice
    int serie1Value;
    int serie2Value;
    int serie3Value;
    int serie4Value;
    int serie5Value;
    int serie6Value;

    // Helper function to determine which slice was clicked
    int getClickedSlice(int16_t clickX, int16_t clickY);

    // NEW: Helper function to move a slice outward or back to center
    void moveSlice(touchgfx::Circle& slice, int arcStart, int arcEnd, bool moveOut);
    void toggleAllSlices();
    int16_t originalCenterX;
    int16_t originalCenterY;
//    void updatePieChart(int newSerie1Value, int newSerie2Value);
    void updatePieChart(int s1, int s2, int s3, int s4, int s5, int s6);
};

#endif // PHASE4VIEW_HPP
