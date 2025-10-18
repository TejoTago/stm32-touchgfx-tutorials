#ifndef THREEWAYPROGRESSCUSTOMCONTAINER_HPP
#define THREEWAYPROGRESSCUSTOMCONTAINER_HPP

#include <gui_generated/containers/ThreeWayProgressCustomContainerBase.hpp>

class ThreeWayProgressCustomContainer : public ThreeWayProgressCustomContainerBase
{
public:
    ThreeWayProgressCustomContainer();
    virtual ~ThreeWayProgressCustomContainer() {}
    virtual void initialize();

    void setCircleProgressesVisiblity(bool visibility);
    void setCirlceProgressesValues(int value);
    void updateCircleProgressesValues();
    touchgfx::EasingEquation getRandomEasingEquation();

    virtual void startShowingProgress();
    void resetIconsAndProgression();
    void resetCircleProgresses();

    void emitCircularIconsMovingAnimationCallback();

    void updatePercentageLables();

protected:
    int progressEndedCounter;
    void setCircularIconsInactive();
    void setCircularIconsActive();

    Callback<ThreeWayProgressCustomContainer, const AbstractProgressIndicator&> circularProgressEndedCallback;
    void circularProgressEndedHandler(const AbstractProgressIndicator& ap);
};

#endif // THREEWAYPROGRESSCUSTOMCONTAINER_HPP
