#ifndef PIECHARTTOGGLEFULLSEMIVIEW_HPP
#define PIECHARTTOGGLEFULLSEMIVIEW_HPP

#include <gui_generated/piecharttogglefullsemi_screen/PieChartToggleFullSemiViewBase.hpp>
#include <gui/piecharttogglefullsemi_screen/PieChartToggleFullSemiPresenter.hpp>

class PieChartToggleFullSemiView : public PieChartToggleFullSemiViewBase
{
public:
    PieChartToggleFullSemiView();
    virtual ~PieChartToggleFullSemiView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    virtual void updateQuarterData();
    virtual void toggleCircleMode();
protected:
    touchgfx::Callback<PieChartToggleFullSemiView, const touchgfx::Container&, const touchgfx::ClickEvent&> pieChartClickedCallback;
    void pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt);

    bool serie1Selected;
    bool serie2Selected;
    bool serie3Selected;
    bool serie4Selected;
    bool serie5Selected;
    bool serie6Selected;
    bool allSlicesExpanded;

    int serie1Value;
    int serie2Value;
    int serie3Value;
    int serie4Value;
    int serie5Value;
    int serie6Value;

    int getClickedSlice(int16_t clickX, int16_t clickY);
    void moveSlice(touchgfx::Circle& slice, int arcStart, int arcEnd, bool moveOut);
    void updatePieChart(int s1, int s2, int s3, int s4, int s5, int s6);
    void toggleAllSlices();

    int16_t originalCenterX;
    int16_t originalCenterY;

    // Animation variables
    enum AnimationState
    {
        NO_ANIMATION,
        DRAW_PIECHART
    };

    AnimationState currentAnimation;

    // Animation progress tracking
    int radiusAnimation;           // Current radius (grows from 0 to 60)
    int angleStartAnimation;       // Starting angle rotation (90 to 360)
    int angle1Animation;           // Progressive angles for each serie
    int angle2Animation;
    int angle3Animation;
    int angle4Animation;
    int angle5Animation;
    int angle6Animation;

    // Target angles (calculated from percentages)
    int angle1Target;
    int angle2Target;
    int angle3Target;
    int angle4Target;
    int angle5Target;
    int angle6Target;

    // Animation function
    void drawPieChartAnimation();
    // Mode state
    bool isFullCircle;  // true = full circle (0°→360°), false = semicircle (270°→450°)

    // Helper methods for dynamic angle calculation
    int getStartAngle() const;
    int getAngleRange() const;
    int getEndAngle() const;
};

#endif // PIECHARTTOGGLEFULLSEMIVIEW_HPP
