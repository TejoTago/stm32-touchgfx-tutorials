#ifndef MENUICONCUSTOMCONTAINER_HPP
#define MENUICONCUSTOMCONTAINER_HPP

#include <gui_generated/containers/MenuIconCustomContainerBase.hpp>

class MenuIconCustomContainer : public MenuIconCustomContainerBase
{
public:
    MenuIconCustomContainer();
    virtual ~MenuIconCustomContainer() {}

    virtual void initialize();

    void setTheIcons(int itemIndex);

    virtual void setY(int16_t y);
protected:
};

#endif // MENUICONCUSTOMCONTAINER_HPP
