#ifndef GameCode_h
#define GameCode_h

namespace Game
{
    void GameStart();

    void UpdateGame(char inputChar);

    void GameUpdateRound();

    void GameUpdateSpellAttempt(char inputChar);

    void GameEnd();

}

#endif