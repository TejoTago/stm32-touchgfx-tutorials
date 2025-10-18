#ifndef LOGOBAR_HPP
#define LOGOBAR_HPP

#include <gui_generated/containers/LogoBarBase.hpp>

class LogoBar : public LogoBarBase
{
public:
    LogoBar();
    virtual ~LogoBar() {}

    virtual void initialize();
protected:
};

#endif // LOGOBAR_HPP
