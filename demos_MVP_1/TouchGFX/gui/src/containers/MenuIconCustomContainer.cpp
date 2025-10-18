#include <gui/containers/MenuIconCustomContainer.hpp>
#include <BitmapDatabase.hpp>

MenuIconCustomContainer::MenuIconCustomContainer()
{

}

void MenuIconCustomContainer::initialize()
{
    MenuIconCustomContainerBase::initialize();
}

void MenuIconCustomContainer::setTheIcons(int itemIndex)
{
    switch (itemIndex % 4)
    {
    case 0:
        iconScalableImage.setBitmap(Bitmap(BITMAP_CONTROL_MENU_ICON_GAUGE_LARGE_ID));
        iconScalableImage.setXY(7, 3);
        break;

    case 1:
        iconScalableImage.setBitmap(Bitmap(BITMAP_CONTROL_MENU_ICON_THREE_WAY_LARGE_ID));
        iconScalableImage.setWidthHeight(26, 26);
        break;

    case 2:
        iconScalableImage.setBitmap(Bitmap(BITMAP_CONTROL_MENU_ICON_PERCENTAGE_LARGE_ID));
        iconScalableImage.setWidthHeight(26, 26);
        break;

    case 3:
        iconScalableImage.setBitmap(Bitmap(BITMAP_CONTROL_MENU_ICON_DATEPICKER_LARGE_ID));
        iconScalableImage.setWidthHeight(26, 26);
        break;
    }
}

void MenuIconCustomContainer::setY(int16_t y)
{
    MenuIconCustomContainerBase::setY(y);

    int iconGrowthSize = 2;
    const int itemOffset = 50;
    const int closenessToCenter = 18;
    const int shortWidthForIcon = 26;

    //Icon should be moved as it expands
    //or shrinks so it stays in center
    const int moveAmount = 1;

    if (abs(y - itemOffset) < closenessToCenter)
    {
        iconScalableImage.setXY(iconScalableImage.getX() - moveAmount, iconScalableImage.getY() - moveAmount);
        iconScalableImage.setWidthHeight(iconScalableImage.getWidth() + iconGrowthSize, iconScalableImage.getHeight() + iconGrowthSize);
    }
    else if (iconScalableImage.getWidth() > shortWidthForIcon)
    {
        iconGrowthSize *= -1;
        iconScalableImage.setXY(iconScalableImage.getX() + moveAmount, iconScalableImage.getY() + moveAmount);
        iconScalableImage.setWidthHeight(iconScalableImage.getWidth() + iconGrowthSize, iconScalableImage.getHeight() + iconGrowthSize);
    }
}
