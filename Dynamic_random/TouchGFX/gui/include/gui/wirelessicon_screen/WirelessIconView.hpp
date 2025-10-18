#ifndef WIRELESSICONVIEW_HPP
#define WIRELESSICONVIEW_HPP

#include <gui_generated/wirelessicon_screen/WirelessIconViewBase.hpp>
#include <gui/wirelessicon_screen/WirelessIconPresenter.hpp>

class WirelessIconView : public WirelessIconViewBase
{
public:
    WirelessIconView();
    virtual ~WirelessIconView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent() override;

private:
    void onToggleChanged(const touchgfx::AbstractButton& source);

    static const int NUM_CIRCLES = 5;
    touchgfx::Circle* circles[NUM_CIRCLES];

    int currentCircleIndex;
    int tickCounter;
    int blinkInterval;
    int stageCounter;
    bool blinkingActive;

    //touchgfx::Callback<WirelessIconView> toggleCallback;
    touchgfx::Callback<WirelessIconView, const touchgfx::AbstractButton&> toggleCallback;
    touchgfx::Container tickReceiver;
};

#endif // WIRELESSICONVIEW_HPP
