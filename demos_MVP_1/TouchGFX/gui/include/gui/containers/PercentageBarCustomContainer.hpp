#ifndef PERCENTAGEBARCUSTOMCONTAINER_HPP
#define PERCENTAGEBARCUSTOMCONTAINER_HPP

#include <gui_generated/containers/PercentageBarCustomContainerBase.hpp>

class PercentageBarCustomContainer : public PercentageBarCustomContainerBase
{
public:
    PercentageBarCustomContainer();
    virtual ~PercentageBarCustomContainer() {}

    virtual void initialize();

    void dragEventCalled(const DragEvent& Event);

protected:

    const int centerOfTheCircleProgress;

    Callback<PercentageBarCustomContainer, const CircleProgress&, const ClickEvent&> percentageBarClickCallback;
    void clickAction(const CircleProgress& object, const ClickEvent& Event);

    void updateCircleProgress(int newX, int newY, int centerX, int centerY);
    void setCircleProgressAngle(int angleInDegrees);
};

#endif // PERCENTAGEBARCUSTOMCONTAINER_HPP
