#include "GameMode.h"

//Mirror mode - inherited from GameMode
class MirrorMode : public GameMode{
  public:
    MirrorMode();
    MirrorMode(GenerateBoard *b);
    ~MirrorMode();
    int countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard *b);
    int nextGenStatus(int previousStatus, int numNeighbors);

    int ** iterateThroughBoard(GenerateBoard *b, int**current);

    GenerateBoard *m_classicBoard;
    int **m_board;
};
