#include <gui/productpresenter_screen/ProductPresenterView.hpp>
#include "BitmapDatabase.hpp"
#include <touchgfx/Color.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ProductPresenterView::ProductPresenterView() :
    selectedPoster(0),
    onFadeAnimationEnded(this, &ProductPresenterView::fadeAnimationEndedHandler),
    selectedLanguage(GBR),
    selectedLanguageBitmapID(0)
{
}

void ProductPresenterView::setupScreen()
{
    bodyText.setFadeAnimationEndedAction(onFadeAnimationEnded);
}

void ProductPresenterView::tearDownScreen()
{
    // Reset language to GBR, which is used in the rest of the demo
    selectedLanguage = GBR;
    selectedLanguageBitmapID = BITMAP_FLAG_GBR_ACTIVE_ID;
    setLanguage();
}

void ProductPresenterView::updateProcessorLoad(uint8_t mcuLoadValue)
{
    mcuLoad.updateProcessorLoad(mcuLoadValue);
}

void ProductPresenterView::nextbuttonPressed()
{
    animateToPoster((selectedPoster + 1) % NUMBER_OF_POSTERS, 10);
}


void ProductPresenterView::languageButtonClicked()
{
    if (languageMenu.getState() == SlideMenu::COLLAPSED)
    {
        languageMenu.setAnimationEasingEquation(EasingEquations::sineEaseOut);
        languageMenu.animateToState(SlideMenu::EXPANDED);
        languageMenu.setAnimationEasingEquation(EasingEquations::sineEaseIn);
        languageMenu.setVisible(true);
        languageButton.setVisible(false);
    }
}

void ProductPresenterView::GBFlagClicked()
{
    selectedLanguage = GBR;
    selectedLanguageBitmapID = BITMAP_FLAG_GBR_ACTIVE_ID;
    setLanguage();
}

void ProductPresenterView::DKFlagClicked()
{
    selectedLanguage = DNK;
    selectedLanguageBitmapID = BITMAP_FLAG_DNK_ACTIVE_ID;
    setLanguage();
}

void ProductPresenterView::JPFlagClicked()
{
    selectedLanguage = JPN;
    selectedLanguageBitmapID = BITMAP_FLAG_JPN_ACTIVE_ID;
    setLanguage();
}

void ProductPresenterView::UAFlagClicked()
{
    selectedLanguage = UKR;
    selectedLanguageBitmapID = BITMAP_FLAG_UKR_ACTIVE_ID;
    setLanguage();
}

void ProductPresenterView::NLFlagClicked()
{
    selectedLanguage = NLD;
    selectedLanguageBitmapID = BITMAP_FLAG_NLD_ACTIVE_ID;
    setLanguage();
}

void ProductPresenterView::languageMenuAnimationEnd()
{
    if (languageMenu.getState() == SlideMenu::COLLAPSED)
    {
        languageMenu.setVisible(false);
        languageButton.setVisible(true);
        languageButton.invalidateContent();
    }
}

void ProductPresenterView::animateToPoster(int posterIndex, int duration)
{
    if (duration < 2)
    {
        headlineText.setTypedText(TypedText(getHeadline(posterIndex)));
        headlineText.invalidate();

        bodyText.setTypedText(TypedText(getBodyText(posterIndex)));
        bodyText.invalidate();

        poster.setBitmap(Bitmap(getPosterBitmap(posterIndex)));
    }
    else
    {
        nextButton.setTouchable(false);

        // Replace headlineText with swap text
        headlineTextSwap.setTypedText(headlineText.getTypedText());
        headlineTextSwap.setXY(headlineText.getX(), headlineText.getY());
        headlineTextSwap.invalidate();

        // Make headlineText ready to be animated in again
        headlineText.setTypedText(TypedText(getHeadline(posterIndex)));
        headlineText.moveTo(headlineTextSwap.getRect().right(), headlineTextSwap.getY());
        headlineText.invalidate();

        headlineTextSwap.startMoveAnimation(headlineTextSwap.getX() - headlineTextSwap.getWidth(), headlineTextSwap.getY(), duration, EasingEquations::cubicEaseInOut);
        headlineText.startMoveAnimation(headlineTextSwap.getX(), headlineTextSwap.getY(), duration, EasingEquations::cubicEaseInOut);

        // Start text fade
        bodyText.startFadeAnimation(0, duration);
        fadeDuration = duration;
        nextTextIndex = posterIndex;

        // Replace poster with swap poster
        posterSwap.setBitmap(Bitmap(poster.getBitmap()));
        posterSwap.setXY(poster.getX(), poster.getY());
        posterSwap.invalidate();

        // Make poster ready to be animated in again
        poster.setBitmap(Bitmap(getPosterBitmap(posterIndex)));
        poster.moveTo(posterSwap.getRect().right(), posterSwap.getY());
        poster.invalidate();

        posterSwap.startMoveAnimation(posterSwap.getX() - posterSwap.getWidth(), posterSwap.getY(), duration, EasingEquations::cubicEaseInOut);
        poster.startMoveAnimation(posterSwap.getX(), posterSwap.getY(), duration, EasingEquations::cubicEaseInOut);
    }

    selectedPoster = posterIndex;
}


void ProductPresenterView::setLanguage()
{
    Texts::setLanguage(selectedLanguage);
    bodyText.resizeToCurrentText();
    textAreaContainer.reset();
    textAreaContainer.invalidate();
    mcuLoad.invalidate();
    headlineText.invalidate();
    bodyText.invalidate();

    languageMenu.animateToState(SlideMenu::COLLAPSED);
    languageButton.setBitmaps(selectedLanguageBitmapID, selectedLanguageBitmapID);
    languageButton.invalidateContent();
}


touchgfx::BitmapId ProductPresenterView::getPosterBitmap(int index)
{
    switch (index)
    {
    default:
    case 0:
        return BITMAP_POSTER_IMAGE_00_ID;
    case 1:
        return BITMAP_POSTER_IMAGE_01_ID;
    case 2:
        return BITMAP_POSTER_IMAGE_02_ID;
    }
}

TEXTS ProductPresenterView::getHeadline(int index)
{
    switch (index)
    {
    default:
    case 0:
        return T_POSTER_HEADLINE_00;
    case 1:
        return T_POSTER_HEADLINE_01;
    case 2:
        return T_POSTER_HEADLINE_02;
    }
}

TEXTS ProductPresenterView::getBodyText(int index)
{
    switch (index)
    {
    default:
    case 0:
        return T_POSTER_TEXT_00;
    case 1:
        return T_POSTER_TEXT_01;
    case 2:
        return T_POSTER_TEXT_02;
    }
}

void ProductPresenterView::fadeAnimationEndedHandler(const FadeAnimator<TextArea>& textArea)
{
    if (&textArea == &bodyText)
    {
        if (bodyText.getAlpha() == 0)
        {
            bodyText.setTypedText(TypedText(getBodyText(nextTextIndex)));
            bodyText.resizeToCurrentText();
            bodyText.startFadeAnimation(255, fadeDuration);

            textAreaContainer.reset();
            textAreaContainer.invalidate();

            nextButton.setTouchable(true);
        }
    }
}
