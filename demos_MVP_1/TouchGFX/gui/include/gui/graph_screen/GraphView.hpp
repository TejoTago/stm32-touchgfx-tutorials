#ifndef GRAPH_VIEW_HPP
#define GRAPH_VIEW_HPP

#include <gui_generated/graph_screen/GraphViewBase.hpp>
#include <gui/graph_screen/GraphPresenter.hpp>

class GraphView : public GraphViewBase
{
public:
    GraphView();
    virtual ~GraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateGraphSettings();
    virtual void handleTickEvent();
    virtual void clearGraphs();
    void updateProcessorLoad(uint8_t mcuLoadValue);
protected:
    int pointCounter;
    int graphX;
    int graphType;
};

#endif // GRAPHVIEW_HPP
