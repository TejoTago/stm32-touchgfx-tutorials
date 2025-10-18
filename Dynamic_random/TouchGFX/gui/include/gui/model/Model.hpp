#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void userSetBlue(bool state);
    bool getBlue()
    {
    	return stateBlue;
    };
    void userSetGreen(bool state);
    bool getGreen()
    {
    	return stateGreen;
    };
protected:
    ModelListener* modelListener;
    bool stateBlue;
    bool stateGreen;
};

#endif // MODEL_HPP
