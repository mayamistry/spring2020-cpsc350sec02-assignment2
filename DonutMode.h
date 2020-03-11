#include "GameMode.h"

class DonutMode : public GameMode{
  public:
    DonutMode();
    DonutMode(GenerateBoard *b);
    ~DonutMode();
    int countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard *b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    int ** iterateThroughBoard(GenerateBoard *b, int**current);

    GenerateBoard *m_classicBoard;
    int **m_board;
};
