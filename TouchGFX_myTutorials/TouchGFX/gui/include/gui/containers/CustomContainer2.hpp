#ifndef CUSTOMCONTAINER2_HPP
#define CUSTOMCONTAINER2_HPP

#include <gui_generated/containers/CustomContainer2Base.hpp>

class CustomContainer2 : public CustomContainer2Base
{
public:
    CustomContainer2();
    virtual ~CustomContainer2() {}

    virtual void initialize();
    void setIndex(int16_t index);
protected:
private:
    int16_t currentIndex;
};

#endif // CUSTOMCONTAINER2_HPP
