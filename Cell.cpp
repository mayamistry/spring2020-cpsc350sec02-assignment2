/* Name: Jessica Roux and Maya Mistry
 * Student ID#: 2317255 and
 * Chapman email: jroux@chapman.edu and
 * Course Number and Section: 350-02
 * Assignment: 2 - Game of Life
 * This program is the implementation file for the cell class that defines functions*/

#include "Cell.h"

  Cell::Cell(){
    //Initialize variables to default values
    m_numN = 0;
    m_isAlive = false;
    m_lifeStatus = "-";
  }

//Overload constructor
  Cell::Cell(int numN, boolean isAlive, char lifeStatus){
    m_numN = numN;
    m_isAlive = isAlive;
    m_lifeStatus = lifeStatus;
  }

/**NumN accessor method
Return m_numN type int**/
  int Cell::getNumN(){
    return m_numN;
  }
/**isAlive accessor function
Return m_isAlive type boolean**/
  boolean Cell::getIsAlive(){
    return m_isAlive;
  }
/**lifeStatus accessor function
Return m_lifeStatus type char**/
  char Cell::getLifeStatus(){
    return m_lifeStatus;
  }
/**numN mutator function
No return**/
  void Cell::setNumN(int numN){
    m_numN = numN;
  }

/**isAlive mutator function
No return**/
  void Cell::setIsAlive(boolean isAlive){
    m_isAlive = isALive;
  }

/**lifeStatus mutator function
No return**/
  void Cell::setLifeStatus(char lifeStatus){
    m_lifeStatus = lifeStatus;
  }

/**neighbor function - refers to the game rules and updates teh lifeStatus of the location for the next getName
No return **/
  void Cell::neighbor(){
    if (numN <= 1){ //if there are one or fewer neightbors then the cell is empty next gen
      lifeStatus = '-';
    }else if (numN = 2){ //if there are 2 neightbors the cell remains stable at its current state
      //stays the same
    }else if (numN = 3){ //location with 3 neighbors will contain a cell in next gen
      lifeStatus = 'x';
    }else if (numN >= 4){ //location with 4 or more neighbors will be empty next gen (overcrowding)
      lifeStatus = '-';
    }
  }
