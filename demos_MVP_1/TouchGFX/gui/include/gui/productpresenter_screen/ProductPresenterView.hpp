#ifndef PRODUCTPRESENTER_VIEW_HPP
#define PRODUCTPRESENTER_VIEW_HPP

#include <gui_generated/productpresenter_screen/ProductPresenterViewBase.hpp>
#include <gui/productpresenter_screen/ProductPresenterPresenter.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <BitmapDatabase.hpp>

class ProductPresenterView : public ProductPresenterViewBase
{
public:
    ProductPresenterView();
    virtual ~ProductPresenterView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateProcessorLoad(uint8_t mcuLoadValue);

    virtual void nextbuttonPressed();
    virtual void languageButtonClicked();
    virtual void GBFlagClicked();
    virtual void DKFlagClicked();
    virtual void JPFlagClicked();
    virtual void UAFlagClicked();
    virtual void NLFlagClicked();
    virtual void languageMenuAnimationEnd();

protected:
    static const uint8_t NUMBER_OF_POSTERS = 3;

    int selectedPoster;
    int nextTextIndex;
    int fadeDuration;

    Callback<ProductPresenterView, const FadeAnimator<TextArea>&> onFadeAnimationEnded;
    void fadeAnimationEndedHandler(const FadeAnimator<TextArea>& textArea);

    void animateToPoster(int posterIndex, int duration);

    void setLanguage();
    BitmapId getPosterBitmap(int index);
    TEXTS getHeadline(int index);
    TEXTS getBodyText(int index);

    LANGUAGES selectedLanguage;
    int selectedLanguageBitmapID;
};

#endif // PRODUCTPRESENTER_VIEW_HPP
