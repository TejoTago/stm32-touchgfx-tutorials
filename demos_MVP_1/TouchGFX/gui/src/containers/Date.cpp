#include <gui/containers/Date.hpp>
#include <touchgfx/Color.hpp>

Date::Date()
{

}

void Date::initialize()
{
    DateBase::initialize();
}

void Date::setText(int date)
{
    Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "%d", date);
}

void Date::setTextType(touchgfx::TypedText typedText)
{
    textArea.setTypedText(typedText);
}

void Date::changeColorToBlue()
{
    textArea.setColor(touchgfx::Color::getColorFromRGB(0, 138, 255));
    textArea.invalidate();
}
