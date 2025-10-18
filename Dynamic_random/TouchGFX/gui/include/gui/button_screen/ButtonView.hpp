#ifndef BUTTONVIEW_HPP
#define BUTTONVIEW_HPP

#include <gui_generated/button_screen/ButtonViewBase.hpp>
#include <gui/button_screen/ButtonPresenter.hpp>

class ButtonView : public ButtonViewBase
{
public:
    ButtonView();
    virtual ~ButtonView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // BUTTONVIEW_HPP
