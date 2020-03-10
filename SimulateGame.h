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

  GenerateBoard* m_board;
  int **m_futureBoard; //use this to create future gen board and then empty out when finished
  string m_mode;
  string m_playType;
};
