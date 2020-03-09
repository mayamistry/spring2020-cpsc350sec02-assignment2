#include "GameMode.h"

class DonutMode : public GameMode{
  public:
    DonutMode();
    DonutMode(GenerateBoard *b);
    ~DonutMode();
    int countNumNeighbors(int i, int j, int rows, int cols, int** b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    void iterateThroughBoard();
    //other extra methods for donut

    GenerateBoard *m_classicBoard;
    int **m_board;
};
