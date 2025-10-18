#ifndef EASINGEQUATION_VIEW_HPP
#define EASINGEQUATION_VIEW_HPP

#include <gui_generated/easingequation_screen/EasingEquationViewBase.hpp>
#include <gui/easingequation_screen/EasingEquationPresenter.hpp>
#include <texts/TextKeysAndLanguages.hpp>

class EasingEquationView : public EasingEquationViewBase
{
public:
    EasingEquationView();
    virtual ~EasingEquationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    virtual void newEasingFunctionSelectedHandler();
    virtual void newEasingTypeSelectedHandler();

    void updateProcessorLoad(uint8_t mcuLoadValue);

    void startDotMoveAnimation();

protected:

    int tickCounter;
    int moveAnimationCounter;
    const int moveAnimationDuration;
    const int animationPause;

    bool newEasingEquationChosen;
    bool isGraphDrawn;
    EasingEquation userSelectedEasingEquation;

    void resetPositionOfBothDots();
    void updatePositionOfGraphDot();

    void updateTheShownNameOfTheEasingEquation();
    void updateUserSelectedEasingEquation();

    void initEasingEquationFunctionList();
    void initEasingEquationNames();

    EasingEquation easingEquationFunctionList[11][3];
    TypedText easingEquationNames[11];
};

#endif
