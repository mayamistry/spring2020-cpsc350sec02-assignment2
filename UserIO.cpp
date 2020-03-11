#include "UserIO.h"

//Default constructor
UserIO::UserIO() {
  m_board = NULL;
  m_modeInput = "";
  m_playType = "";
}

//Destructor will delete m_board to prevent memory leaks
UserIO::~UserIO() {
  delete m_board;
}

//Start function gets all the information needed from the user to start the game
void UserIO::start(){
  m_board = promptForFileOrRandom();
  m_modeInput = promptBoundary();
  m_playType = promptForSimulationType();
}

//promptForFileOrRandom function prompts if the user wants to provide their own map file or geneterate a random one
GenerateBoard* UserIO::promptForFileOrRandom() {
  string userInput = "";
  cout << "Welcome to the game of life!" << endl;

  //1. Ask the user if they want to provide a map file or receive a random assignment
  cout << "If you would like to provide your own map file, enter 'file'. If you would like a random assignment, enter 'random'." << endl;
  cin >> userInput;

  GenerateBoard *b1 = new GenerateBoard(); //create a default object and then alter values later

  while (userInput != "file" || userInput != "random") {
    //If user provides a map file
    if (userInput == "file") {
      string fileName = "";
      cout << "Enter the name of your map.txt file: " << endl;
      cin >> fileName;
      b1->createFromFile(fileName);
      break;
      //If user chooses to generate random
    } else if (userInput == "random") {
      int height = 0;
      int width = 0;
      float random = 0.0;
      cout << "Enter a height for the board: " << endl;
      cin >> height;
      //error handling
      bool isValid = false;
      while (isValid == false) {
        if (height <= 1) {
          cout << "Make your height bigger and enter integer value: " << endl;
          cin >> height;
        } else {
          isValid = true;
        }
      }
      b1->setHeight(height);
      cout << "Enter a width for the board: " << endl;
      cin >> width;
      isValid = false;
      //error handling
      while (isValid == false) {
        if (width <= 1) {
          cout << "Make your width bigger and enter integer value: " << endl;
          cin >> width;
        } else {
          isValid = true;
        }
      }
      b1->setWidth(width);
      cout << "Enter a random number greater than 0 and less than or equal to 1 in decimal form: " << endl;
      cin >> random;
      //error handlings
      isValid = false;
      while (isValid == false) {
        if (random >= 1) {
          cout << "Make your value less than 1 and enter a decimal value: " << endl;
          cin >> random;
        } else {
          isValid = true;
        }
      }
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

//Asks the user what boundary mode they want to run in
string UserIO::promptBoundary() {
  //do error handling
  string input = "";
  bool validInput = false;
  while (validInput == false) {
    cout << "Choose the boundary mode you want to use: (Enter '1' for classic, '2' for mirror, or '3' for donut)" << endl;
    cin >> input;
    if ((input != "1") && (input != "2") && (input != "3")) {
      cout << "Not valid. Try again." << endl;
      continue;
    } else {
      validInput = true;
    }
  }
  return input;
}

//Asks user if they want a brief pause, want to press enter, or output everything to an output file
string UserIO::promptForSimulationType() {
  string input = "";
  bool validInput = false;
  while (validInput == false) {
    cout << "Choose if you want to simulate using a pause (Enter '1'), pressing enter (Enter '2'), or output everything to a file ('Enter '3'): " << endl;
    cin >> input;
    if ((input != "1") && (input != "2") && (input != "3")) {
      cout << "Not valid. Try again." << endl;
      continue;
    } else {
      validInput = true;
    }
  }
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
