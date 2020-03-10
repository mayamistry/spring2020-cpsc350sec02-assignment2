#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"

class SimulateGame {
public:
  SimulateGame();
  SimulateGame(GenerateBoard *b, string mode, string playType);
  ~SimulateGame();

  void play();

  void playWithPause();
  void playWithEnter();
  void playWithOutputFile();

  void playClassic(ClassicMode *c);
  void playMirror(MirrorMode *m);
  void playDonut(DonutMode *d);

  //add other helper methods here
  void printBoard();

  GenerateBoard* m_board;
  int **m_mainBoard; //main board to show current generations
  int **m_futureBoard; //use this to create future gen board and then empty out when finished
  string m_mode;
  string m_playType;
  int m_genCount; //counts number of generations
  int m_height;
  int m_width;
};
