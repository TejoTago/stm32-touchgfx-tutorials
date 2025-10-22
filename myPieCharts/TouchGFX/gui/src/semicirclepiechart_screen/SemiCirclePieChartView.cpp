#include <gui/semicirclepiechart_screen/SemiCirclePieChartView.hpp>
#include <touchgfx/Math3D.hpp>

SemiCirclePieChartView::SemiCirclePieChartView():
    pieChartClickedCallback(this, &SemiCirclePieChartView::pieChartClickHandler),
    serie1Selected(false),
    serie2Selected(false),
    serie3Selected(false),
    serie4Selected(false),
    serie5Selected(false),
    serie6Selected(false),
    allSlicesExpanded(false),
    serie1Value(0),
    serie2Value(0),
    serie3Value(0),
    serie4Value(0),
    serie5Value(0),
    serie6Value(0),
    originalCenterX(120),
    originalCenterY(120),
    currentAnimation(NO_ANIMATION),
    radiusAnimation(0),
    angleStartAnimation(270), // SEMICIRCLE
    angle1Animation(0),
    angle2Animation(0),
    angle3Animation(0),
    angle4Animation(0),
    angle5Animation(0),
    angle6Animation(0),
    angle1Target(0),
    angle2Target(0),
    angle3Target(0),
    angle4Target(0),
    angle5Target(0),
    angle6Target(0)
{

}

void SemiCirclePieChartView::setupScreen()
{
    SemiCirclePieChartViewBase::setupScreen();

    pieChartContainer.setClickAction(pieChartClickedCallback);

    serie1.setCenter(originalCenterX, originalCenterY);
    serie2.setCenter(originalCenterX, originalCenterY);
    serie3.setCenter(originalCenterX, originalCenterY);
    serie4.setCenter(originalCenterX, originalCenterY);
    serie5.setCenter(originalCenterX, originalCenterY);
    serie6.setCenter(originalCenterX, originalCenterY);

    serie1Percentage.setVisible(false);
    serie2Percentage.setVisible(false);
    serie3Percentage.setVisible(false);
    serie4Percentage.setVisible(false);
    serie5Percentage.setVisible(false);
    serie6Percentage.setVisible(false);

    // Set initial values
    serie1Value = 15;
    serie2Value = 20;
    serie3Value = 25;
    serie4Value = 10;
    serie5Value = 18;
    serie6Value = 12;

    // Calculate target angles | SEMICIRCLE
    angle1Target = (serie1Value * 180) / 100;
    angle2Target = (serie2Value * 180) / 100;
    angle3Target = (serie3Value * 180) / 100;
    angle4Target = (serie4Value * 180) / 100;
    angle5Target = (serie5Value * 180) / 100;
    angle6Target = (serie6Value * 180) / 100;

    // Update text buffers
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d%%", serie1Value);
    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d%%", serie2Value);
    Unicode::snprintf(serie3PercentageBuffer, SERIE3PERCENTAGE_SIZE, "%d%%", serie3Value);
    Unicode::snprintf(serie4PercentageBuffer, SERIE4PERCENTAGE_SIZE, "%d%%", serie4Value);
    Unicode::snprintf(serie5PercentageBuffer, SERIE5PERCENTAGE_SIZE, "%d%%", serie5Value);
    Unicode::snprintf(serie6PercentageBuffer, SERIE6PERCENTAGE_SIZE, "%d%%", serie6Value);

    // Start with radius 0 and trigger animation
    serie1.setRadius(0);
    serie2.setRadius(0);
    serie3.setRadius(0);
    serie4.setRadius(0);
    serie5.setRadius(0);
    serie6.setRadius(0);

    currentAnimation = DRAW_PIECHART;
}


void SemiCirclePieChartView::tearDownScreen()
{
    SemiCirclePieChartViewBase::tearDownScreen();
}

void SemiCirclePieChartView::handleTickEvent()
{
    // Call this every frame to run animations
    if (currentAnimation == DRAW_PIECHART)
    {
        drawPieChartAnimation();
        drawPieChartAnimation();  // Call twice for faster animation
    }
}


