#ifndef MOVEWIDGETWITHINTERACTIONSVIEW_HPP
#define MOVEWIDGETWITHINTERACTIONSVIEW_HPP

#include <gui_generated/movewidgetwithinteractions_screen/MoveWidgetWithInteractionsViewBase.hpp>
#include <gui/movewidgetwithinteractions_screen/MoveWidgetWithInteractionsPresenter.hpp>

class MoveWidgetWithInteractionsView : public MoveWidgetWithInteractionsViewBase
{
public:
    MoveWidgetWithInteractionsView();
    virtual ~MoveWidgetWithInteractionsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MOVEWIDGETWITHINTERACTIONSVIEW_HPP
