#include <iostream>
#include "UserIO.h"
using namespace std;

int main (int argc, char**argv) {
  UserIO *userIO = new UserIO();
  userIO->start();

  string modeInput = userIO->getGameMode();
  string playType = userIO->getPlayType();

  //Simulate game
  //Make simulation object
  SimulateGame* game = new SimulateGame(userIO->getBoard(), modeInput, playType); //other, //other)
  game->start();

  return 0;
}
