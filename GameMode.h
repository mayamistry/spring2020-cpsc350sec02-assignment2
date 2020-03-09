#ifndef __GameMode__h
#define __GameMode__h
#include "GenerateBoard.h"

class GameMode {
  public:
    virtual int countNumMeighbors(int cell){}
    virtual int nextGenStatus(int numNeighbors){};
};
#endif
