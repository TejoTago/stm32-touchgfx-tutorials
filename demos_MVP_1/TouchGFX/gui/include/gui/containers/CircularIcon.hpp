#ifndef CIRCULARICON_HPP
#define CIRCULARICON_HPP

#include <gui_generated/containers/CircularIconBase.hpp>

class CircularIcon : public CircularIconBase
{
public:
    CircularIcon();
    virtual ~CircularIcon() {}

    virtual void initialize();

    virtual void emitStartAnimationCallback();

    void setIconImage(const Bitmap& bmp);

    void changePercentage(int newValue);
protected:
};

#endif // CIRCULARICON_HPP
