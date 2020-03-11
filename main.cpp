#include <iostream>
#include "UserIO.h"
using namespace std;

//main method is where we implemenet userIO which then connects all info to start the actual game
int main (int argc, char**argv) {
  UserIO *userIO = new UserIO();
  userIO->start();

  string modeInput = userIO->getGameMode();
  string playType = userIO->getPlayType();

  //Simulate game
  //The board object, game mode, and play type get put into simulation to start game
  SimulateGame* game = new SimulateGame(userIO->getBoard(), modeInput, playType); //other, //other)
  game->start();

  return 0;
}
