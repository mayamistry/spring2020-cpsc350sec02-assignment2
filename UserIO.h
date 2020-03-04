#include <iostream>
#include "GameMode.h"
#include "GenerateBoard.h"

using namespace std;

class UserIO {
  public:
    UserIO();
    //overloaded constructor not needed
    ~UserIO();
    void promptForFileOrRandom();
    GameMode promptBoundary();
    void promptForSimulationType(); //pause, enter, or output file
};
