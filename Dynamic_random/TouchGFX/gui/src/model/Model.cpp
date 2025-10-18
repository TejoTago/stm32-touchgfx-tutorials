#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0),stateBlue(true), stateGreen(true)
{

}

void Model::tick()
{

}

void Model::userSetBlue(bool state)
{
	stateBlue = state;
}

void Model::userSetGreen(bool state)
{
	stateGreen = state;
}
