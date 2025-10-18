#ifndef SLIDERBLINKCONTROLVIEW_HPP
#define SLIDERBLINKCONTROLVIEW_HPP

#include <gui_generated/sliderblinkcontrol_screen/SliderBlinkControlViewBase.hpp>
#include <gui/sliderblinkcontrol_screen/SliderBlinkControlPresenter.hpp>

class SliderBlinkControlView : public SliderBlinkControlViewBase
{
public:
    SliderBlinkControlView();
    virtual ~SliderBlinkControlView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void visibilityControl() override;
    virtual void colorControl(int value) override;
    virtual void blinkControl() override;
    virtual void handleTickEvent() override;


protected:
    bool blinking = false;
    uint16_t blinkCounter = 0;
    int blinkMode = 0;          // 0 (off), 1 (normal), 2 (2x), 3 (3x)
    int blinkBaseInterval = 15; // Default tick interval for normal speed

};
// Outside any class in the header file
void hsvToRgb(uint16_t h, uint8_t s, uint8_t v, uint8_t& r, uint8_t& g, uint8_t& b);


#endif // SLIDERBLINKCONTROLVIEW_HPP
