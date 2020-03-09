#include "GameMode.h"

class MirrorMode : public GameMode{
  public:
    MirrorMode();
    MirrorMode(GenerateBoard *b);
    ~MirrorMode();
    int countNumNeighbors(int i, int j, int rows, int cols, int** b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    void iterateThroughBoard();
    //other extra methods for donut

    GenerateBoard *m_classicBoard;
    int **m_board;
};
