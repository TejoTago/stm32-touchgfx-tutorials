#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>

MainMenuView::MainMenuView()
{
}

MainMenuView::~MainMenuView()
{
}

void MainMenuView::setupScreen()
{
    lastSeenPage = presenter->getLastSeenPage();
    swipeContainer.setSelectedPage(lastSeenPage);

    MainMenuViewBase::setupScreen();
}


void MainMenuView::tearDownScreen()
{
    lastSeenPage = swipeContainer.getSelectedPage();
    presenter->setLastSeenPage(lastSeenPage);

    MainMenuViewBase::tearDownScreen();

}


void MainMenuView::updateProcessorLoad(uint8_t mcuLoadValue)
{
    mcuLoad.updateProcessorLoad(mcuLoadValue);
}
