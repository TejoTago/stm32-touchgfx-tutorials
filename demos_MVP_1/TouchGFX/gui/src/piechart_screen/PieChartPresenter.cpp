#include <gui/piechart_screen/PieChartView.hpp>
#include <gui/piechart_screen/PieChartPresenter.hpp>

PieChartPresenter::PieChartPresenter(PieChartView& v)
    : view(v)
{

}

void PieChartPresenter::activate()
{

}

void PieChartPresenter::deactivate()
{

}

void PieChartPresenter::mcuLoadUpdated(uint8_t mcuLoadValue)
{
    view.updateProcessorLoad(mcuLoadValue);
}
