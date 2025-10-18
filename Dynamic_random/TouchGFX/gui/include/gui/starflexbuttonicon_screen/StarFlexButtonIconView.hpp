#ifndef STARFLEXBUTTONICONVIEW_HPP
#define STARFLEXBUTTONICONVIEW_HPP

#include <gui_generated/starflexbuttonicon_screen/StarFlexButtonIconViewBase.hpp>
#include <gui/starflexbuttonicon_screen/StarFlexButtonIconPresenter.hpp>

class StarFlexButtonIconView : public StarFlexButtonIconViewBase
{
public:
    StarFlexButtonIconView();
    virtual ~StarFlexButtonIconView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateRating() override;

protected:
//    void onStar1Clicked();
//     void onStar2Clicked();
//     void onStar3Clicked();
//     void onStar4Clicked();
//     void onStar5Clicked();

private:
    int lastClickedStar;

};

#endif // STARFLEXBUTTONICONVIEW_HPP
