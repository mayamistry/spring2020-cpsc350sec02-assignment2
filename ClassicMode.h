#include "GameMode.h"

class ClassicMode : public GameMode{
  public:
    ClassicMode();
    ClassicMode(GenerateBoard *b);
    int countNumMeighbors(int cell);
    int nextGenStatus(int numNeighbors);

    //helper functions
  private:
    GenerateBoard *board;
};
