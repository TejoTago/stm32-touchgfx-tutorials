#include <gui/graph_screen/GraphView.hpp>
#include <gui/common/Utils.hpp>

GraphView::GraphView()
    :    pointCounter(0),
         graphX(0),
         graphType(0)
{

}

void GraphView::setupScreen()
{
    GraphViewBase::setupScreen();
    primaryGraphLineSetting.forceState(true);
    primaryGraphDotSetting.forceState(true);
    primaryGraphAreaSetting.forceState(true);
    secondaryGraphLineSetting.forceState(true);
    secondaryGraphDotSetting.forceState(false);
    secondaryGraphAreaSetting.forceState(true);
    updateGraphSettings();
    mcuLoad.setTextColor(Color::getColorFromRGB(0x0, 0x0, 0x0));
}

void GraphView::tearDownScreen()
{
    GraphViewBase::tearDownScreen();
}

void GraphView::updateGraphSettings()
{
    if (primaryGraphLineSetting.getState() == false)
    {
        primaryGraphLine1.setAlpha(0);
    }
    else
    {
        primaryGraphLine1.setAlpha(255);
    }

    if (primaryGraphAreaSetting.getState() == false)
    {
        primaryGraphArea1.setAlpha(0);
    }
    else
    {
        primaryGraphArea1.setAlpha(255);
    }

    if (primaryGraphDotSetting.getState() == false)
    {
        primaryGraphDots1.setAlpha(0);
        primaryGraphDots2.setAlpha(0);
    }
    else
    {
        primaryGraphDots1.setAlpha(255);
        primaryGraphDots2.setAlpha(255);
    }
    primaryGraph.invalidate();

    if (secondaryGraphLineSetting.getState() == false)
    {
        secondaryGraphLine1.setAlpha(0);
    }
    else
    {
        secondaryGraphLine1.setAlpha(255);
    }

    if (secondaryGraphAreaSetting.getState() == false)
    {
        secondaryGraphArea1.setAlpha(0);
    }
    else
    {
        secondaryGraphArea1.setAlpha(255);
    }

    if (secondaryGraphDotSetting.getState() == false)
    {
        secondaryGraphDiamonds2.setAlpha(0);
        secondaryGraphDiamonds1.setAlpha(0);
    }
    else
    {
        secondaryGraphDiamonds2.setAlpha(255);
        secondaryGraphDiamonds1.setAlpha(255);
    }
    secondaryGraph.invalidate();

}

void GraphView::handleTickEvent()
{
    if (pointCounter < 15)
    {
        switch (graphType)
        {
        case 0:
            {
                primaryGraph.addDataPoint(graphX, (int)((CWRUtil::toQ5(150) * CWRUtil::sine(graphX + Utils::randomNumberBetween(-25, 25))).to<int>()) + 200 + Utils::randomNumberBetween(-50, 0));
                secondaryGraph.addDataPoint(graphX, (int)((CWRUtil::toQ5(150) * CWRUtil::sine(graphX + 230)).to<int>()) + 200 + Utils::randomNumberBetween(-50, 0));
                graphX += 15;
                pointCounter++;
                break;
            }
        case 1:
        case 2:
            {
                static int value1;
                static int value2;
                int graph1min = graphType == 1 ? 100 : 10;
                int graph1max = graphType == 1 ? 390 : 390;
                int graph2min = graphType == 1 ? 10 : 10;
                int graph2max = graphType == 1 ? 300 : 390;
                int randomMax = graphType == 1 ? 50 : 100;
                if (graphX == 0)
                {
                    value1 = Utils::randomNumberBetween(graph1min, graph1max - 1);
                    value2 = Utils::randomNumberBetween(graph2min, graph2max - 1);
                    if (graphType == 1 && value1 < value2)
                    {
                        int value0 = value1;
                        value1 = value2;
                        value2 = value0;
                    }
                }
                value1 += Utils::randomNumberBetween(-randomMax, randomMax);
                value2 += Utils::randomNumberBetween(-randomMax, randomMax);
                if (value1 < graph1min)
                {
                    value1 += Utils::randomNumberBetween(randomMax, randomMax * 2 - 1);
                }
                if (value1 > graph1max)
                {
                    value1 -= Utils::randomNumberBetween(randomMax, randomMax * 2 - 1);
                }
                if (value2 < graph2min)
                {
                    value2 += Utils::randomNumberBetween(randomMax, randomMax * 2 - 1);
                }
                if (value2 > graph2max)
                {
                    value2 -= Utils::randomNumberBetween(randomMax, randomMax * 2 - 1);
                }
                if (graphType == 1)
                {
                    if (value1 < value2)
                    {
                        int value0 = value1;
                        value1 = value2;
                        value2 = value0;
                    }
                    if (value1 - value2 < 20)
                    {
                        value1 += 10;
                        value2 -= 10;
                    }
                }
                primaryGraph.addDataPoint(graphX, value1);
                secondaryGraph.addDataPoint(graphX, value2);
                graphX += 15;
                pointCounter++;
                break;
            }
        }
    }
}

void GraphView::clearGraphs()
{
    primaryGraph.clear();
    secondaryGraph.clear();
    primaryGraph.invalidate();

    pointCounter = 0;
    graphX = 0;
    graphType++;
    graphType %= 3;
}

void GraphView::updateProcessorLoad(uint8_t mcuLoadValue)
{
    mcuLoad.updateProcessorLoad(mcuLoadValue);
}
