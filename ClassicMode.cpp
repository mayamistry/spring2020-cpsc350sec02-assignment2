#include "ClassicMode.h"

ClassicMode::~ClassicMode(){
  delete m_board;
}

void ClassicMode::iterateThroughBoard() {
  //dereference the board to get the 2d array
  //nothing below this will work right not because m_board isn't recognized for some reason
  int rows = m_board->getWidth(); //why is this an error??
  int cols = m_board->getHeight();
  board = **m_board->getBoard();
}

int countNumMeighbors(int i, int j, int rows, int cols) {
  int numNeighbors = 0;
  //special case:corners:
  if (i == 0 || j == 0) {
    //check if corner (0,0)
    if (i == 0 && j == 0) {
      if (board[i][j + 1] == 1) {
        ++numNeighbors;
      }
      if (board[i+1][j] == 1) {
        ++numNeighbors;
      }
      if (board[i+1][j+1]) {
        ++numNeighbors;
      }
    }
    //check if corner (0,cols-1)
    if (i == 0 && j == cols  - 1) {
      if (board[i][j-1] == 1) {
        ++numNeighbors;
      }
      if (board[i+1][j-1] == 1) {
        ++numNeighbors;
      }
      if (board[i+1][j]) {
        ++numNeighbors;
      }
    }
    //check if corner (rows - 1, 0)
    if (i == rows - 1 && j == 0) {
      if (board[i - 1][j] == 1) {
        ++numNeighbors;
      }
      if (board[i - 1][j + 1] == 1) {
        ++numNeighbors;
      }
      if (board[i][j+1]) {
        ++numNeighbors;
      }
    }
    //check if corner (rows - 1, cols - 1)
    if (i == rows - 1 && j == cols - 1) {
      if (board[i][j - 1] == 1) {
        ++numNeighbors;
      }
      if (board[i - 1][j - 1] == 1) {
        ++numNeighbors;
      }
      if (board[i - 1][j]) {
        ++numNeighbors;
      }
    }
    //check if right edge
    //check if left edge
    //check if top edge
    //check if bottom edge
  } else {
    //perform normal function
  }
  return numNeighbors;
}

int nextGenStatus(int previousStatus, int numNeighbors) {
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
  return num;
}
