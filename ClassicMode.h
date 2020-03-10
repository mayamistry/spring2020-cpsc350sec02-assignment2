#include "GameMode.h"

class ClassicMode : public GameMode{
  public:
    ClassicMode();
    ClassicMode(GenerateBoard *b);
    ~ClassicMode();
    int countNumNeighbors(int i, int j, int rows, int cols, int **currentBoard);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    void iterateThroughBoard(GenerateBoard *b);

    GenerateBoard *m_classicBoard;
};
