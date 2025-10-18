#ifndef IMAGESVIEW_HPP
#define IMAGESVIEW_HPP

#include <gui_generated/images_screen/ImagesViewBase.hpp>
#include <gui/images_screen/ImagesPresenter.hpp>

class ImagesView : public ImagesViewBase
{
public:
    ImagesView();
    virtual ~ImagesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // IMAGESVIEW_HPP
