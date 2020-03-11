#include "DonutMode.h"

DonutMode::DonutMode() {
  m_classicBoard = NULL;
  m_board = NULL;
}

DonutMode::DonutMode(GenerateBoard *b) {
  m_classicBoard = b;
  m_board = b->getBoard();
}

DonutMode::~DonutMode(){
  delete m_board;
}

int** DonutMode::iterateThroughBoard(GenerateBoard *b, int**current) {
  //dereference the board to get the 2d array
  const int height = b->getHeight();
  const int width = b->getWidth();
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
  return future;
}

int DonutMode::countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard*b) {
  int**currentBoard = b->getBoard();
  int numNeighbors = 0;
  if ((i == 0) || (j == 0) || (i == rows - 1) || (j == cols - 1)) {
    //TOP LEFT CORNER
    if (i == 0 && j == 0) {
      if (currentBoard[i][j + 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j+1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][cols-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][cols-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows-1][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows-1][j+1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows-1][cols-1] == 1) {
        ++numNeighbors;
      }
    }
    //TOP RIGHT CORNER
    if ((i == 0) && (j == cols  - 1)) {
      if (currentBoard[i][j-1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i+1][j-1] == 1) {
      ++numNeighbors;
      }
      if (currentBoard[i+1][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows-1][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows-1][j-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows-1][0] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][0] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][0] == 1) {
        ++numNeighbors;
      }
    }
    //BOTTOM LEFT CORNER
    if ((i == rows - 1) && (j == 0)) {
      if (currentBoard[i-1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j+1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[0][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[0][j+1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[0][cols-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i-1][cols-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[rows - 1][cols-1] == 1) {
        ++numNeighbors;
      }
    }
    //BOTTOM RIGHT CORNER
    if ((i == rows - 1) && (j == cols - 1)) {
      if (currentBoard[i-1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i-1][j - 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][j - 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[0][j] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][0] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i-1][0] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[0][0] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[0][j-1] == 1) {
        ++numNeighbors;
      }
    }
    //BOTTOM EDGES
    if ((i == (rows - 1)) && (j != 0) && (j != (cols - 1))){
      if (currentBoard[i][j-1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i-1][j - 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i-1][j] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i - 1][j+1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[0][j - 1] == 1){
      ++numNeighbors;
      }
      if (currentBoard[0][j] == 1){
      ++numNeighbors;
      }
      if (currentBoard[0][j+1] == 1){
      ++numNeighbors;
      }
    }
    //TOP EDGES
    if ((i == 0) && (j != 0 && (j != cols - 1))){
      if (currentBoard[i][j-1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i+1][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i+1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j+1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[rows - 1][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[rows - 1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[rows - 1][j + 1] == 1){
        ++numNeighbors;
      }
    }
    //RIGHT EDGES
    if (((i != 0) && (i != (rows - 1))) && (j == cols - 1)){
      if (currentBoard[0][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[0][j-1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i+1][j - 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i - 1][0] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][0] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][0] == 1){
        ++numNeighbors;
      }
    }
    //LEFT EDGES
    if (((j == 0) && (i != (rows - 1))) && (i != 0)){
      if (currentBoard[i-1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j + 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j+1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i - 1][cols-1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][cols-1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][cols-1] == 1){
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

int DonutMode::nextGenStatus(int previousStatus, int numNeighbors) {
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
