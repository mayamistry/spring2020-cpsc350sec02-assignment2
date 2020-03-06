#include <iostream>
using namespace std;
#include "GenerateBoard.h"

class GameMode {
  public:
    GameMode(GenerateBoard *b);
    virtual int countNumMeighbors(int cell);
    virtual int nextGenStatus(int numNeighbors);
};
