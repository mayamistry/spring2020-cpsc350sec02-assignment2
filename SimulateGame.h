#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"

class SimulateGame {
public:
  SimulateGame();
  SimulateGame(GenerateBoard *b, string mode, string playType);
  ~SimulateGame();
  void generateWithPause();
  void generateWithEnter();
  void generateInOutputFile();

  void play();

  GenerateBoard* m_board;
  string m_mode;
  string m_playType;
};
