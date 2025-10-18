#include <gui/customcontrols_screen/CustomControlsView.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <gui/common/Utils.hpp>

CustomControlsView::CustomControlsView() : tickCounter(0), selectedMenuItemIndex(0),
    previousMenuItemIndex(0), scrollWheelAnimateToNewItemCallback(this, &CustomControlsView::showSelectedControler)
{
}

void CustomControlsView::setupScreen()
{
    setMenuUpButtonInactive();

    menuScrollWheel.setTouchable(false);
    menuScrollWheel.setAnimateToCallback(scrollWheelAnimateToNewItemCallback);

    updateGaugeValue();

    CustomControlsViewBase::setupScreen();
}

void CustomControlsView::tearDownScreen()
{

    CustomControlsViewBase::tearDownScreen();
}

void CustomControlsView::menuScrollWheelUpdateItem(MenuIconCustomContainer& item, int16_t itemIndex)
{
    item.setTheIcons(itemIndex);
}

void CustomControlsView::handleTickEvent()
{
    if (gauge.isVisible())
    {
        tickCounter++;
        if (tickCounter >= 90)
        {
            tickCounter = 0;
            updateGaugeValue();
        }
    }

    if (threeWayProgressCustomContainer.isVisible())
    {
        threeWayProgressCustomContainer.updatePercentageLables();
    }

    CustomControlsViewBase::handleTickEvent();
}

void CustomControlsView::updateGaugeValue()
{
    int newValue = Utils::randomNumberBetween(0, 100);
    int differenceBetweenNewValueAndCurrent = abs(gauge.getValue() - newValue);
    int animationDuration = 0;

    if (differenceBetweenNewValueAndCurrent > 40)
    {

        gauge.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
        animationDuration = 25;
    }
    else
    {
        gauge.setEasingEquation(touchgfx::EasingEquations::quadEaseOut);
        animationDuration = 15;
    }

    gauge.updateValue(newValue, animationDuration);
}

void CustomControlsView::scrollMenuUp()
{
    previousMenuItemIndex = selectedMenuItemIndex--;

    if (selectedMenuItemIndex == 0)
    {
        setMenuUpButtonInactive();
    }

    setMenuDownButtonActive();
    menuScrollWheel.animateToItem(selectedMenuItemIndex);

    menuScrollWheel.invalidate();
}

void CustomControlsView::scrollMenuDown()
{
    previousMenuItemIndex = selectedMenuItemIndex++;

    if (selectedMenuItemIndex == 3)
    {
        setMenuDownButtonInactive();
    }

    setMenuUpButtonActive();
    menuScrollWheel.animateToItem(selectedMenuItemIndex);

    menuScrollWheel.invalidate();
}

void CustomControlsView::setMenuUpButtonInactive()
{
    menuUpButton.setBitmaps(touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_UP_INACTIVE_ID),
                            touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_UP_INACTIVE_ID));
    menuUpButton.setTouchable(false);
    menuUpButton.invalidate();
}

void CustomControlsView::setMenuUpButtonActive()
{
    menuUpButton.setBitmaps(touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_UP_ID),
                            touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_UP_PRESSED_ID));
    menuUpButton.setTouchable(true);
    menuUpButton.invalidate();
}

void CustomControlsView::setMenuDownButtonInactive()
{
    menuDownButton.setBitmaps(touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_DOWN_INACTIVE_ID),
                              touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_DOWN_INACTIVE_ID));
    menuDownButton.setTouchable(false);
    menuDownButton.invalidate();
}

void CustomControlsView::setMenuDownButtonActive()
{
    menuDownButton.setBitmaps(touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_DOWN_ID),
                              touchgfx::Bitmap(BITMAP_CONTROL_MENU_ARROW_DOWN_PRESSED_ID));
    menuDownButton.setTouchable(true);
    menuDownButton.invalidate();
}

void CustomControlsView::screenSaverMinorTick()
{
    if (menuScrollWheel.getSelectedItem() == 0)
    {
        scrollMenuDown();
    }
    else if (menuScrollWheel.getSelectedItem() == menuScrollWheel.getNumberOfItems() - 1)
    {
        scrollMenuUp();
    }
    else
    {
        if (Utils::randomNumberBetween(0, 100) < 50)
        {
            scrollMenuUp();
        }
        else
        {
            scrollMenuDown();
        }
    }
}

void CustomControlsView::updateProcessorLoad(uint8_t mcuLoadValue)
{
    mcuLoad.updateProcessorLoad(mcuLoadValue);
}

void CustomControlsView::showSelectedControler(int16_t itemIndex)
{

    hidePreviousControler();

    switch (itemIndex)
    {
    case 0:
        gauge.setVisible(true);
        gauge.invalidate();
        break;

    case 1:
        threeWayProgressCustomContainer.setVisible(true);
        messageTextArea.setVisible(true);
        threeWayProgressCustomContainer.invalidate();
        messageTextArea.invalidate();
        threeWayProgressCustomContainer.emitCircularIconsMovingAnimationCallback();
        break;

    case 2:
        percentageBarCustomContainer.setVisible(true);
        percentageBarCustomContainer.invalidate();
        break;

    case 3:
        datePickerCustomContainer.setVisible(true);
        datePickerCustomContainer.invalidate();
        datePickerCustomContainer.startFirstTimeRunAnimation();
        break;
    }
}

void CustomControlsView::hidePreviousControler()
{

    switch (previousMenuItemIndex)
    {

    case 0:
        gauge.setVisible(false);
        gauge.invalidate();
        break;

    case 1:
        threeWayProgressCustomContainer.setVisible(false);
        messageTextArea.setVisible(false);
        threeWayProgressCustomContainer.invalidate();
        messageTextArea.invalidate();
        threeWayProgressCustomContainer.resetIconsAndProgression();
        break;

    case 2:
        percentageBarCustomContainer.setVisible(false);
        percentageBarCustomContainer.invalidate();
        break;

    case 3:
        datePickerCustomContainer.setVisible(false);
        datePickerCustomContainer.resetTheScrollWheels();
        datePickerCustomContainer.invalidate();
        break;
    }

}

void CustomControlsView::handleDragEvent(const DragEvent& Event)
{
    //Used for implementing drag event for percentageBar
    //Drags can only be used with screens
    CustomControlsViewBase::handleDragEvent(Event);

    if (percentageBarCustomContainer.isVisible() && Event.getOldX() >= percentageBarCustomContainer.getX())
    {
        percentageBarCustomContainer.dragEventCalled(Event);
    }
}
