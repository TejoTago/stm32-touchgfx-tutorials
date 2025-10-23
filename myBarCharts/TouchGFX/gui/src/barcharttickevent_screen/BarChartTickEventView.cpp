#include <gui/barcharttickevent_screen/BarChartTickEventView.hpp>
#include <stdlib.h>  // For rand() and srand()
//#include <time.h>    // For time() - works in simulator


BarChartTickEventView::BarChartTickEventView() :
    tickCounter(0),
    updateCounter(0),
    animationActive(false)
{
}

void BarChartTickEventView::setupScreen()
{
    BarChartTickEventViewBase::setupScreen();

    // Seed random number generator with current time
    srand(12345);

    // Start the animation automatically when screen loads
    animationActive = true;
    tickCounter = 0;
    updateCounter = 0;

    // Generate initial random values
    updateColumnHeightsRandom();
    analogSeconds = analogClock1.getCurrentSecond();
}

void BarChartTickEventView::tearDownScreen()
{
    BarChartTickEventViewBase::tearDownScreen();
}

void BarChartTickEventView::handleTickEvent()
{
    // Check if animation is active
    if (!animationActive)
        return;

    tickCounter++;

    // TouchGFX typically runs at 60 FPS, so 60 ticks = 1 second
    // For 2 second intervals: 120 ticks
    if (tickCounter >= 120)
    {
        tickCounter = 0;
        updateCounter++;

        // Update with random values
        updateColumnHeightsRandom();

        // Stop after 12 seconds (6 updates x 2 seconds each)
        if (updateCounter >= 6)
        {
            animationActive = false;
            updateCounter = 0;
        }
    }
    if (tickCounter % 60 == 0)
     {
         if (++analogSeconds >= 60)
         {
             analogSeconds = 0;
         }
         // Update the clocks
         analogClock1.setTime24Hour(0, 0,analogSeconds);
     }
}

void BarChartTickEventView::updateColumnHeightsRandom()
{
    // Generate random Y-coordinates for each column
    // Range: 10.0f to 160.0f (taller to shorter bars)
    // This creates heights between 10 and 160 pixels

    float randomCol1 = 10.0f + (rand() % 151);  // 10 to 160
    float randomCol2 = 10.0f + (rand() % 151);
    float randomCol3 = 10.0f + (rand() % 151);
    float randomCol4 = 10.0f + (rand() % 151);

    // Update col1 points with random height
    col1Points[0] = { 0.0f, randomCol1 };
    col1Points[1] = { 40.0f, randomCol1 };
    col1Points[2] = { 40.0f, 170.0f };
    col1Points[3] = { 0.0f, 170.0f };
    col1.setShape(col1Points);

    // Update col2 points with random height
    col2Points[0] = { 0.0f, randomCol2 };
    col2Points[1] = { 40.0f, randomCol2 };
    col2Points[2] = { 40.0f, 170.0f };
    col2Points[3] = { 0.0f, 170.0f };
    col2.setShape(col2Points);

    // Update col3 points with random height
    col3Points[0] = { 0.0f, randomCol3 };
    col3Points[1] = { 40.0f, randomCol3 };
    col3Points[2] = { 40.0f, 170.0f };
    col3Points[3] = { 0.0f, 170.0f };
    col3.setShape(col3Points);

    // Update col4 points with random height
    col4Points[0] = { 0.0f, randomCol4 };
    col4Points[1] = { 40.0f, randomCol4 };
    col4Points[2] = { 40.0f, 170.0f };
    col4Points[3] = { 0.0f, 170.0f };
    col4.setShape(col4Points);

    // Single invalidation on the parent container
    columns.invalidate();
}
