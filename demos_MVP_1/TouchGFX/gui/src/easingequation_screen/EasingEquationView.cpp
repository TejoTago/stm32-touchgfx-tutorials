#include <gui/easingequation_screen/EasingEquationView.hpp>
#include <touchgfx/Utils.hpp>
#include <gui/easingequation_screen/EasingEquationsEnum.hpp>

EasingEquationView::EasingEquationView()
    : tickCounter(0),
      moveAnimationCounter(),
      moveAnimationDuration(100),
      animationPause(30),
      newEasingEquationChosen(true),
      isGraphDrawn(false),
      userSelectedEasingEquation(EasingEquations::bounceEaseIn)
{
    initEasingEquationFunctionList();
    initEasingEquationNames();
}

void EasingEquationView::setupScreen()
{
    mcuLoad.setTextColor(Color::getColorFromRGB(0x41, 0x5D, 0x62));

    EasingEquationViewBase::setupScreen();
}

void EasingEquationView::tearDownScreen()
{
}

void EasingEquationView::newEasingFunctionSelectedHandler()
{
    updateTheShownNameOfTheEasingEquation();

    updateUserSelectedEasingEquation();
    newEasingEquationChosen = true;
}

void EasingEquationView::updateTheShownNameOfTheEasingEquation()
{
    TypedText easingName = easingEquationNames[easingEquationButtons.selectedEasingFunction];
    easingEquationName.setTypedText(easingName);
    easingEquationName.invalidate();

}

void EasingEquationView::newEasingTypeSelectedHandler()
{
    updateUserSelectedEasingEquation();
    newEasingEquationChosen = true;
}

void EasingEquationView::updateUserSelectedEasingEquation()
{
    int easingFunction = easingEquationButtons.selectedEasingFunction;
    int easingType = easingTypeButtons.selectedEasingType;
    userSelectedEasingEquation = easingEquationFunctionList[easingFunction][easingType];
}

void EasingEquationView::initEasingEquationFunctionList()
{
    //The order is based on the EasingEquationsEnum.hpp
    easingEquationFunctionList[0][0] = EasingEquations::backEaseIn;
    easingEquationFunctionList[0][1] = EasingEquations::backEaseOut;
    easingEquationFunctionList[0][2] = EasingEquations::backEaseInOut;
    easingEquationFunctionList[1][0] = EasingEquations::bounceEaseIn;
    easingEquationFunctionList[1][1] = EasingEquations::bounceEaseOut;
    easingEquationFunctionList[1][2] = EasingEquations::bounceEaseInOut;
    easingEquationFunctionList[2][0] = EasingEquations::circEaseIn;
    easingEquationFunctionList[2][1] = EasingEquations::circEaseOut;
    easingEquationFunctionList[2][2] = EasingEquations::circEaseInOut;
    easingEquationFunctionList[3][0] = EasingEquations::cubicEaseIn;
    easingEquationFunctionList[3][1] = EasingEquations::cubicEaseOut;
    easingEquationFunctionList[3][2] = EasingEquations::cubicEaseInOut;
    easingEquationFunctionList[4][0] = EasingEquations::elasticEaseIn;
    easingEquationFunctionList[4][1] = EasingEquations::elasticEaseOut;
    easingEquationFunctionList[4][2] = EasingEquations::elasticEaseInOut;
    easingEquationFunctionList[5][0] = EasingEquations::expoEaseIn;
    easingEquationFunctionList[5][1] = EasingEquations::expoEaseOut;
    easingEquationFunctionList[5][2] = EasingEquations::expoEaseInOut;
    easingEquationFunctionList[6][0] = EasingEquations::linearEaseIn;
    easingEquationFunctionList[6][1] = EasingEquations::linearEaseOut;
    easingEquationFunctionList[6][2] = EasingEquations::linearEaseInOut;
    easingEquationFunctionList[7][0] = EasingEquations::quadEaseIn;
    easingEquationFunctionList[7][1] = EasingEquations::quadEaseOut;
    easingEquationFunctionList[7][2] = EasingEquations::quadEaseInOut;
    easingEquationFunctionList[8][0] = EasingEquations::quartEaseIn;
    easingEquationFunctionList[8][1] = EasingEquations::quartEaseOut;
    easingEquationFunctionList[8][2] = EasingEquations::quartEaseInOut;
    easingEquationFunctionList[9][0] = EasingEquations::quintEaseIn;
    easingEquationFunctionList[9][1] = EasingEquations::quintEaseOut;
    easingEquationFunctionList[9][2] = EasingEquations::quintEaseInOut;
    easingEquationFunctionList[10][0] = EasingEquations::sineEaseIn;
    easingEquationFunctionList[10][1] = EasingEquations::sineEaseOut;
    easingEquationFunctionList[10][2] = EasingEquations::sineEaseInOut;
}

