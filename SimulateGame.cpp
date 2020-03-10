#include "SimulateGame.h"

SimulateGame::SimulateGame() {
  m_board = NULL;
  m_mode = "";
  m_genCount = 0;
}
SimulateGame::SimulateGame(GenerateBoard *b, string mode, string playType){
  m_board = b;
  m_mode = mode;
  m_playType = playType;
  m_genCount = 0;
  m_mainBoard = b->getBoard();
  m_height = b->getHeight();
  m_width = b->getWidth();
  m_futureBoard = NULL;
}
SimulateGame::~SimulateGame(){
  delete m_board;
}

void SimulateGame::play(){
  //work with mode
  if (m_mode == "1"){
    ClassicMode* game = new ClassicMode(m_board);
    //call play classic function
    playClassic(game);
  }else if (m_mode == "2"){
    MirrorMode* game = new MirrorMode(m_board);
    //call play mirror function
    playMirror(game);
  }else if (m_mode == "3"){
    DonutMode* game = new DonutMode(m_board);
    //call play donut function
    playDonut(game);
  }

  //work with play type
  if (m_playType == "1") {
    playWithPause();
  } else if (m_playType == "2") {
    playWithEnter();
  } else if (m_playType == "3") {
    playWithOutputFile();
  }
}

void SimulateGame::playWithPause() {
  //do actual game play here
}

void SimulateGame::playWithEnter() {
  //do actual game play here
}

void SimulateGame::playWithOutputFile() {
  //do actual game play here
}

void SimulateGame::playClassic(ClassicMode *c) {
  //play
  //first print what genertation 0 is
  cout << "-----------------------------------------------------";
  cout << endl;
  cout << "START OF GAME OF LIFE: " << endl;
  cout << "Generation #: " << m_genCount << endl;
  printBoard();
  cout << endl;
  c->iterateThroughBoard(m_board);
}

void SimulateGame::playMirror(MirrorMode *m) {

}

void SimulateGame::playDonut(DonutMode *d) {

}

void SimulateGame::printBoard() {
  for (int i = 0; i < m_height; ++i) {
    for (int j = 0; j < m_width; ++j) {
      int cell = m_mainBoard[i][j];
      if (cell == 0) {
        cout << "-";
      } else if (cell == 1) {
        cout << "X";
      }
    }
    cout << endl;
  }
}

//make helper methods here
