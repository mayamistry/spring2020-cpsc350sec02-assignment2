#include "UserIO.h"

UserIO::UserIO() {
  //what happens here??
}

UserIO::~UserIO() {
  delete; //what happens here???
}

void UserIO::promptForFileOrRandom() {
  string userInput = "";
  cout << "Welcome to the game of life!" << endl;

  //1. Ask the user if they want to provide a map file or receive a random assignment
  cout << "If you would like to provide your own map file, enter 'file'. If you would like a random assignment, enter 'random'." << endl;
  cin >> userInput;

  GenerateBoard b1 = new GenerateBoard(); //create a default object and then alter values later

  while (userInput != "file" || userInput != "random") {
    if (userInput == "file") {
      string fileName = "";
      cout << "Enter the name of your map.txt file: " << endl;
      cin >> fileName;
      b1.createFromFile(fileName);
    } else if (userInput == "random") {
      int height = 0;
      int width = 0;
      float random = 0.0;
      cout << "Enter a height for the board: " << endl;
      cin >> height;
      cout << "Enter a width for the board: " << endl;
      cin >> width;
      cout << "Enter a random number greater than 0 and less than or equal to 1 in decimal form: " << endl;
      cin >> random;
      b1.createRandom(height, width, random);
    }
    cout << "Error: please either enter 'file' or 'random'. Try again: " << endl;
    cin >> userInput;
  }
}

//2. Ask the user what boundary mode they want to run in
GameMode UserIO::promptBoundary() { //maybe pass in grid for this function
  GameMode g;
  cout << "Choose the boundary mode you want to use: (Enter 'classic', 'mirror', or 'donut')" << endl;
  string input = "";
  cin >> input;
  if (input == "classic") {
    g = new ClassicMode(); //enter parameters -> maybe the grid
  } else if (input == "mirror") {
    g = new MirrorMode();
  } else if (input == "donut") {
    g = new DonutMode();
  }
  return g;
}

  //3. Ask user if they want a brief pause, want to press enter, or output everything to an output file
  void UserIO::promptForSimulationType() {

  }