void SemiCirclePieChartView::updateQuarterData()
{
    // Determine which radio button is selected
    if (radioButtonQ1.getSelected())
    {
        // Q1: 6 values totaling 100%
        updatePieChart(15, 20, 25, 10, 18, 12);
    }
    else if (radioButtonQ2.getSelected())
    {
        // Q2: Different distribution
        updatePieChart(18, 15, 22, 12, 20, 13);
    }
    else if (radioButtonQ3.getSelected())
    {
        // Q3: Another distribution
        updatePieChart(12, 25, 18, 15, 16, 14);
    }
    else if (radioButtonQ4.getSelected())
    {
        // Q4: Final distribution
        updatePieChart(20, 18, 15, 20, 12, 15);
    }
    //When changing quarters, show all slices expanded with percentages
    if (!allSlicesExpanded)
    {
        toggleAllSlices();  // Expand all to show new data
    }
}

void SemiCirclePieChartView::updatePieChart(int s1, int s2, int s3, int s4, int s5, int s6)
{
    // Store new percentage values
    serie1Value = s1;
    serie2Value = s2;
    serie3Value = s3;
    serie4Value = s4;
    serie5Value = s5;
    serie6Value = s6;

    const int START_ANGLE = 270;

    // Calculate individual slice widths
    int angle1 = (serie1Value * 180) / 100;
    int angle2 = (serie2Value * 180) / 100;
    int angle3 = (serie3Value * 180) / 100;
    int angle4 = (serie4Value * 180) / 100;
    int angle5 = (serie5Value * 180) / 100;
    int angle6 = (serie6Value * 180) / 100;

    // Calculate START positions (cumulative)
    int start1 = START_ANGLE;
    int start2 = start1 + angle1;
    int start3 = start2 + angle2;
    int start4 = start3 + angle3;
    int start5 = start4 + angle4;
    int start6 = start5 + angle5;

    // Set arcs: each slice from its start to its end
    serie1.setArc(start1, start1 + angle1);
    serie2.setArc(start2, start2 + angle2);
    serie3.setArc(start3, start3 + angle3);
    serie4.setArc(start4, start4 + angle4);
    serie5.setArc(start5, start5 + angle5);
    serie6.setArc(start6, start6 + angle6);

    // Reset all selections and move slices back to center
    if (serie1Selected)
    {
        serie1Selected = false;
        serie1Percentage.setVisible(false);
        moveSlice(serie1, start1, start1 + angle1, false);
    }

    if (serie2Selected)
    {
        serie2Selected = false;
        serie2Percentage.setVisible(false);
        moveSlice(serie2, start2, start2 + angle2, false);
    }

    if (serie3Selected)
    {
        serie3Selected = false;
        serie3Percentage.setVisible(false);
        moveSlice(serie3, start3, start3 + angle3, false);
    }

    if (serie4Selected)
    {
        serie4Selected = false;
        serie4Percentage.setVisible(false);
        moveSlice(serie4, start4, start4 + angle4, false);
    }

    if (serie5Selected)
    {
        serie5Selected = false;
        serie5Percentage.setVisible(false);
        moveSlice(serie5, start5, start5 + angle5, false);
    }

    if (serie6Selected)
    {
        serie6Selected = false;
        serie6Percentage.setVisible(false);
        moveSlice(serie6, start6, start6 + angle6, false);
    }

    // Update text buffers with new values
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d%%", serie1Value);
    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d%%", serie2Value);
    Unicode::snprintf(serie3PercentageBuffer, SERIE3PERCENTAGE_SIZE, "%d%%", serie3Value);
    Unicode::snprintf(serie4PercentageBuffer, SERIE4PERCENTAGE_SIZE, "%d%%", serie4Value);
    Unicode::snprintf(serie5PercentageBuffer, SERIE5PERCENTAGE_SIZE, "%d%%", serie5Value);
    Unicode::snprintf(serie6PercentageBuffer, SERIE6PERCENTAGE_SIZE, "%d%%", serie6Value);

    // Redraw everything
    pieChartContainer.invalidate();
}


