#include "GenerateBoard.h"

//default constructor
GenerateBoard::GenerateBoard() {
  m_height = 10;
  m_width = 10;
  m_density = 0.0;
}

//overloaded constructor
GenerateBoard::GenerateBoard(int h, int w, float d) {
  m_height = h;
  m_width = w;
  m_density = d;
}

//copy constructor
// GenerateBoard::GenerateBoard(const GenerateBoard& b) {
//   m_height = &b->getHeight();
//   m_width  = &b->getWidth();
//   m_density = &b->getDensity();
// }

GenerateBoard::~GenerateBoard() {
   delete board;
}

void GenerateBoard::setHeight(int h) {
  m_height = h;
}

void GenerateBoard::setWidth(int w) {
  m_width = w;
}

int GenerateBoard::getHeight() {
  return m_height;
}

int GenerateBoard::getWidth() {
  return m_width;
}

void GenerateBoard::setDensity(float d) {
  m_density = d;
}

float GenerateBoard::getDensity() {
  return m_density;
}

int** GenerateBoard::getBoard(){
  return board;
}

void GenerateBoard::initializeBoard(int h, int w) {
  board = new int*[w];
  for (int i = 0; i < w; ++i) {
    board[i] = new int[h];
  }
}

void GenerateBoard::createFromFile(string fileName) {
  ifstream inFS;
  string currentLine = "";
  int lineCount = 1;

  inFS.open(fileName);

  //check if the file can be opened
  if (!inFS.is_open()) {
    cout << "Could not open file." << endl;
    // return 1; figure out how to do later
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
        initializeBoard(m_height,m_width);
      } else {
        for (int i = 0; i < m_width; ++i) {
          for (int j = 0; j < m_height; ++j) {
            if (currentLine == "-") {
              board[i][j] = 0;
            } else if (currentLine == "X"){
              board[i][j] = 1;
            }
          }
        }
      }
    }
    lineCount++;
  }
}

void GenerateBoard::createRandom(int h, int w, float randDecimal) {
  initializeBoard(h,w);
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
