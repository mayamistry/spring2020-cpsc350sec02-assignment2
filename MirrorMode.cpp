#include "MirrorMode.h"

//Default constructor
MirrorMode::MirrorMode() {
  m_classicBoard = NULL;
  m_board = NULL;
}

//Overloaded constructor
MirrorMode::MirrorMode(GenerateBoard *b) {
  m_classicBoard = b;
  m_board = b->getBoard();
}

//Destructor
MirrorMode::~MirrorMode(){
  delete m_board;
}

//Function that returns a new board of values after calculating number of neigbors and new status for each cell
int** MirrorMode::iterateThroughBoard(GenerateBoard *b, int**current) {
  const int height = b->getHeight();
  const int width = b->getWidth();
  //create a new 2d array of pointers and put all the new values on future gen board
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

//Helper function to count the neighbors for an individual cell
int MirrorMode::countNumNeighbors(int i, int j, int rows, int cols, GenerateBoard*b) {
  int**currentBoard = b->getBoard();
  int numNeighbors = 0;
  //special case:corners:
  if ((i == 0) || (j == 0) || (i == rows - 1) || (j == cols - 1)) {
    //check if corner (0,0)
    if (i == 0 && j == 0) {
      if (currentBoard[i][j] == 1){
        numNeighbors += 3;
      }
      if (currentBoard[i][j + 1] == 1) {
        numNeighbors += 2;
      }
      if (currentBoard[i+1][j] == 1) {
        numNeighbors += 2;
      }
      if (currentBoard[i+1][j+1] == 1) {
        ++numNeighbors;
      }
    }
    //top right corner
    if ((i == 0) && (j == cols  - 1)) {
      if (currentBoard[i][j] == 1) {
        numNeighbors += 3;
      }
      if (currentBoard[i][j-1] == 1) {
        numNeighbors += 2;
      }
      if (currentBoard[i+1][j-1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i+1][j] == 1) {
        numNeighbors += 2;
      }
    }
    //bottom left corner
    if ((i == rows - 1) && (j == 0)) {
      if (currentBoard[i][j] == 1){
        numNeighbors += 3;
      }
      if (currentBoard[i - 1][j] == 1) {
        numNeighbors += 2;
      }
      if (currentBoard[i - 1][j + 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i][j+1] == 1) {
        numNeighbors += 2;
      }
    }
    //bottom right corner
    if ((i == rows - 1) && (j == cols - 1)) {
      if (currentBoard[i][j] == 1){
        numNeighbors += 3;
      }
      if (currentBoard[i][j - 1] == 1) {
        numNeighbors += 2;
      }
      if (currentBoard[i - 1][j - 1] == 1) {
        ++numNeighbors;
      }
      if (currentBoard[i - 1][j] == 1) {
        numNeighbors += 2;
      }
    }
    //top
    if ((i == 0) && (j != 0 && (j != cols - 1))){
      if (currentBoard[i][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j - 1] == 1){
        numNeighbors += 2;
      }
      if (currentBoard[i][j + 1] == 1){
        numNeighbors += 2;
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
      if (currentBoard[i][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j - 1] == 1){
        numNeighbors += 2;
      }
      if (currentBoard[i][j + 1] == 1){
        numNeighbors += 2;
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
      if (currentBoard[i][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j + 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i][j + 1] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j] == 1){
        numNeighbors += 2;
      }
      if (currentBoard[i - 1][j] == 1){
        numNeighbors += 2;
      }
      if (currentBoard[i - 1][j + 1] == 1){
        ++numNeighbors;
      }
    }
    //right edge
    if (((i != 0) && (i != (rows - 1))) && (j == cols - 1)){
      if (currentBoard[i][j] == 1){
        ++numNeighbors;
      }
      if (currentBoard[i + 1][j] == 1){
        numNeighbors += 2;
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
        numNeighbors += 2;
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

//Helper function to see what the status is for cell in the next generation 
int MirrorMode::nextGenStatus(int previousStatus, int numNeighbors) {
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
