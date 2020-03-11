#include <iostream>
#include <math.h>
#include <string>
#include "SimulateGame.h"
using namespace std;

//Class where all of the UserIO occurs and stores whatever information is inputted by the user
class UserIO {
  public:
    UserIO();
    //overloaded constructor not needed
    ~UserIO();
    void start();
    GenerateBoard* promptForFileOrRandom();
    string promptBoundary();
    string promptForSimulationType(); //pause, enter, or output file

    GenerateBoard* getBoard();
    string getGameMode();
    string getPlayType();

    GenerateBoard *m_board;
    string m_modeInput;
    string m_playType;
};
