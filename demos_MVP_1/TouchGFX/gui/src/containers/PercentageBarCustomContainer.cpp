#include <gui/containers/PercentageBarCustomContainer.hpp>

PercentageBarCustomContainer::PercentageBarCustomContainer()
    : centerOfTheCircleProgress(124),
      percentageBarClickCallback(this, &PercentageBarCustomContainer::clickAction)
{

}

void PercentageBarCustomContainer::initialize()
{
    circleProgress.setClickAction(percentageBarClickCallback);

    PercentageBarCustomContainerBase::initialize();
}

void PercentageBarCustomContainer::clickAction(const CircleProgress& object, const ClickEvent& Event)
{

    if (Event.getType() == ClickEvent::PRESSED)
    {
        updateCircleProgress(Event.getX(), Event.getY(), centerOfTheCircleProgress, centerOfTheCircleProgress);
    }
}

void PercentageBarCustomContainer::updateCircleProgress(int newX, int newY, int centerX, int centerY)
{

    int currentAngleOfClick = CWRUtil::angle<int>(newX - centerX, newY - centerY);

    if (currentAngleOfClick >= 245)
    {
        circleProgress.setValue(currentAngleOfClick - 245);
        percentageTextProgress.setValue(currentAngleOfClick - 245);
    }
    else if (currentAngleOfClick < 115)
    {
        circleProgress.setValue(currentAngleOfClick + 115);
        percentageTextProgress.setValue(currentAngleOfClick + 115);
    }
    else if (currentAngleOfClick >= 115 && currentAngleOfClick < 180)
    {
        circleProgress.setValue(230);
        percentageTextProgress.setValue(230);
    }
    else if (currentAngleOfClick <= 245 && currentAngleOfClick >= 180)
    {
        circleProgress.setValue(0);
        percentageTextProgress.setValue(0);
    }

}

void PercentageBarCustomContainer::dragEventCalled(const DragEvent& Event)
{
    int centerPossitionOfProgressInContainer_X = centerOfTheCircleProgress + 166;
    int centerPossitionOfProgressInContainer_Y = centerOfTheCircleProgress + 10;

    updateCircleProgress(Event.getNewX(), Event.getNewY(), centerPossitionOfProgressInContainer_X, centerPossitionOfProgressInContainer_Y);
}
