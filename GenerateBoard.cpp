#include "GenerateBoard.h"

//default constructor
GenerateBoard::GenerateBoard() {
  m_height = 10;
  m_width = 10;
}

//overloaded constructor
GenerateBoard::GenerateBoard(int h, int w) {
  m_height = h;
  m_width = w;
}

//copy constructor
GenerateBoard::GenerateBoard(GenerateBoard b) {
  m_height = b->getHeight();
  m_width  = b->getWidth();
}

GenerateBoard::~GenerateBoard() {
   delete board;
}

GenerateBoard::setHeight(int h) {
  m_height = h;
}

GenerateBoard::setWidth(int w) {
  m_widht = w;
}

GenerateBoard::getHeight() {
  return m_height;
}

GenerateBoard::getWidth() {
  return m_width;
}

GenerateBoard::createFromFile(string fileName) {
  ifstream inFS;
  string currentLine = "";
  int lineCount = 1;

  inFS.open(fileName);

  //check if the file can be opened
  if (!inFS.is_open()) {
    cout << "Could not open file." << endl;
    return 1;
  }

  //start reading the file
  while (!inFS.eof()) {
    //specifically read the first two lines of the file to get dimensions
    inFS >> currentLine;
    if (!inFS.fail()){
      if (lineCount = 1) {
        m_height = stoi(currentLine); //convert from string to int
      } else if (lineCount = 2) {
        m_width = stoi(currentLine); //convert from string to int
        board = new board[m_height][m_width];
      } else {
        for (int i = 0; i < m_width; ++i) {
          for (int j = 0; j < m_height; ++j) {
            if (currentLine == '-') {
              board[i][j] = 0;
            } else if (currentLine == 'X'){
              board[i][j] = 1;
            }
          }
        }
      }
    }
    lineCount++;
  }
}

GenerateBoard::createRandom(int h, int w, float randDecimal) {
  board = new board[h][w];
  int totalBoxes = h * w;
  int density  = (int)randDecimal * totalBoxes;
  int currentCell = 0;
  int tempCount = 0;

  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (tempCount < density) {
        currentCell = rand() % 2;
        if (currentCell == 1) {
          ++tempCount;
        }
      } else {
        currentCell = 0;
      }
      board[i][j] = currentCell;
    }
  }
}
