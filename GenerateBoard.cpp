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
  board = new int*[h];
  for (int i = 0; i < h; ++i) {
    board[i] = new int[w];
  }
}

void GenerateBoard::createFromFile(string fileName) {
  ifstream inFS;
  string currentLine = "";
  int lineCount = 1;
  int i = 0;

  inFS.open(fileName);

  //check if the file can be opened
  if (!inFS.is_open()) {
    cout << "Could not open file. Start program over." << endl;
    // return;
  }

  //start reading the file
  while (!inFS.eof()) {
    //specifically read the first two lines of the file to get dimensions
    inFS >> currentLine;
    if (!inFS.fail()){
      if (lineCount == 1) {
        m_height = stoi(currentLine); //convert from string to int
        cout << "Height: " << m_height << endl;
      } else if (lineCount == 2) {
        m_width = stoi(currentLine); //convert from string to int
        cout << "Width: " << m_width << endl;
        initializeBoard(m_height,m_width);
      } else {
        for (int j = 0; j < m_width; ++j) {
          char currentChar = currentLine[j];
          if (currentChar == 'X') {
            board[i][j] = 1;
          } else if (currentChar == '-'){
            board[i][j] = 0;
          }
        }
        ++i;
      }
    }
    ++lineCount;
  }
  inFS.close();
}

void GenerateBoard::createRandom(int h, int w, float randDecimal) {
  initializeBoard(h,w);
  int totalBoxes = h * w;
  float temp  = randDecimal * totalBoxes;
  int density = (int)temp;
  int currentCell = 0;
  int tempCount = 0;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
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
