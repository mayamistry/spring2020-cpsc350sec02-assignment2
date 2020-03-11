#include "GameMode.h"

class MirrorMode : public GameMode{
  public:
    MirrorMode();
    MirrorMode(GenerateBoard *b);
    ~MirrorMode();
    int countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard *b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    int ** iterateThroughBoard(GenerateBoard *b, int**current);


    GenerateBoard *m_classicBoard;
    int **m_board;
};
