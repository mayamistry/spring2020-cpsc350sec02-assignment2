/* Name: Jessica Roux and Maya Mistry
 * Student ID#: 2317255 and
 * Chapman email: jroux@chapman.edu and
 * Course Number and Section: 350-02
 * Assignment: 2 - Game of Life
 * This program is the header file for cell.cpp including the class definitions*/

#include <iostream>
#include <string>

using namespace std;

class Cell{
public:
  Cell(); //Constructor
  Cell(int numN, boolean isAlive, char lifeStatus); //Overloaded constructor
  ~Cell(); //destructor

  //Accessors
  int getNumN();
  boolean getIsAlive();
  char getLifeStatus();

  //Mutators
  void setNumN(int numN);
  void setIsAlive(boolean isAlive);
  void setLifeStatus(char lifeStatus);

  void neighbor();

private:
  //Attributes of the cell
  int m_numN; //number of neighbors
  boolean m_isAlive; //dead or alive
  char m_lifeStatus; //'-' or 'x'
};
