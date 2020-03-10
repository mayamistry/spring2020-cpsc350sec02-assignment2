#ifndef __GameMode__h
#define __GameMode__h
#include "GenerateBoard.h"

class GameMode {
  public:
    virtual int countNumMeighbors(int i, int j, int rows, int cols, int** b){}
    virtual int nextGenStatus(int previousStatus, int numNeighbors){};
};
#endif
