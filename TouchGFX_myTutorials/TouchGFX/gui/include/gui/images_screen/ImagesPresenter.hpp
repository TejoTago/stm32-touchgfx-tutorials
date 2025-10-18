#ifndef IMAGESPRESENTER_HPP
#define IMAGESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ImagesView;

class ImagesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ImagesPresenter(ImagesView& v);

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

    virtual ~ImagesPresenter() {}

private:
    ImagesPresenter();

    ImagesView& view;
};

#endif // IMAGESPRESENTER_HPP
