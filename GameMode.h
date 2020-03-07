#ifndef __GameMode__h
#define __GameMode__h
#include <iostream>
using namespace std;
#include "GenerateBoard.h"

class GameMode {
  public:
    GameMode();
    GameMode(GenerateBoard *b);
    ~GameMode();
    virtual int countNumMeighbors(int cell);
    virtual int nextGenStatus(int numNeighbors);
    GenerateBoard *m_board;
};
#endif
