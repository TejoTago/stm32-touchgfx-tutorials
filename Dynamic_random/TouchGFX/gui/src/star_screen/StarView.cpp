#include <gui/star_screen/StarView.hpp>

StarView::StarView()
: lastPressedIndex(0),
  button1ClickedCallback(this, &StarView::onButton1Clicked),
  button2ClickedCallback(this, &StarView::onButton2Clicked),
  button3ClickedCallback(this, &StarView::onButton3Clicked),
  button4ClickedCallback(this, &StarView::onButton4Clicked),
  button5ClickedCallback(this, &StarView::onButton5Clicked)

{
}

void StarView::setupScreen()
{
    StarViewBase::setupScreen();
    lastPressedIndex = 0;

    // Bind the wildcard buffer to the text area to show star count
    textArea1.setWildcard(textArea1Buffer);
}

void StarView::tearDownScreen()
{
    StarViewBase::tearDownScreen();
}

void StarView::updateRating()
{
    // Update the visibility of star shapes based on lastPressedIndex
    for (int i = 1; i <= 5; ++i)
    {
        bool visible = (i <= lastPressedIndex);

        switch (i)
        {
            case 1:
                star1_Off.setVisible(!visible);
                star1.setVisible(visible);
                star1.invalidate();
                star1_Off.invalidate();
                break;
            case 2:
                star2_Off.setVisible(!visible);
                star2.setVisible(visible);
                star2.invalidate();
                star2_Off.invalidate();
                break;
            case 3:
                star3_Off.setVisible(!visible);
                star3.setVisible(visible);
                star3.invalidate();
                star3_Off.invalidate();
                break;
            case 4:
                star4_Off.setVisible(!visible);
                star4.setVisible(visible);
                star4.invalidate();
                star4_Off.invalidate();
                break;
            case 5:
                star5_Off.setVisible(!visible);
                star5.setVisible(visible);
                star5.invalidate();
                star5_Off.invalidate();
                break;
        }
    }

    // Update the text area showing the star count
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", lastPressedIndex);
    textArea1.invalidate();
}

void StarView::onButton1Clicked(const touchgfx::AbstractButtonContainer&) { lastPressedIndex = 1; updateRating(); }
void StarView::onButton2Clicked(const touchgfx::AbstractButtonContainer&) { lastPressedIndex = 2; updateRating(); }
void StarView::onButton3Clicked(const touchgfx::AbstractButtonContainer&) { lastPressedIndex = 3; updateRating(); }
void StarView::onButton4Clicked(const touchgfx::AbstractButtonContainer&) { lastPressedIndex = 4; updateRating(); }
void StarView::onButton5Clicked(const touchgfx::AbstractButtonContainer&) { lastPressedIndex = 5; updateRating(); }

void StarView::test()
{
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", 1);
    textArea1.invalidate();
}