void SemiCirclePieChartView::pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt)
{
    if (evt.getType() != ClickEvent::RELEASED)
    {
        return;
    }

    int16_t clickX = evt.getX();
    int16_t clickY = evt.getY();

    const int16_t centerX = 120;
    const int16_t centerY = 120;
    const int16_t innerRadius = 25;

    int16_t deltaX = clickX - centerX;
    int16_t deltaY = clickY - centerY;
    int distanceSquared = (deltaX * deltaX) + (deltaY * deltaY);
    int innerRadiusSquared = innerRadius * innerRadius;

    // If clicked in center, toggle ALL slices
    if (distanceSquared <= innerRadiusSquared)
    {
        toggleAllSlices();
        return;
    }

    int clickedSlice = getClickedSlice(clickX, clickY);

    const int START_ANGLE = 270;

    // Calculate individual slice widths
    int angle1 = (serie1Value * 180) / 100;
    int angle2 = (serie2Value * 180) / 100;
    int angle3 = (serie3Value * 180) / 100;
    int angle4 = (serie4Value * 180) / 100;
    int angle5 = (serie5Value * 180) / 100;
    int angle6 = (serie6Value * 180) / 100;

    // Calculate start positions
    int start1 = START_ANGLE;
    int start2 = start1 + angle1;
    int start3 = start2 + angle2;
    int start4 = start3 + angle3;
    int start5 = start4 + angle4;
    int start6 = start5 + angle5;

    if (clickedSlice == 1)
    {
        serie1Selected = !serie1Selected;
        serie1Percentage.setVisible(serie1Selected);
        serie1Percentage.invalidate();
        moveSlice(serie1, start1, start1 + angle1, serie1Selected);
    }
    else if (clickedSlice == 2)
    {
        serie2Selected = !serie2Selected;
        serie2Percentage.setVisible(serie2Selected);
        serie2Percentage.invalidate();
        moveSlice(serie2, start2, start2 + angle2, serie2Selected);
    }
    else if (clickedSlice == 3)
    {
        serie3Selected = !serie3Selected;
        serie3Percentage.setVisible(serie3Selected);
        serie3Percentage.invalidate();
        moveSlice(serie3, start3, start3 + angle3, serie3Selected);
    }
    else if (clickedSlice == 4)
    {
        serie4Selected = !serie4Selected;
        serie4Percentage.setVisible(serie4Selected);
        serie4Percentage.invalidate();
        moveSlice(serie4, start4, start4 + angle4, serie4Selected);
    }
    else if (clickedSlice == 5)
    {
        serie5Selected = !serie5Selected;
        serie5Percentage.setVisible(serie5Selected);
        serie5Percentage.invalidate();
        moveSlice(serie5, start5, start5 + angle5, serie5Selected);
    }
    else if (clickedSlice == 6)
    {
        serie6Selected = !serie6Selected;
        serie6Percentage.setVisible(serie6Selected);
        serie6Percentage.invalidate();
        moveSlice(serie6, start6, start6 + angle6, serie6Selected);
    }
}

