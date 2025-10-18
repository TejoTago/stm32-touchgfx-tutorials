#ifndef MAINMENU_PRESENTER_HPP
#define MAINMENU_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainMenuView;

class MainMenuPresenter : public Presenter, public ModelListener
{
public:
    MainMenuPresenter(MainMenuView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainMenuPresenter() {};

    virtual void mcuLoadUpdated(uint8_t mcuLoad);

    void setLastSeenPage(uint8_t lastSeenPage);
    uint8_t getLastSeenPage();

private:
    MainMenuPresenter();

    MainMenuView& view;
};

#endif // MAINMENU_PRESENTER_HPP
