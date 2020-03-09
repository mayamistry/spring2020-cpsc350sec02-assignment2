#include "SimulateGame.h"

SimulateGame::SimulateGame() {
  m_board = NULL;
  m_mode = "";
}
SimulateGame::SimulateGame(GenerateBoard *b, string mode, string playType){
  m_board = b;
  m_mode = mode;
  m_playType = playType;
}
SimulateGame::~SimulateGame(){
  delete m_board;
}

void SimulateGame::play(){
  if (m_mode == "1"){
    ClassicMode* game = new ClassicMode();
  }else if (m_mode == "2"){
    MirrorMode* game = new MirrorMode();
  }else if (m_mode == "3"){
    DonutMode* game = new DonutMode();
  }
}
