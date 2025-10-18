#include <gui/containers/DatePickerCustomContainer.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DatePickerCustomContainer::DatePickerCustomContainer()
    : startYear(2017),
      clickCallback(this, &DatePickerCustomContainer::updateNumberOfDaysBasedOnMonth),
      animationEndedCallback(this, &DatePickerCustomContainer::changeAnimationStyle)
{

}

void DatePickerCustomContainer::initialize()
{
    monthScrollWheel.setClickAction(clickCallback);
    yearScrollWheel.setClickAction(clickCallback);

    dayScrollWheel.setAnimationEndedCallback(animationEndedCallback);

    setScrollWheelsOverShootPercentage(65);
    resetTheScrollWheels();

    DatePickerCustomContainerBase::initialize();
}

void DatePickerCustomContainer::setScrollWheelsOverShootPercentage(uint8_t percentage)
{

    dayScrollWheel.setOvershootPercentage(percentage);
    monthScrollWheel.setOvershootPercentage(percentage);
    yearScrollWheel.setOvershootPercentage(percentage);

}


void DatePickerCustomContainer::resetTheScrollWheels()
{
    setScrollWheelsSelectedItem(7);
}

void DatePickerCustomContainer::setScrollWheelsSelectedItem(int16_t itemIndex)
{
    dayScrollWheel.animateToItem(itemIndex + 10);
    monthScrollWheel.animateToItem(itemIndex);
    yearScrollWheel.animateToItem(itemIndex);
}

void DatePickerCustomContainer::dayScrollWheelUpdateItem(Date& item, int16_t itemIndex)
{
    item.setText(itemIndex + 1);
}

void DatePickerCustomContainer::monthScrollWheelUpdateItem(Date& item, int16_t itemIndex)
{
    setNameOfTheMonth(item, itemIndex);
}

void DatePickerCustomContainer::setNameOfTheMonth(Date& item, int16_t itemIndex)
{
    switch (itemIndex)
    {
    case 0:
        item.setTextType(touchgfx::TypedText(T_JANUARY));
        break;

    case 1:
        item.setTextType(touchgfx::TypedText(T_FEBRUARY));
        break;

    case 2:
        item.setTextType(touchgfx::TypedText(T_MARCH));
        break;

    case 3:
        item.setTextType(touchgfx::TypedText(T_APRIL));
        break;

    case 4:
        item.setTextType(touchgfx::TypedText(T_MAY));
        break;

    case 5:
        item.setTextType(touchgfx::TypedText(T_JUNE));
        break;

    case 6:
        item.setTextType(touchgfx::TypedText(T_JULY));
        break;

    case 7:
        item.setTextType(touchgfx::TypedText(T_AUGUST));
        break;

    case 8:
        item.setTextType(touchgfx::TypedText(T_SEPTEMBER));
        break;

    case 9:
        item.setTextType(touchgfx::TypedText(T_OCTOBER));
        break;

    case 10:
        item.setTextType(touchgfx::TypedText(T_NOVEMBER));
        break;

    case 11:
        item.setTextType(touchgfx::TypedText(T_DECEMBER));
        break;

    default:
        break;
    }
}

void DatePickerCustomContainer::yearScrollWheelUpdateItem(Date& item, int16_t itemIndex)
{
    item.setText(startYear + itemIndex);
}

void DatePickerCustomContainer::dayScrollWheelUpdateCenterItem(Date& item, int16_t itemIndex)
{
    item.setText(itemIndex + 1);
    item.changeColorToBlue();
}

void DatePickerCustomContainer::monthScrollWheelUpdateCenterItem(Date& item, int16_t itemIndex)
{
    setNameOfTheMonth(item, itemIndex);
    item.changeColorToBlue();
}

void DatePickerCustomContainer::yearScrollWheelUpdateCenterItem(Date& item, int16_t itemIndex)
{
    item.setText(startYear + itemIndex);
    item.changeColorToBlue();
}

void DatePickerCustomContainer::startFirstTimeRunAnimation()
{

    int16_t animationSteps = 100;

    changeScrollWheelsAnimationEasing(EasingEquations::elasticEaseOut);

    dayScrollWheel.setAnimationSteps(animationSteps + 5);
    monthScrollWheel.setAnimationSteps(animationSteps - 20);
    yearScrollWheel.setAnimationSteps(animationSteps);

    setScrollWheelsSelectedItem(3);

    eaquationChanged = false;
}

void DatePickerCustomContainer::changeScrollWheelsAnimationEasing(EasingEquation equation)
{
    dayScrollWheel.setEasingEquation(equation);
    monthScrollWheel.setEasingEquation(equation);
    yearScrollWheel.setEasingEquation(equation);
}

void DatePickerCustomContainer::updateNumberOfDaysBasedOnMonth(const ScrollWheelWithSelectionStyle& object, const ClickEvent& Event)
{

    if (Event.getType() != ClickEvent::RELEASED)
    {
        return;
    }

    int selectedMonth = monthScrollWheel.getSelectedItem();
    int selectedYear = startYear + yearScrollWheel.getSelectedItem();

    int numberOfDays = 31;

    if (selectedMonth == 0 || selectedMonth == 2 || selectedMonth == 4 || selectedMonth == 6 || selectedMonth == 7 || selectedMonth == 9 || selectedMonth == 11)
    {
        numberOfDays = 31;
    }
    else if (selectedMonth == 3 || selectedMonth == 5 || selectedMonth == 8 || selectedMonth == 10)
    {
        numberOfDays = 30;
    }
    else if (selectedMonth == 1)
    {
        //month = February
        numberOfDays = 28;

        if (selectedYear % 4 == 0)
        {
            numberOfDays++;
        }
    }

    dayScrollWheel.setNumberOfItems(numberOfDays);
    dayScrollWheel.invalidate();

}

void DatePickerCustomContainer::changeAnimationStyle()
{
    if (!eaquationChanged)
    {
        changeScrollWheelsAnimationEasing(EasingEquations::backEaseOut);

        dayScrollWheel.setAnimationSteps(20);
        monthScrollWheel.setAnimationSteps(20);
        yearScrollWheel.setAnimationSteps(20);

        eaquationChanged = true;
    }
}
