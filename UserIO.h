#include <iostream>
#include "GameMode.h"

using namespace std;

class UserIO {
  public:
    UserIO();
    //overloaded constructor not needed
    ~UserIO();
    void start();
    GenerateBoard* promptForFileOrRandom();
    GameMode* promptBoundary(GenerateBoard *b);
    void promptForSimulationType(); //pause, enter, or output file

    GenerateBoard *m_board;
    GameMode *m_gameMode;
};
