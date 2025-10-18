#ifndef RADIOBUTTONSEMAPHORENEWVIEW_HPP
#define RADIOBUTTONSEMAPHORENEWVIEW_HPP

#include <gui_generated/radiobuttonsemaphorenew_screen/RadioButtonSemaphoreNewViewBase.hpp>
#include <gui/radiobuttonsemaphorenew_screen/RadioButtonSemaphoreNewPresenter.hpp>

class RadioButtonSemaphoreNewView : public RadioButtonSemaphoreNewViewBase
{
public:
    RadioButtonSemaphoreNewView();
    virtual ~RadioButtonSemaphoreNewView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void semaphore() override;
    virtual void handleTickEvent() override;

protected:
    enum Mode { OFF, SLOW, FAST } currentMode;
    int tickCounter;
    int currentLightIndex;

    void updateSemaphoreLights();

};

#endif // RADIOBUTTONSEMAPHORENEWVIEW_HPP
