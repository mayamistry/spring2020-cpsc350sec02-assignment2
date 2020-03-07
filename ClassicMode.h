#include "GameMode.h"

class ClassicMode : public GameMode{
  public:
    ClassicMode() : GameMode(){m_classicBoard = NULL; board = NULL;}
    ClassicMode(GenerateBoard *b) : GameMode(b){
      m_board = b;
      board = b->getBoard();
    }
    ~ClassicMode();
    int countNumMeighbors(int i, int j, int rows, int cols);
    int nextGenStatus(int previousStatus, int numNeighbors);

    //helper functions
    void iterateThroughBoard();

    GenerateBoard *m_classicBoard;
    int **board;
};
