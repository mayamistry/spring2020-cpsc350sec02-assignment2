#include "UserIO.h"

UserIO::UserIO() {
  m_board = NULL;
  m_modeInput = "";
  m_playType = "";
}

UserIO::~UserIO() { // figure out later
  delete m_board;
}

void UserIO::start(){
  m_board = promptForFileOrRandom();
  m_modeInput = promptBoundary();
  m_playType = promptForSimulationType();
}

GenerateBoard* UserIO::promptForFileOrRandom() {
  string userInput = "";
  cout << "Welcome to the game of life!" << endl;

  //1. Ask the user if they want to provide a map file or receive a random assignment
  cout << "If you would like to provide your own map file, enter 'file'. If you would like a random assignment, enter 'random'." << endl;
  cin >> userInput;

  GenerateBoard *b1 = new GenerateBoard(); //create a default object and then alter values later

  while (userInput != "file" || userInput != "random") {
    if (userInput == "file") {
      string fileName = "";
      cout << "Enter the name of your map.txt file: " << endl;
      cin >> fileName;
      b1->createFromFile(fileName);
      break;
    } else if (userInput == "random") {
      int height = 0;
      int width = 0;
      float random = 0.0;
      cout << "Enter a height for the board: " << endl;
      cin >> height;
      b1->setHeight(height);
      cout << "Enter a width for the board: " << endl;
      cin >> width;
      b1->setWidth(width);
      cout << "Enter a random number greater than 0 and less than or equal to 1 in decimal form: " << endl;
      cin >> random;
      b1->setDensity(random);
      b1->createRandom(height, width, random);
      break;
    } else {
      cout << "Error: please either enter 'file' or 'random'. Try again: " << endl;
      cin >> userInput;
    }
  }
  return b1;
}

//2. Ask the user what boundary mode they want to run in
string UserIO::promptBoundary() {
  cout << "Choose the boundary mode you want to use: (Enter '1' for classic, '2' for mirror, or '3' for donut)" << endl;
  //do error handling
  string input = "";
  cin >> input;
  return input;
}



  //3. Ask user if they want a brief pause, want to press enter, or output everything to an output file
string UserIO::promptForSimulationType() {
  cout << "Choose if you want to simulate using a pause (Enter '1'), pressing enter (Enter '2'), or output everyhting to a file ('Enter '3'): " << endl;
  //do error handling
  string input = "";
  cin >> input;
  return input;
}

GenerateBoard* UserIO::getBoard() {
  return m_board;
}

string UserIO::getGameMode() {
  return m_modeInput;
}

string UserIO::getPlayType(){
  return m_playType;
}