int SemiCirclePieChartView::getClickedSlice(int16_t clickX, int16_t clickY)
{
    const int16_t centerX = 120;
    const int16_t centerY = 120;
    const int16_t radius = 60;

    int16_t deltaX = clickX - centerX;
    int16_t deltaY = clickY - centerY;
    int distanceSquared = (deltaX * deltaX) + (deltaY * deltaY);
    int radiusSquared = radius * radius;

    if (distanceSquared > radiusSquared)
    {
        return 0;
    }

    int angleInDegrees = CWRUtil::angle(deltaX, deltaY);

    const int START_ANGLE = 270;

    // Reject angles between 90° and 270° (bottom half)
    if (angleInDegrees > 90 && angleInDegrees < 270)
    {
        return 0;  // Outside semicircle range
    }
    // Convert 270°-360° range to 270°-360°, and 0°-90° range to 360°-450°

    int normalizedAngle = angleInDegrees;
    if (angleInDegrees < 90)
    {
        normalizedAngle = angleInDegrees + 360;  // 0°-90° becomes 360°-450°
    }

    // Calculate individual slice widths
    int angle1 = (serie1Value * 180) / 100;
    int angle2 = (serie2Value * 180) / 100;
    int angle3 = (serie3Value * 180) / 100;
    int angle4 = (serie4Value * 180) / 100;
    int angle5 = (serie5Value * 180) / 100;

    // Calculate END positions (cumulative)
    int end1 = START_ANGLE + angle1;
    int end2 = end1 + angle2;
    int end3 = end2 + angle3;
    int end4 = end3 + angle4;
    int end5 = end4 + angle5;
    int end6 = 450;

    // Determine which slice was clicked (using normalized angle)
    if (normalizedAngle >= START_ANGLE && normalizedAngle <= end1)
    {
        return 1;
    }
    else if (normalizedAngle > end1 && normalizedAngle <= end2)
    {
        return 2;
    }
    else if (normalizedAngle > end2 && normalizedAngle <= end3)
    {
        return 3;
    }
    else if (normalizedAngle > end3 && normalizedAngle <= end4)
    {
        return 4;
    }
    else if (normalizedAngle > end4 && normalizedAngle <= end5)
    {
        return 5;
    }
    else if (normalizedAngle > end5 && normalizedAngle <= end6)
    {
        return 6;
    }

    return 0;  // ✅ FIXED: Added missing return statement
}


void SemiCirclePieChartView::moveSlice(touchgfx::Circle& slice, int arcStart, int arcEnd, bool moveOut)
{
    if (moveOut)
    {
        int arcAngle = arcEnd - arcStart;
        int middleAngle = arcStart + (arcAngle / 2);

        int offsetX = (CWRUtil::toQ5(15) * CWRUtil::sine(middleAngle)).to<int>();
        int offsetY = -(CWRUtil::toQ5(15) * CWRUtil::cosine(middleAngle)).to<int>();

        slice.setCenter(originalCenterX + offsetX, originalCenterY + offsetY);
    }
    else
    {
        slice.setCenter(originalCenterX, originalCenterY);
    }

    pieChartContainer.invalidate();
}

void SemiCirclePieChartView::toggleAllSlices()
{
    const int START_ANGLE = 270;

    // Calculate individual slice widths
    int angle1 = (serie1Value * 180) / 100;
    int angle2 = (serie2Value * 180) / 100;
    int angle3 = (serie3Value * 180) / 100;
    int angle4 = (serie4Value * 180) / 100;
    int angle5 = (serie5Value * 180) / 100;
    int angle6 = (serie6Value * 180) / 100;

    // Calculate start positions
    int start1 = START_ANGLE;
    int start2 = start1 + angle1;
    int start3 = start2 + angle2;
    int start4 = start3 + angle3;
    int start5 = start4 + angle4;
    int start6 = start5 + angle5;

    // Toggle the state
    allSlicesExpanded = !allSlicesExpanded;

    // Apply to all slices
    serie1Selected = allSlicesExpanded;
    serie2Selected = allSlicesExpanded;
    serie3Selected = allSlicesExpanded;
    serie4Selected = allSlicesExpanded;
    serie5Selected = allSlicesExpanded;
    serie6Selected = allSlicesExpanded;

    // Show/hide all percentages
    serie1Percentage.setVisible(allSlicesExpanded);
    serie2Percentage.setVisible(allSlicesExpanded);
    serie3Percentage.setVisible(allSlicesExpanded);
    serie4Percentage.setVisible(allSlicesExpanded);
    serie5Percentage.setVisible(allSlicesExpanded);
    serie6Percentage.setVisible(allSlicesExpanded);

    // Move all slices
    moveSlice(serie1, start1, start1 + angle1, allSlicesExpanded);
    moveSlice(serie2, start2, start2 + angle2, allSlicesExpanded);
    moveSlice(serie3, start3, start3 + angle3, allSlicesExpanded);
    moveSlice(serie4, start4, start4 + angle4, allSlicesExpanded);
    moveSlice(serie5, start5, start5 + angle5, allSlicesExpanded);
    moveSlice(serie6, start6, start6 + angle6, allSlicesExpanded);

    // Invalidate text areas
    serie1Percentage.invalidate();
    serie2Percentage.invalidate();
    serie3Percentage.invalidate();
    serie4Percentage.invalidate();
    serie5Percentage.invalidate();
    serie6Percentage.invalidate();
}

