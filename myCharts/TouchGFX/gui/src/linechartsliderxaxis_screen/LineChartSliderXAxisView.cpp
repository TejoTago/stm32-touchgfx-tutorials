//#include <gui/linechartsliderxaxis_screen/LineChartSliderXAxisView.hpp>
//#include <cstdlib>  // rand(), srand()
////#include <ctime>    // time()
//
//LineChartSliderXAxisView::LineChartSliderXAxisView()
//    : tickCounter(0), lastValue(80)
//{
//	srand(tickCounter);
////	srand(static_cast<unsigned int>(time(NULL)));
////	srand(12345);
//}
//
//void LineChartSliderXAxisView::setupScreen()
//{
//    LineChartSliderXAxisViewBase::setupScreen();
////    updateLineChart();
//}
//
//void LineChartSliderXAxisView::tearDownScreen()
//{
//    LineChartSliderXAxisViewBase::tearDownScreen();
//}
//
//void LineChartSliderXAxisView::handleTickEvent()
//{
//    tickCounter++;
//    if (tickCounter % 6 == 0)
//    {
//        // Generate the new value
//        int16_t newValue = generateDeltaValue(lastValue, 15, 150, 5);
//
//        // Add it to the chart
//        lineChart.addDataPoint(newValue);
//        lineChart.invalidate();
//
//        // Update the text area to show the current value
//        Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", newValue);
//        textArea1.invalidate();
//
//    }
//}
//
//int16_t LineChartSliderXAxisView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
//{
//    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
//    int16_t newValue = lastValue + delta;
//
//    // Clamp to min/max
//    if (newValue < min) newValue = min;
//    if (newValue > max) newValue = max;
//
//    lastValue = newValue;
//    return newValue;
//}
//
//void LineChartSliderXAxisView::setXAxisRange(int visiblePoints)
//{
//    lineChart.setXAxisRange(visiblePoints); // This sets how many points are visible
//    lineChartMajorXAxisLabel.setInterval(visiblePoints / 5); // Optional: adjust label spacing
//    lineChart.invalidate();
//}
//
//
//
//
