#ifndef MYICON_HPP
#define MYICON_HPP

#include <gui_generated/containers/myIconBase.hpp>
//#include <images/BitmapDatabase.hpp>

class myIcon : public myIconBase
{
public:
    myIcon();
    virtual ~myIcon() {}

    virtual void initialize();

    void setNumber(int no)
        {
            Unicode::itoa(no, textBuffer, TEXT_SIZE, 10);
            switch (no % 5)
            {
            case 0:
            icon.setBitmap(Bitmap(11));
                break;
            case 1:
            icon.setBitmap(Bitmap(12));
                break;
            case 2:
            icon.setBitmap(Bitmap(13));
                break;
            case 3:
            icon.setBitmap(Bitmap(18));
                break;
            case 4:
            icon.setBitmap(Bitmap(19));
                break;
            }
protected:
};

#endif // MYICON_HPP
