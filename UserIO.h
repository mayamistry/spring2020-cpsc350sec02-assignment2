#include <iostream>
#include <math.h>
#include <string>
#include "SimulateGame.h"
using namespace std;

class UserIO {
  public:
    UserIO();
    //overloaded constructor not needed
    ~UserIO();
    void start();
    GenerateBoard* promptForFileOrRandom();
    string promptBoundary(GenerateBoard *b);
    string promptForSimulationType(); //pause, enter, or output file

    GenerateBoard* getBoard();
    string getGameMode();
    string getPlayType();

    GenerateBoard *m_board;
    string m_modeInput;
    string m_playType;
};