void EasingEquationView::initEasingEquationNames()
{
    //The order is based on the EasingEquationsEnum.hpp
    easingEquationNames[0] = TypedText(T_EASING_EQUATION_BACK);
    easingEquationNames[1] = TypedText(T_EASING_EQUATION_BOUNCE);
    easingEquationNames[2] = TypedText(T_EASING_EQUATION_CIRCULAR);
    easingEquationNames[3] = TypedText(T_EASING_EQUATION_CUBIC);
    easingEquationNames[4] = TypedText(T_EASING_EQUATION_ELASTIC);
    easingEquationNames[5] = TypedText(T_EASING_EQUATION_EXPONENTIAL);
    easingEquationNames[6] = TypedText(T_EASING_EQUATION_LINEAR);
    easingEquationNames[7] = TypedText(T_EASING_EQUATION_QUADRATIC);
    easingEquationNames[8] = TypedText(T_EASING_EQUATION_QUARTIC);
    easingEquationNames[9] = TypedText(T_EASING_EQUATION_QUINTIC);
    easingEquationNames[10] = TypedText(T_EASING_EQUATION_SINUSOIDAL);
}

void EasingEquationView::handleTickEvent()
{
    if (newEasingEquationChosen)
    {
        startDotMoveAnimation();

        graph.clear();
        newEasingEquationChosen = false;
        isGraphDrawn = false;
    }

    if (tickCounter < moveAnimationDuration)
    {
        int deltaGraphDot = 0;

        if (!isGraphDrawn)
        {
            for (int i = 0; i < 5; i++)
            {
                deltaGraphDot = userSelectedEasingEquation(moveAnimationCounter + i, 0, 2500, moveAnimationDuration * 5);
                graph.addDataPoint(deltaGraphDot / 10.0f);
            }
        }

        updatePositionOfGraphDot();
    }

    if (tickCounter >= moveAnimationDuration + animationPause)
    {
        startDotMoveAnimation();
        isGraphDrawn = true;
    }

    tickCounter++;
    moveAnimationCounter = moveAnimationCounter + 5;
}

void EasingEquationView::startDotMoveAnimation()
{

    resetPositionOfBothDots();

    tickCounter = 0;
    moveAnimationCounter = 0;

    dot.startMoveAnimation(408, dot.getY(), moveAnimationDuration, userSelectedEasingEquation, userSelectedEasingEquation);
    dot.invalidate();
}

void EasingEquationView::resetPositionOfBothDots()
{
    //Values from designer
    dot.moveTo(150, 197);
    dot.invalidate();

    graphDot.moveTo(179, 160);
    graphDot.invalidate();
}

void EasingEquationView::updatePositionOfGraphDot()
{
    // Align center of the graph dot with the third insertion point
    uint16_t X_OfDataPoint = graph.indexToScreenX(moveAnimationCounter + 2);
    uint16_t Y_OfDataPoint = graph.indexToScreenY(moveAnimationCounter + 2);
    graphDot.moveTo(X_OfDataPoint + graph.getX() - (graphDot.getWidth() / 2), Y_OfDataPoint + graph.getY() - (graphDot.getHeight() / 2));
    graphDot.invalidate();
}

void EasingEquationView::updateProcessorLoad(uint8_t mcuLoadValue)
{
    mcuLoad.updateProcessorLoad(mcuLoadValue);
}
