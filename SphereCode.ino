#include <SoftwareSerial.h>
#include <Button.h>
#include <GameCode.h>
#include <Helpers.h>

// Globals
const int ledPin          = 13;   // STM test LED 
const int buttonPin       = 23;   // STM test button
const int buttonPinWhite  = 3;    // External color button
const int buttonPinGreen  = 4;    // External color button
const int buttonPinRed    = 5;    // External color button
const int buttonPinBlue   = 6;    // External color button
const int buttonPinYellow = 7;    // External color button
const int buttonPinBlack  = 8;    // External color button

Button buttonList[6] = 
{ 
  Button(String("WhiteButton"), 'a', buttonPinWhite, INPUT_PULLUP, 25),
  Button(String("GreenButton"), 'e', buttonPinGreen, INPUT_PULLUP, 25),
  Button(String("RedButton"),   'p', buttonPinRed,   INPUT_PULLUP, 25),
  Button(String("BlueButton"),  'r', buttonPinBlue,  INPUT_PULLUP, 25),
  Button(String("YellowButton"),'s', buttonPinYellow,INPUT_PULLUP, 25),
  Button(String("BlackButton"), 't', buttonPinBlack, INPUT_PULLUP, 25),
};

int ledState = LOW;

// Where all the hardwarde setup takes place
void setup()
{
  Serial.begin(9600);

  Serial.println("Starting up");

  pinMode(ledPin, OUTPUT);

  for(int butCtr; butCtr < ARR_SIZE(buttonList); butCtr++)
  {
    buttonList[butCtr].setup();
  }
}

// Where the main loop actions
void loop()
{
  // Get an input from one of the buttons
  for(int butCtr; butCtr < ARR_SIZE(buttonList); butCtr++)
  {
    buttonList[butCtr].update();
    if(buttonList[butCtr].fell())
    {
      Game::UpdateGame(buttonList[butCtr].getLetter());
    }
  }
}

