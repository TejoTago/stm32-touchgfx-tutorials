#ifndef LOLLIPOPVIEW_HPP
#define LOLLIPOPVIEW_HPP

#include <gui_generated/lollipop_screen/lollipopViewBase.hpp>
#include <gui/lollipop_screen/lollipopPresenter.hpp>

class lollipopView : public lollipopViewBase
{
public:
    lollipopView();
    virtual ~lollipopView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int monthValues[12];
    int tickCounter;
    float wavePhase[12];     // Wave
     float time;              // Wave

    void generateRandomValues();
    void updateLollipop(int month, int value);
    void updateAllLollipops();
    void generateWaveValues(); // Wave
};

#endif // LOLLIPOPVIEW_HPP
