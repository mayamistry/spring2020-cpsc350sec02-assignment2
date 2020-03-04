#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

class GenerateBoard {
  public:
    GenerateBoard(); //default
    GenerateBoard(int h, int w); //overloaded
    GenerateBoard(GenerateBoard b); //copy constructor
    ~GenerateBoard();

    //getter and setter methods
    void setHeight(int h);
    void setWidth(int w);
    int getHeight();
    int getWidth();

    void createFromFile(string fileName);
    void createRandom(int h, int w, float randDecimal);

    int *board; //2D array

  private:
    int m_height;
    int m_width;
};
