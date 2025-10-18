#ifndef DATE_HPP
#define DATE_HPP

#include <gui_generated/containers/DateBase.hpp>

class Date : public DateBase
{
public:
    Date();
    virtual ~Date() {}

    virtual void initialize();

    void setText(int date);
    void setTextType(touchgfx::TypedText typedText);

    void changeColorToBlue();

protected:
};

#endif // DATE_HPP
