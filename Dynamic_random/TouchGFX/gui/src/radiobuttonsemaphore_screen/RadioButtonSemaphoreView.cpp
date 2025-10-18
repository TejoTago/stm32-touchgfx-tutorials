#include <gui/radiobuttonsemaphore_screen/RadioButtonSemaphoreView.hpp>

RadioButtonSemaphoreView::RadioButtonSemaphoreView()
: currentMode(OFF), tickCounter(0), currentLightIndex(0)

{

}

void RadioButtonSemaphoreView::setupScreen()
{
    RadioButtonSemaphoreViewBase::setupScreen();
}

void RadioButtonSemaphoreView::tearDownScreen()
{
    RadioButtonSemaphoreViewBase::tearDownScreen();
}

void RadioButtonSemaphoreView::semaphore()
{
    if (radioButtonOFF.getSelected())
    {
        currentMode = OFF;
        redON.setVisible(false);
        redOFF.setVisible(true);
        yellowON.setVisible(false);
        yellowOFF.setVisible(true);
        greenON.setVisible(false);
        greenOFF.setVisible(true);
    }
    else if (radioButtonSlow.getSelected())
    {
        currentMode = SLOW;
        tickCounter = 0;
        currentLightIndex = 0;
    }
    else if (radioButtonFast.getSelected())
    {
        currentMode = FAST;
        tickCounter = 0;
        currentLightIndex = 0;
    }

    invalidate();
}

void RadioButtonSemaphoreView::handleTickEvent()
{
    tickCounter++;

    if ((currentMode == SLOW && tickCounter % 60 == 0) ||
        (currentMode == FAST && tickCounter % 20 == 0))
    {
        updateSemaphoreLights();
    }
}

void RadioButtonSemaphoreView::updateSemaphoreLights()
{
    // Turn all OFF first
    redON.setVisible(false);
    redOFF.setVisible(true);
    yellowON.setVisible(false);
    yellowOFF.setVisible(true);
    greenON.setVisible(false);
    greenOFF.setVisible(true);

    // Turn ON the current light
    switch (currentLightIndex)
    {
        case 0:
            redON.setVisible(true);
            redOFF.setVisible(false);
            break;
        case 1:
            yellowON.setVisible(true);
            yellowOFF.setVisible(false);
            break;
        case 2:
            greenON.setVisible(true);
            greenOFF.setVisible(false);
            break;
    }

    // Advance to next light
    currentLightIndex = (currentLightIndex + 1) % 3;

    invalidate();
}
