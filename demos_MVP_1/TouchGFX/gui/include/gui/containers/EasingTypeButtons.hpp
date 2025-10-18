#ifndef EASINGTYPEBUTTONS_HPP
#define EASINGTYPEBUTTONS_HPP

#include <gui_generated/containers/EasingTypeButtonsBase.hpp>
#include <gui/easingequation_screen/EasingEquationsEnum.hpp>
class EasingTypeButtons : public EasingTypeButtonsBase
{
public:
    EasingTypeButtons();
    virtual ~EasingTypeButtons() {}

    virtual void initialize();

    EasingType selectedEasingType;
protected:

    Callback<EasingTypeButtons, const touchgfx::AbstractButton&> radioButtonSelectedCallback;
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);

    Callback<EasingTypeButtons, const touchgfx::AbstractButton&> radioButtonDeselectedCallback;
    void radioButtonDeselectedCallbackHandler(const touchgfx::AbstractButton& src);
};

#endif // EASINGTYPEBUTTONS_HPP
