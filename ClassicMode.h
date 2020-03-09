#include "GameMode.h"

class ClassicMode : public GameMode{
  public:
    ClassicMode();
    ClassicMode(GenerateBoard *b);
    ~ClassicMode();
    int countNumNeighbors(int i, int j, int rows, int cols, int** b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    void iterateThroughBoard();

    GenerateBoard *m_classicBoard;
    int **m_board;
};
