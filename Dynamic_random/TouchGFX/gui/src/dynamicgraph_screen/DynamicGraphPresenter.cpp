#include <gui/dynamicgraph_screen/DynamicGraphView.hpp>
#include <gui/dynamicgraph_screen/DynamicGraphPresenter.hpp>

DynamicGraphPresenter::DynamicGraphPresenter(DynamicGraphView& v)
    : view(v)
{

}

void DynamicGraphPresenter::activate()
{
	view.setBlue(model->getBlue());
	view.setGreen(model->getGreen());
}

void DynamicGraphPresenter::deactivate()
{

}

void DynamicGraphPresenter::setBlue(bool state)
{
	model->userSetBlue(state);
}

void DynamicGraphPresenter::setGreen(bool state)
{
	model->userSetGreen(state);
}
