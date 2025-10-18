#ifndef DATEPICKERCUSTOMCONTAINER_HPP
#define DATEPICKERCUSTOMCONTAINER_HPP

#include <gui_generated/containers/DatePickerCustomContainerBase.hpp>

class DatePickerCustomContainer : public DatePickerCustomContainerBase
{
public:
    DatePickerCustomContainer();
    virtual ~DatePickerCustomContainer() {}

    virtual void initialize();

    virtual void dayScrollWheelUpdateItem(Date& item, int16_t itemIndex);
    virtual void monthScrollWheelUpdateItem(Date& item, int16_t itemIndex);
    virtual void yearScrollWheelUpdateItem(Date& item, int16_t itemIndex);

    virtual void dayScrollWheelUpdateCenterItem(Date& item, int16_t itemIndex);
    virtual void monthScrollWheelUpdateCenterItem(Date& item, int16_t itemIndex);
    virtual void yearScrollWheelUpdateCenterItem(Date& item, int16_t itemIndex);


    void startFirstTimeRunAnimation();
    void resetTheScrollWheels();

protected:

    const int startYear;
    bool eaquationChanged;

    void setScrollWheelsOverShootPercentage(uint8_t percentage);
    void setScrollWheelsSelectedItem(int16_t itemIndex);
    void changeScrollWheelsAnimationEasing(EasingEquation equation);

    void setNameOfTheMonth(Date& item, int16_t itemIndex);
    void updateNumberOfDaysBasedOnMonth(const ScrollWheelWithSelectionStyle& object, const ClickEvent& Event);

    Callback<DatePickerCustomContainer, const ScrollWheelWithSelectionStyle&, const ClickEvent&> clickCallback;

    Callback<DatePickerCustomContainer> animationEndedCallback;
    void changeAnimationStyle();
};

#endif // DATEPICKERCUSTOMCONTAINER_HPP
