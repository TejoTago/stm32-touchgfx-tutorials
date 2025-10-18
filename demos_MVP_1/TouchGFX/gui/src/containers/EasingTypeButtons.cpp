#include <gui/containers/EasingTypeButtons.hpp>
#include <touchgfx/Color.hpp>

EasingTypeButtons::EasingTypeButtons() :
    selectedEasingType(InOut),
    radioButtonSelectedCallback(this, &EasingTypeButtons::radioButtonSelectedCallbackHandler),
    radioButtonDeselectedCallback(this, &EasingTypeButtons::radioButtonDeselectedCallbackHandler)
{

}

void EasingTypeButtons::initialize()
{
    radioButtonGroup.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup.setRadioButtonDeselectedHandler(radioButtonDeselectedCallback);
    radioButtonGroup.setSelected(easeInButton);

    EasingTypeButtonsBase::initialize();
}

void EasingTypeButtons::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{

    if (&src == &easeInButton)
    {
        selectedEasingType = In;
        easeInText.setColor(Color::getColorFromRGB(0xFF, 0x61, 0x14));
    }
    else if (&src == &easeOutButton)
    {
        selectedEasingType = Out;
        easeOutText.setColor(Color::getColorFromRGB(0xFF, 0x61, 0x14));
    }
    else if (&src == &easeInOutButton)
    {
        selectedEasingType = InOut;
        easeInOutText.setColor(Color::getColorFromRGB(0xFF, 0x61, 0x14));
    }

    emitNewEasingTypeSelectedCallback();
}

void EasingTypeButtons::radioButtonDeselectedCallbackHandler(const touchgfx::AbstractButton& src)
{

    if (&src == &easeInButton)
    {
        easeInText.setColor(Color::getColorFromRGB(0x9D, 0xC9, 0xD1));
    }
    else if (&src == &easeOutButton)
    {
        easeOutText.setColor(Color::getColorFromRGB(0x9D, 0xC9, 0xD1));
    }
    else if (&src == &easeInOutButton)
    {
        easeInOutText.setColor(Color::getColorFromRGB(0x9D, 0xC9, 0xD1));
    }
}
