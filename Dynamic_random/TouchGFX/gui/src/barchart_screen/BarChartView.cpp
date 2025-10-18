#include <gui/barchart_screen/BarChartView.hpp>
//#include <cstdio>

BarChartView::BarChartView()
//    : radioSelectedCallback(this, &BarChartView::onRadioSelected)
{
}

void BarChartView::setupScreen()
{
    BarChartViewBase::setupScreen();

    // Optional: trigger initial update
    //fQuarters();
    tickCounter = 0;
    currentSetIndex = 0;

}


void BarChartView::tearDownScreen()
{
    BarChartViewBase::tearDownScreen();
}

void BarChartView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 180 == 0) // Every 3 seconds
    {
        updateBars(currentSetIndex);
        currentSetIndex = (currentSetIndex + 1) % 4; // Cycle through 0–3
    }
}


void BarChartView::updateBars(int setIndex)
{
    const int heightSets[4][4] = {
        {40, 60, 80, 100},  // Set 0
        {20, 30, 40, 50},   // Set 1
        {50, 50, 60, 70},   // Set 2
        {70, 40, 20, 90}    // Set 3
    };

    const int barWidth = 20;
    const int maxBarHeight = 100;
    const int baseY = 35;

    for (int i = 0; i < 4; ++i)
    {
        int h = heightSets[setIndex][i];

        // Shape grows upward from bottom
        touchgfx::AbstractShape::ShapePoint<float> barPoints[4] = {
            {0.0f, static_cast<float>(maxBarHeight - h)}, // top left
            {static_cast<float>(barWidth), static_cast<float>(maxBarHeight - h)}, // top right
            {static_cast<float>(barWidth), static_cast<float>(maxBarHeight)}, // bottom right
            {0.0f, static_cast<float>(maxBarHeight)} // bottom left
        };

        switch (i)
        {
            case 0:
                bar1.setY(baseY);
                bar1.setShape(barPoints);
                bar1.invalidate();
                break;
            case 1:
                bar2.setY(baseY);
                bar2.setShape(barPoints);
                bar2.invalidate();
                break;
            case 2:
                bar3.setY(baseY);
                bar3.setShape(barPoints);
                bar3.invalidate();
                break;
            case 3:
                bar4.setY(baseY);
                bar4.setShape(barPoints);
                bar4.invalidate();
                break;
        }
    }
}

//    for (int i = 0; i < 4; ++i)
//    {
//        int h = heights[i];
//        int adjustedY = baseY + (maxBarHeight - h);
//
//        touchgfx::AbstractShape::ShapePoint<float> barPoints[4] = {
//            {0.0f, 0.0f},
//            {static_cast<float>(barWidth), 0.0f},
//            {static_cast<float>(barWidth), static_cast<float>(h)},
//            {0.0f, static_cast<float>(h)}
//        };
//
//        switch (i)
//        {
//            case 0:
//                bar1.setOrigin(0.0f, 0.0f); // Ensure origin is top-left
//                bar1.setY(adjustedY);
//                bar1.setShape(barPoints);
//                bar1.invalidate();
//                break;
//            case 1:
//                bar2.setOrigin(0.0f, 0.0f);
//                bar2.setY(adjustedY);
//                bar2.setShape(barPoints);
//                bar2.invalidate();
//                break;
//            case 2:
//                bar3.setOrigin(0.0f, 0.0f);
//                bar3.setY(adjustedY);
//                bar3.setShape(barPoints);
//                bar3.invalidate();
//                break;
//            case 3:
//                bar4.setOrigin(0.0f, 0.0f);
//                bar4.setY(adjustedY);
//                bar4.setShape(barPoints);
//                bar4.invalidate();
//                break;
//        }
//    }
//}
//void BarChartView::fQuarters()
//{
//    int selectedIndex = 0;
//
//    if (radioButtonQ1.getSelected()) selectedIndex = 0;
//    else if (radioButtonQ2.getSelected()) selectedIndex = 1;
//    else if (radioButtonQ3.getSelected()) selectedIndex = 2;
//    else if (radioButtonQ4.getSelected()) selectedIndex = 3;
//    printf("Selected quarter: Q%d\n", selectedIndex + 1);
//
//    // Heights for each quarter: [gas, electricity, water, multimedia]
//    const int heights[4][4] = {
//        {40, 60, 80, 100},  // Q1
//        {100, 80, 60, 40},  // Q2
//        {70, 70, 70, 70},   // Q3
//        {20, 40, 60, 80}    // Q4
//    };
//
//    const int barWidth = 20;
//    const int maxBarHeight = 80;
//    const int baseY = 35; // original Y position of bars
//
//    for (int i = 0; i < 4; ++i)
//    {
//        int h = heights[selectedIndex][i];
//        int adjustedY = baseY + (maxBarHeight - h); // shift upward to align top
//
//        touchgfx::AbstractShape::ShapePoint<float> barPoints[4] = {
//            {0.0f, 0.0f},                          // top left
//            {static_cast<float>(barWidth), 0.0f}, // top right
//            {static_cast<float>(barWidth), static_cast<float>(h)}, // bottom right
//            {0.0f, static_cast<float>(h)}         // bottom left
//        };
//
//        switch (i)
//        {
//            case 0:
//                bar1.setY(adjustedY);
//                bar1.setShape(barPoints);
//                bar1.invalidate();
//                break;
//            case 1:
//                bar2.setY(adjustedY);
//                bar2.setShape(barPoints);
//                bar2.invalidate();
//                break;
//            case 2:
//                bar3.setY(adjustedY);
//                bar3.setShape(barPoints);
//                bar3.invalidate();
//                break;
//            case 3:
//                bar4.setY(adjustedY);
//                bar4.setShape(barPoints);
//                bar4.invalidate();
//                break;
//        }
//    }
//}
