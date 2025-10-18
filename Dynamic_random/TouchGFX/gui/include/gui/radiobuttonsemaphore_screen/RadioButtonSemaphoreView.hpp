#ifndef RADIOBUTTONSEMAPHOREVIEW_HPP
#define RADIOBUTTONSEMAPHOREVIEW_HPP

#include <gui_generated/radiobuttonsemaphore_screen/RadioButtonSemaphoreViewBase.hpp>
#include <gui/radiobuttonsemaphore_screen/RadioButtonSemaphorePresenter.hpp>

class RadioButtonSemaphoreView : public RadioButtonSemaphoreViewBase
{
public:
    RadioButtonSemaphoreView();
    virtual ~RadioButtonSemaphoreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void semaphore() override;
    virtual void handleTickEvent() override;
protected:
private:
private:
    enum Mode { OFF, SLOW, FAST } currentMode;
    int tickCounter;
    int currentLightIndex; // 0 = red, 1 = yellow, 2 = green

    void updateSemaphoreLights();

};

#endif // RADIOBUTTONSEMAPHOREVIEW_HPP