void SemiCirclePieChartView::drawPieChartAnimation()
{
    bool animationComplete = true;

    // Phase 1: Grow radius from 0 to 60
    if (radiusAnimation < 60)
    {
        radiusAnimation += 2;

        serie1.setRadius(radiusAnimation);
        serie2.setRadius(radiusAnimation);
        serie3.setRadius(radiusAnimation);
        serie4.setRadius(radiusAnimation);
        serie5.setRadius(radiusAnimation);
        serie6.setRadius(radiusAnimation);

        animationComplete = false;
    }

    // Phase 2: Rotate starting angle from 180° to 360°
    const int ANIM_START = 270;
    const int ANIM_END = 450;

    if (radiusAnimation >= 60 && angleStartAnimation < ANIM_END)
        {
            angleStartAnimation += 10;
            if (angleStartAnimation > ANIM_END) angleStartAnimation = ANIM_END;
            animationComplete = false;
        }

        // Phase 3: Draw each slice progressively
        if (angleStartAnimation >= ANIM_START)
    {
        // Increment each angle toward its target
        for (int i = 0; i < 4; i++)
        {
            if (angle1Animation < angle1Target)
            {
                angle1Animation++;
                animationComplete = false;
            }
            if (angle2Animation < angle2Target)
            {
                angle2Animation++;
                animationComplete = false;
            }
            if (angle3Animation < angle3Target)
            {
                angle3Animation++;
                animationComplete = false;
            }
            if (angle4Animation < angle4Target)
            {
                angle4Animation++;
                animationComplete = false;
            }
            if (angle5Animation < angle5Target)
            {
                angle5Animation++;
                animationComplete = false;
            }
            if (angle6Animation < angle6Target)
            {
                angle6Animation++;
                animationComplete = false;
            }
        }

        // ✅ FIXED: Calculate start positions for animation
        int start1 = angleStartAnimation;
        int start2 = start1 + angle1Animation;
        int start3 = start2 + angle2Animation;
        int start4 = start3 + angle3Animation;
        int start5 = start4 + angle4Animation;
        int start6 = start5 + angle5Animation;

        // Update arcs with animated angles
        serie1.setArc(start1, start1 + angle1Animation);
        serie2.setArc(start2, start2 + angle2Animation);
        serie3.setArc(start3, start3 + angle3Animation);
        serie4.setArc(start4, start4 + angle4Animation);
        serie5.setArc(start5, start5 + angle5Animation);
        serie6.setArc(start6, start6 + angle6Animation);
    }

    // When animation is complete
    if (animationComplete)
    {
        // ✅ FIXED: Set final arcs using individual slice widths
        const int START_ANGLE = 270;

        // Recalculate from current values
        int angle1 = (serie1Value * 180) / 100;
        int angle2 = (serie2Value * 180) / 100;
        int angle3 = (serie3Value * 180) / 100;
        int angle4 = (serie4Value * 180) / 100;
        int angle5 = (serie5Value * 180) / 100;
        int angle6 = (serie6Value * 180) / 100;

        // Calculate start positions
        int start1 = START_ANGLE;
        int start2 = start1 + angle1;
        int start3 = start2 + angle2;
        int start4 = start3 + angle3;
        int start5 = start4 + angle4;
        int start6 = start5 + angle5;

        serie1.setArc(start1, start1 + angle1);
        serie2.setArc(start2, start2 + angle2);
        serie3.setArc(start3, start3 + angle3);
        serie4.setArc(start4, start4 + angle4);
        serie5.setArc(start5, start5 + angle5);
        serie6.setArc(start6, start6 + angle6);

        // Stop animation
        currentAnimation = NO_ANIMATION;
    }

    // Redraw
    pieChartContainer.invalidate();
}
