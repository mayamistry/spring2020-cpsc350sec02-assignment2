#include "ClassicMode.h"

ClassicMode::ClassicMode() {
  m_classicBoard = NULL;
}

ClassicMode::ClassicMode(GenerateBoard *b) {
  m_classicBoard = b;
}

ClassicMode::~ClassicMode(){
  delete m_classicBoard;
}

int ** ClassicMode::iterateThroughBoard(GenerateBoard *b) {
  //dereference the board to get the 2d array
  const int height = b->getHeight();
  const int width = b->getWidth();
  int **current = b->getBoard();
  //did wrong at first and stored on stack, now stored on heap
  int** future = new int* [height];
  for (int i = 0; i < height; ++i){
    future[i] = new int[width];
  }


  int neighborCount = 0;
  int newCell = 0;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      //Segmentation fault update: it is not moving down to the next row
      neighborCount = countNumNeighbors(i,j,height,width,b); //SEGMENTATION FAULT
      newCell = nextGenStatus(current[i][j],neighborCount);
      future[i][j] = newCell;
    }
  }

  // current = m_classicBoard->getBoard();

  // // current = m_classicBoard->getBoard(); //SEGMENTATION FAULT OCCURS HERE
  // for (int i = 0; i < rows; ++i) {
  //   for (int j = 0; j < cols; ++j) {
  //     current
  //   }
  // }
  //


  // int newCell = 0;
  // int value = 0;
  // int neighborCount = 0;
  // for (int i = 0; i < rows; ++i) {
  //   for (int j = 0; j < cols; ++j) {
  //     current[i][j] = value;
  //     cout << value << endl;
  //     neighborCount = countNumNeighbors(i, j, rows, cols, b);
  //     newCell = nextGenStatus(value, neighborCount);
  //     // future[i][j] = newCell;
  //   }
  // }
  return future;
}

int ClassicMode::countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard *b) {
  int **currentBoard = b->getBoard();
  int numNeighbors = 0;
  //special case:corners:
  if ((i == 0) || (j == 0) || (i == rows - 1) || (j == cols - 1)) {
    //check if corner (0,0)
    if (i == 0 && j == 0) {
      if (currentBoard[i][j + 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j+1] == 1) {
        ++numNeighbors;
      }
    }
    //check if corner (0,cols-1)
    if ((i == 0) && (j == cols  - 1)) {
      if (currentBoard[i][j-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j] == 1) {
        ++numNeighbors;
      }
    }
    //check if corner (rows - 1, 0)
    if ((i == rows - 1) && (j == 0)) {
      if (currentBoard[i - 1][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j + 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][j+1] == 1) {
        ++numNeighbors;
      }
    }
    //check if corner (rows - 1, cols - 1)
    if ((i == rows - 1) && (j == cols - 1)) {
      if (currentBoard[i][j - 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j - 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j] == 1) {
        ++numNeighbors;
      }
    }
    //top
    if ((i == 0) && (j != 0 && (j != cols - 1))){
      if (currentBoard[i][j - 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i + 1][j] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i+1][j - 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i + 1][j + 1] == 1){
      ++numNeighbors;
      }
    }
    //bottom
    if ((i == (rows - 1)) && (j != 0) && (j != (cols - 1))){
      if (currentBoard[i][j - 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i - 1][j] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i - 1][j - 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i - 1][j + 1] == 1){
      ++numNeighbors;
      }
    }
    //left edge
    if (((j == 0) && (i != (rows - 1))) && (i != 0)){
      if (currentBoard[i + 1][j + 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i + 1][j] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i - 1][j] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i - 1][j + 1] == 1){
      ++numNeighbors;
      }
    }
    //right edge
    if (((i != 0) && (i != (rows - 1))) && (j == cols - 1)){
      if (currentBoard[i + 1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j] == 1){
        ++numNeighbors;
      }
    }
  } else {
    if (currentBoard[i-1][j-1] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i][j-1] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i+1][j-1] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i-1][j] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i+1][j] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i-1][j+1] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i][j+1] == 1) {
      ++numNeighbors;
    }
    if (currentBoard[i+1][j+1] == 1) {
      ++numNeighbors;
    }
  }
  return numNeighbors;
}

int ClassicMode::nextGenStatus(int previousStatus, int numNeighbors) {
  int newCell = 0;
  if (numNeighbors <= 1) {
    newCell = 0;
  } else if (numNeighbors == 2) {
    newCell = previousStatus;
  } else if (numNeighbors == 3) {
    newCell = 1;
  } else if (numNeighbors >= 4) {
    newCell = 0;
  }
  return newCell;
}
