#include <iostream>
#include "GameMode.h"
#include "GenerateBoard.h"

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
};
