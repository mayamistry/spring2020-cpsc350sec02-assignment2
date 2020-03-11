#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include <fstream> //to output boards to the file
#include <unistd.h>
#include <stdio.h>

class SimulateGame {
public:
  SimulateGame();
  SimulateGame(GenerateBoard *b, string mode, string playType);
  ~SimulateGame();

  void start();

  void playClassic(ClassicMode *c, string playType);
  void playMirror(MirrorMode *m, string playType);
  void playDonut(DonutMode *d, string playType);

  //add other helper methods here
  void printBoardToConsole(int**array, int h, int w);
  void printToOutputFile(int**array, int h, int w);

  GenerateBoard* m_board;
  int **m_mainBoard; //main board to show current generations
  int **m_futureBoard; //use this to create future gen board and then empty out when finished
  string m_mode;
  string m_playType;
  int m_genCount; //counts number of generations
  int m_height;
  int m_width;
  bool m_isStable;
  ofstream m_outFS;
};
