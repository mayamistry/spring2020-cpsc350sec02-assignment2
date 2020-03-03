#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main (int argc, char**argv) {
  ifstream inFS;
  int dimensionX = 0;
  int dimensionY = 0;

  return 0;
}

void startGame() {
  cout << "Welcome to the game of life! Before starting, would you like to provide your own map file? Enter 'yes' if so." << endl;
  string userInput = "";
  cin >> userInput;
  if (userInput == "yes") {
    fileInput();
  } else {
    randomAssignment();
  }
}

void fileInput() {
  string fileName = "";
  string currentLine = "";
  cout << "Enter the name of your .txt file: " << endl;
  cin >> fileName;

  inFS.open(fileName);

  //check if the file can be opened
  if (!inFS.is_open()) {
    cout << "Could not open file." << endl;
    return 1;
  }

  //start reading the file
  while (!inFS.eof()) {
    inFS >> currentLine;
    if (!inFS.fail()){
      if (dimensionX = 0) {
        dimensionX = stoi(currentLine);
      } else if (dimensionY = 0)
        dimensionY = stoi(currentLine);
      } else {
        for (int i = 0; i < currentLine.size(); ++i) {
          char currentChar = currentLine[i];
          //First make a cell object and then add it onto the grid
          //create an add function on the grid class to add a cell value to it
          //maybe put this part of it in the game/simulation class?
        }
      }
    }
  }

  //Calculate the mean
  mean = (float)sum / lineCount;

  //Close file and then re-open to find variance
  inFS.close();
}

void randomAssignment() {

}
