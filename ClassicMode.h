#include "GameMode.h"

////Classic mode - inherited from GameMode
class ClassicMode : public GameMode{
  public:
    ClassicMode();
    ClassicMode(GenerateBoard *b);
    ~ClassicMode();
    int countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard *b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    int ** iterateThroughBoard(GenerateBoard *b, int**current);

    GenerateBoard *m_classicBoard;
};
