#include <gui/containers/CircularIcon.hpp>

CircularIcon::CircularIcon()
{

}

void CircularIcon::initialize()
{
    CircularIconBase::initialize();
}

void CircularIcon::emitStartAnimationCallback()
{

    CircularIconBase::emitStartMovingAnimationCallback();

}

void CircularIcon::setIconImage(const Bitmap& bmp)
{
    icon.setBitmap(bmp);
}

void CircularIcon::changePercentage(int newValue)
{
    Unicode::snprintf(percentageBuffer, PERCENTAGE_SIZE, "%d", newValue);
    percentage.invalidate();
}
