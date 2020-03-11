#ifndef __GameMode__h
#define __GameMode__h
#include "GenerateBoard.h"

//Abstract class for the game modes: classic, mirror and donut
class GameMode {
  public:
    virtual int countNumMeighbors(int i, int j, int rows, int cols, int** b){}
    virtual int nextGenStatus(int previousStatus, int numNeighbors){};
};
#endif
