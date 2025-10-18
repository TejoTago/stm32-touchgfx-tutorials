#ifndef CUSTOMCONTROLS_VIEW_HPP
#define CUSTOMCONTROLS_VIEW_HPP

#include <gui_generated/customcontrols_screen/CustomControlsViewBase.hpp>
#include <gui/customcontrols_screen/CustomControlsPresenter.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>


class CustomControlsView : public CustomControlsViewBase
{
public:
    CustomControlsView();
    virtual ~CustomControlsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    virtual void handleDragEvent(const DragEvent& Event);
    virtual void menuScrollWheelUpdateItem(MenuIconCustomContainer& item, int16_t itemIndex);

    virtual void scrollMenuUp();
    virtual void scrollMenuDown();

    void setMenuUpButtonActive();
    void setMenuUpButtonInactive();

    void setMenuDownButtonActive();
    void setMenuDownButtonInactive();

    void showSelectedControler(int16_t itemIndex);
    void hidePreviousControler();

    void updateProcessorLoad(uint8_t mcuLoadValue);
    virtual void screenSaverMinorTick();

protected:
    int tickCounter;
    uint16_t selectedMenuItemIndex;
    uint16_t previousMenuItemIndex;

    Callback<CustomControlsView, int16_t> scrollWheelAnimateToNewItemCallback;

    void updateGaugeValue();
};

#endif // CUSTOMCONTROLS_VIEW_HPP
