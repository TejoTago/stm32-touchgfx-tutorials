#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // Initialize with Q1 data since Q1 is selected by default
    updateColumnHeights(1);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::selectQuarter()
{
    // Determine which quarter button is currently selected
    int selectedQuarter = 0;

    if (Q1.getSelected())
        selectedQuarter = 1;
    else if (Q2.getSelected())
        selectedQuarter = 2;
    else if (Q3.getSelected())
        selectedQuarter = 3;
    else if (Q4.getSelected())
        selectedQuarter = 4;

    // Update the column heights based on selected quarter
    updateColumnHeights(selectedQuarter);
}

void Screen1View::updateColumnHeights(int quarter)
{
    // Define expenditure data for each quarter
    // Remember: base is at Y=170, so smaller Y values = taller bars
    // Format for each quarter: [col1_top, col2_top, col3_top, col4_top]

    float quarterData[5][4] = {
        {85.0f,  85.0f,  85.0f,  85.0f},    // Index 0: unused
        {15.0f,  120.0f, 50.0f,  140.0f},   // Q1
        {130.0f, 25.0f,  145.0f, 60.0f},    // Q2
        {40.0f,  85.0f,  10.0f,  100.0f},   // Q3
        {155.0f, 45.0f,  125.0f, 20.0f}     // Q4
    };

    // Validate quarter is in valid range
    if (quarter < 1 || quarter > 4)
        return;

    // Update col1 points in member variable
    col1Points[0] = { 0.0f, quarterData[quarter][0] };   // Top left
    col1Points[1] = { 40.0f, quarterData[quarter][0] };  // Top right
    col1Points[2] = { 40.0f, 170.0f };                   // Bottom right
    col1Points[3] = { 0.0f, 170.0f };                    // Bottom left
    col1.setShape(col1Points);
    //col1.invalidate();

    // Update col2 points in member variable
    col2Points[0] = { 0.0f, quarterData[quarter][1] };
    col2Points[1] = { 40.0f, quarterData[quarter][1] };
    col2Points[2] = { 40.0f, 170.0f };
    col2Points[3] = { 0.0f, 170.0f };
    col2.setShape(col2Points);
    //col2.invalidate();

    // Update col3 points in member variable
    col3Points[0] = { 0.0f, quarterData[quarter][2] };
    col3Points[1] = { 40.0f, quarterData[quarter][2] };
    col3Points[2] = { 40.0f, 170.0f };
    col3Points[3] = { 0.0f, 170.0f };
    col3.setShape(col3Points);
    //col3.invalidate();

    // Update col4 points in member variable
    col4Points[0] = { 0.0f, quarterData[quarter][3] };
    col4Points[1] = { 40.0f, quarterData[quarter][3] };
    col4Points[2] = { 40.0f, 170.0f };
    col4Points[3] = { 0.0f, 170.0f };
    col4.setShape(col4Points);
    //col4.invalidate();

    columns.invalidate();
}
