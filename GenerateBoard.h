#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

class GenerateBoard {
  public:
    GenerateBoard(); //default
    GenerateBoard(int h, int w, float d); //overloaded
    // GenerateBoard(const GenerateBoard&); //copy constructor
    ~GenerateBoard();

    //getter and setter methods
    void setHeight(int h);
    void setWidth(int w);
    int getHeight();
    int getWidth();
    void setDensity(float d);
    float getDensity();
    int** getBoard();

    //helper method for 2D array
    void initializeBoard(int h, int w);

    void createFromFile(string fileName);
    void createRandom(int h, int w, float randDecimal);

    int** board; //2D array

  private:
    int m_height;
    int m_width;
    float m_density;
};
