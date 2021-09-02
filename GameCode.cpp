#include <SoftwareSerial.h>
#include <GameCode.h>
#include <GameWords.h>
#include <Helpers.h>

#define DEBUG 0

namespace Game
{
    enum GameState {
        NA,
        FAIL,
        SUCCESS
    };

    bool gameStarted         = false;
    const int numberOfRounds = 5;
    int currentRound         = 0;
    int currentCharIndex     = 0;
    int currentWordIndex     = 0;
    GameState gameState      = NA; 
    const int maxHealth      = 5;
    int health               = 5;

    void GameStart()
    {
        Serial.println("-------------------------------------------------");
        Serial.println("|        Spell Sphere v0.00000000000000001      |");
        Serial.println("-------------------------------------------------");
        Serial.println("Welcome, ya jabronie!!");
        Serial.println("Prepare yourself for a hardcore spelltastic asskicking experience!");
        Serial.println("Press a button to begin");
        Serial.println("");
    }

    void UpdateGame(char inputChar)
    {
        if(!gameStarted)
        {
            // Set the initial variables
            gameStarted      = true;
            health           = maxHealth;
            currentRound     = 0;
            currentCharIndex = 0;
            gameState        = NA;
            GameStart();
            GameUpdateRound();
        }
        else
        {
            GameUpdateSpellAttempt(inputChar);
        }
    }

    void GameUpdateRound()
    {
        if(currentRound <= numberOfRounds)
        {
            currentWordIndex = random(0,ARR_SIZE(possibleWords));
            Serial.println(String("Round "  + String(currentRound) + ", spell this:"));
            Serial.println(String(possibleWords[currentWordIndex]));
        }
        else
        {
            gameState = SUCCESS;
            GameEnd();
        }
    }

    void GameUpdateSpellAttempt(char inputChar)
    {
        char expectedChar = possibleWords[currentWordIndex].charAt(currentCharIndex);

        #if DEBUG == 1

        Serial.println(" ");
        Serial.println("Expected char: " + String(expectedChar));
        Serial.println("Current char index: " + String(currentCharIndex));
        Serial.println("Current health: " + String(health));
        Serial.println("Current word length: " + String(possibleWords[currentWordIndex].length()));

        #endif

        if(inputChar == expectedChar)
        {
            currentCharIndex++;
            Serial.print(inputChar);
            if(currentCharIndex == possibleWords[currentWordIndex].length())
            {
                // Word should be completed at this point
                currentCharIndex = 0;
                currentRound++;
                Serial.println("");
                Serial.println("Nice!");
                GameUpdateRound();
            }
        }
        else
        {

            Serial.print("*");
            if(health == 1)
            {
                Serial.println("");
                gameState = FAIL;
                GameEnd();
            }
            else
            {
                health--;
            }
        }
    }

    void GameEnd()
    {
        if(gameState == SUCCESS)
        {
            Serial.println("-------------------------------------------------");
            Serial.println("|                YOOO WOOONN!!!!                |");
            Serial.println("-------------------------------------------------");
            Serial.println("Holy crap, we've never seen such skill, such raw untempered force of will, you should be proud");
            Serial.println("");
        }
        else if (gameState == FAIL)
        {
            Serial.println("-------------------------------------------------");
            Serial.println("|                YOOO LOOOOSEEE!!!!              |");
            Serial.println("-------------------------------------------------");
            Serial.println("It was to bee expected... only a meager few have made it past the jaws of the spell sphere...");
            Serial.println("");
            gameStarted = false;
        }
    }
}