#ifndef SCREENLOGOVIEW_HPP
#define SCREENLOGOVIEW_HPP

#include <gui_generated/screenlogo_screen/ScreenLogoViewBase.hpp>
#include <gui/screenlogo_screen/ScreenLogoPresenter.hpp>

class ScreenLogoView : public ScreenLogoViewBase
{
public:
    ScreenLogoView();
    virtual ~ScreenLogoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    touchgfx::PainterRGB565 shapeB1Painter;
    touchgfx::MoveAnimator< touchgfx::Shape<8> > shapeB1;
};

#endif // SCREENLOGOVIEW_HPP
