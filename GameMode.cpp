#include "GameMode.h"

GameMode::GameMode() {

}

GameMode::GameMode(GenerateBoard *b) {
  m_board = b;
}

GameMode::~GameMode() {
  delete m_board;
}
