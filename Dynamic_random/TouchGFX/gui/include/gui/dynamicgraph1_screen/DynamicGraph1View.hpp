#ifndef DYNAMICGRAPH1VIEW_HPP
#define DYNAMICGRAPH1VIEW_HPP

#include <gui_generated/dynamicgraph1_screen/DynamicGraph1ViewBase.hpp>
#include <gui/dynamicgraph1_screen/DynamicGraph1Presenter.hpp>

class DynamicGraph1View : public DynamicGraph1ViewBase
{
public:
    DynamicGraph1View();
    virtual ~DynamicGraph1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DYNAMICGRAPH1VIEW_HPP
