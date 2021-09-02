#include "Button.h"

Button::Button(String name, char letter, int pin, int mode, unsigned short debounceInterval)
{
    mPin    = pin;
    mMode   = mode;
    mName   = name;
    mLetter = letter;
    mDebounceInterval = debounceInterval;
    mBounce = Bounce();
}

void Button::setup()
{ 
    mBounce.attach(mPin, mMode);
    mBounce.interval(mDebounceInterval);
}

void Button::update()    { mBounce.update(); }
bool Button::fell()      { return mBounce.fell(); }
bool Button::rose()      { return mBounce.rose(); }
char Button::getLetter() { return mLetter; }
String Button::getName() { return mName; }

