#ifndef EASINGEQUATIONBUTTONS_HPP
#define EASINGEQUATIONBUTTONS_HPP

#include <gui_generated/containers/EasingEquationButtonsBase.hpp>
#include <gui/easingequation_screen/EasingEquationsEnum.hpp>

class EasingEquationButtons : public EasingEquationButtonsBase
{
public:
    EasingEquationButtons();
    virtual ~EasingEquationButtons() {}

    virtual void initialize();

    EasingFunction selectedEasingFunction;

protected:

    Callback<EasingEquationButtons, const touchgfx::AbstractButton&> radioButtonSelectedCallback;
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);
};

#endif // EASINGEQUATIONBUTTONS_HPP
