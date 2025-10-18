#include <gui/containers/ThreeWayProgressCustomContainer.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <gui/common/Utils.hpp>

ThreeWayProgressCustomContainer::ThreeWayProgressCustomContainer() : progressEndedCounter(0),
    circularProgressEndedCallback(this, &ThreeWayProgressCustomContainer::circularProgressEndedHandler)
{

}

void ThreeWayProgressCustomContainer::initialize()
{
    setCircularIconsInactive();
    setCircleProgressesVisiblity(false);
    scanButton.setTouchable(false);

    circleProgressTop.setValueUpdatedAction(circularProgressEndedCallback);
    circleProgressRight.setValueUpdatedAction(circularProgressEndedCallback);
    circleProgressLeft.setValueUpdatedAction(circularProgressEndedCallback);

    ThreeWayProgressCustomContainerBase::initialize();
}

void ThreeWayProgressCustomContainer::setCircularIconsInactive()
{
    binCircularIcon.setIconImage(touchgfx::Bitmap(BITMAP_SMALL_CIRCLE_BIN_ICON_INACTIVE_ID));
    binCircularIcon.invalidate();

    folderCircularIcon.setIconImage(touchgfx::Bitmap(BITMAP_SMALL_CIRCLE_FOLDER_ICON_INACTIVE_ID));
    folderCircularIcon.invalidate();

    fileCircularIcon.setIconImage(touchgfx::Bitmap(BITMAP_SMALL_CIRCLE_PAPERS_ICON_INACTIVE_ID));
    fileCircularIcon.invalidate();
}

void ThreeWayProgressCustomContainer::setCircleProgressesVisiblity(bool visibility)
{
    circleProgressTop.setVisible(visibility);
    circleProgressLeft.setVisible(visibility);
    circleProgressRight.setVisible(visibility);
}

void ThreeWayProgressCustomContainer::startShowingProgress()
{

    setCircleProgressesVisiblity(true);
    setCirlceProgressesValues(0);

    setCircularIconsActive();

    scanButton.setTouchable(false);
    scanButton.setLabelText(touchgfx::TypedText(T_THREE_WAY_PROGRESS_BAR_SCANNING));
    scanButton.invalidate();

    updateCircleProgressesValues();

}

void ThreeWayProgressCustomContainer::setCirlceProgressesValues(int value)
{
    circleProgressTop.setValue(value);
    circleProgressLeft.setValue(value);
    circleProgressRight.setValue(value);
}

void ThreeWayProgressCustomContainer::updateCircleProgressesValues()
{
    int randomDuration = Utils::randomNumberBetween(0, 99);
    int randomRange = 101 - randomDuration;

    randomDuration += Utils::randomNumberBetween(0, randomRange);
    circleProgressTop.setEasingEquation(getRandomEasingEquation());
    circleProgressTop.updateValue(100, randomDuration);

    randomDuration += Utils::randomNumberBetween(0, randomRange);
    circleProgressRight.setEasingEquation(getRandomEasingEquation());
    circleProgressRight.updateValue(100, randomDuration);

    randomDuration += Utils::randomNumberBetween(0, randomRange);
    circleProgressLeft.setEasingEquation(getRandomEasingEquation());
    circleProgressLeft.updateValue(100, randomDuration);
}

touchgfx::EasingEquation ThreeWayProgressCustomContainer::getRandomEasingEquation()
{
    switch (Utils::randomNumberBetween(0, 6))
    {
    case 0:
        return EasingEquations::sineEaseIn;
    case 1:
        return EasingEquations::linearEaseInOut;
    case 2:
        return EasingEquations::quadEaseIn;
    case 3:
        return EasingEquations::cubicEaseOut;
    case 4:
        return EasingEquations::cubicEaseInOut;
    case 5:
        return EasingEquations::linearEaseNone;
    default:
        return EasingEquations::sineEaseIn;
    }
}

void ThreeWayProgressCustomContainer::resetIconsAndProgression()
{

    resetCircleProgresses();
    setCircularIconsInactive();

    scanButton.setLabelText(touchgfx::TypedText(T_THREE_WAY_PROGRESS_BAR_SCAN));
    scanButton.invalidate();

    progressEndedCounter = 0;

    //Just using the coordinates from the Designer
    binCircularIcon.setXY(89, 66);
    folderCircularIcon.setXY(71, 101);
    fileCircularIcon.setXY(115, 101);
}

void ThreeWayProgressCustomContainer::resetCircleProgresses()
{
    setCircleProgressesVisiblity(false);

    circleProgressLeft.updateValue(0, 1);
    circleProgressRight.updateValue(0, 1);
    circleProgressTop.updateValue(0, 1);
}

void ThreeWayProgressCustomContainer::emitCircularIconsMovingAnimationCallback()
{

    //to signal CircularCustomContainer to start moving the Circle Icons
    binCircularIcon.emitStartAnimationCallback();
    folderCircularIcon.emitStartAnimationCallback();
    fileCircularIcon.emitStartAnimationCallback();
}

void ThreeWayProgressCustomContainer::setCircularIconsActive()
{

    binCircularIcon.setIconImage(touchgfx::Bitmap(BITMAP_SMALL_CIRCLE_BIN_ICON_ACTIVE_ID));
    binCircularIcon.invalidate();

    folderCircularIcon.setIconImage(touchgfx::Bitmap(BITMAP_SMALL_CIRCLE_FOLDER_ICON_ACTIVE_ID));
    folderCircularIcon.invalidate();

    fileCircularIcon.setIconImage(touchgfx::Bitmap(BITMAP_SMALL_CIRCLE_PAPERS_ICON_ACTIVE_ID));
    fileCircularIcon.invalidate();

}

void ThreeWayProgressCustomContainer::circularProgressEndedHandler(const AbstractProgressIndicator& as)
{
    progressEndedCounter++;

    if (progressEndedCounter == 3)
    {
        setCircularIconsInactive();

        scanButton.setLabelText(touchgfx::TypedText(T_THREE_WAY_PROGRESS_BAR_SCAN));
        scanButton.invalidate();
        scanButton.setTouchable(true);

        if (circleProgressLeft.getValue() != 0)
        {
            //If progresses were reset, do not emit
            ThreeWayProgressCustomContainerBase::emitAllProgressesDoneCallback();
        }

        progressEndedCounter = 0;
    }
}

void ThreeWayProgressCustomContainer::updatePercentageLables()
{

    //Will be called from GaugeView
    binCircularIcon.changePercentage(circleProgressTop.getValue());
    folderCircularIcon.changePercentage(circleProgressLeft.getValue());
    fileCircularIcon.changePercentage(circleProgressRight.getValue());
}
