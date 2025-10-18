#ifndef STARVIEW_HPP
#define STARVIEW_HPP

#include <gui_generated/star_screen/StarViewBase.hpp>
#include <gui/star_screen/StarPresenter.hpp>

class StarView : public StarViewBase
{
public:
    StarView();
    virtual ~StarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void test() override;


protected:
    virtual void updateRating() override; // override base virtual if defined
private:
    int lastPressedIndex;

    // Callback objects
    touchgfx::Callback<StarView, const touchgfx::AbstractButtonContainer&> button1ClickedCallback;
    touchgfx::Callback<StarView, const touchgfx::AbstractButtonContainer&> button2ClickedCallback;
    touchgfx::Callback<StarView, const touchgfx::AbstractButtonContainer&> button3ClickedCallback;
    touchgfx::Callback<StarView, const touchgfx::AbstractButtonContainer&> button4ClickedCallback;
    touchgfx::Callback<StarView, const touchgfx::AbstractButtonContainer&> button5ClickedCallback;

    // Callback handler methods
    void onButton1Clicked(const touchgfx::AbstractButtonContainer&);
    void onButton2Clicked(const touchgfx::AbstractButtonContainer&);
    void onButton3Clicked(const touchgfx::AbstractButtonContainer&);
    void onButton4Clicked(const touchgfx::AbstractButtonContainer&);
    void onButton5Clicked(const touchgfx::AbstractButtonContainer&);

};

#endif // STARVIEW_HPP
