#include <Bounce2.h>

#ifndef Button_h
#define Button_h

class Button
{
    public:
        Button();
        Button(String name, char letter, int pin, int mode, unsigned short debounceInterval);
        void setup();
        void update();
        bool fell();
        bool rose();
        char getLetter();
        String getName();

    private:
        Bounce mBounce;
        String mName;
        char mLetter;
        int mMode;
        int mPin;
        unsigned short mDebounceInterval;
};

#endif
