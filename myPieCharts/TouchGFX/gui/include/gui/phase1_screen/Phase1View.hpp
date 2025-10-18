#ifndef PHASE1VIEW_HPP
#define PHASE1VIEW_HPP

#include <gui_generated/phase1_screen/Phase1ViewBase.hpp>
#include <gui/phase1_screen/Phase1Presenter.hpp>

class Phase1View : public Phase1ViewBase
{
public:
    Phase1View();
    virtual ~Phase1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    // Callback for pie chart clicks
    touchgfx::Callback<Phase1View, const touchgfx::Container&, const touchgfx::ClickEvent&> pieChartClickedCallback;



    // Click handler function
    void pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt);

    // Variable to track if slice is selected
    bool serie1Selected;

    // The percentage value for the slice
    int serie1Value;
};

#endif // PHASE1VIEW_HPP
