#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <gui/mainmenu_screen/MainMenuPresenter.hpp>

MainMenuPresenter::MainMenuPresenter(MainMenuView& v)
    : view(v)
{
}

void MainMenuPresenter::activate()
{
}

void MainMenuPresenter::deactivate()
{
}

void MainMenuPresenter::mcuLoadUpdated(uint8_t mcuLoad)
{
    view.updateProcessorLoad(mcuLoad);
}

void MainMenuPresenter::setLastSeenPage(uint8_t lastSeenPage)
{
    model->setLastSeenPage(lastSeenPage);
}

uint8_t MainMenuPresenter::getLastSeenPage()
{
    return model->getLastSeenPage();
}
