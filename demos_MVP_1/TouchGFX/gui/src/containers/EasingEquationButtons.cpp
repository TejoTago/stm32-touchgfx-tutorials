#include <gui/containers/EasingEquationButtons.hpp>

EasingEquationButtons::EasingEquationButtons() :
    selectedEasingFunction(BACK),
    radioButtonSelectedCallback(this, &EasingEquationButtons::radioButtonSelectedCallbackHandler)
{

}

void EasingEquationButtons::initialize()
{
    radioButtonGroup.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup.setSelected(bounceButton);

    EasingEquationButtonsBase::initialize();
}

void EasingEquationButtons::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{

    if (&src == &backButton)
    {
        selectedEasingFunction = BACK;
    }
    else if (&src == &bounceButton)
    {
        selectedEasingFunction = BOUNCE;
    }
    else if (&src == &circularButton)
    {
        selectedEasingFunction = CIRC;
    }
    else if (&src == &cubicButton)
    {
        selectedEasingFunction = CUBIC;
    }
    else if (&src == &elasticButton)
    {
        selectedEasingFunction = ELASTIC;
    }
    else if (&src == &exponentialButton)
    {
        selectedEasingFunction = EXPO;
    }
    else if (&src == &linearButton)
    {
        selectedEasingFunction = LINEAR;
    }
    else if (&src == &quardraticButton)
    {
        selectedEasingFunction = QUAD;
    }
    else if (&src == &quarticButton)
    {
        selectedEasingFunction = QUART;
    }
    else if (&src == &quinticButton)
    {
        selectedEasingFunction = QUINT;
    }
    else if (&src == &sinusodialButton)
    {
        selectedEasingFunction = SINE;
    }

    emitNewEasingFunctionSelectedCallback();
}
