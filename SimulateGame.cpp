#include "SimulateGame.h"

//Default constructor
SimulateGame::SimulateGame() {
  m_board = NULL;
  m_mode = "";
  m_genCount = 1;
  m_isStable = false;
}

//Overloaded constructor
SimulateGame::SimulateGame(GenerateBoard *b, string mode, string playType){
  m_board = b;
  m_mode = mode;
  m_playType = playType;
  m_genCount = 1;
  m_mainBoard = b->getBoard();
  m_height = b->getHeight();
  m_width = b->getWidth();
  m_futureBoard = NULL;
  m_isStable = false;
}

//Destructor
SimulateGame::~SimulateGame(){
  delete m_board;
}

//kmethod to actually start the game using the mode and play type the user chooses
void SimulateGame::start(){
  if (m_mode == "1"){
    ClassicMode* game = new ClassicMode(m_board);
    //call play classic function
    playClassic(game, m_playType);
  }else if (m_mode == "2"){
    MirrorMode* game = new MirrorMode(m_board);
    //call play mirror function
    playMirror(game, m_playType);
  }else if (m_mode == "3"){
    DonutMode* game = new DonutMode(m_board);
    //call play donut function
    playDonut(game, m_playType);
  }
}

//method used if player chooses classic mode
void SimulateGame::playClassic(ClassicMode *c, string playType) {
  //play
  //first print what genertation 0 is
  cout << "-----------------------------------------------------";
  cout << endl;
  cout << "START OF GAME OF LIFE: " << endl;
  //work with play type
  if (playType == "1") {
    //for pause
    while ((m_isStable == false)) {
      cout << "Generation #: " << m_genCount << endl;
      printBoardToConsole(m_mainBoard, m_height, m_width);
      cout << endl;
      m_futureBoard = c->iterateThroughBoard(m_board, m_mainBoard);
      cout << endl;
      ++m_genCount;
      printBoardToConsole(m_futureBoard, m_height, m_width);
      //check if stable
      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        cout << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
      sleep(1);
    }
  } else if (playType == "2") {
    //for enter
    while ((m_isStable == false)) {
      cout << "Generation #: " << m_genCount << endl;
      printBoardToConsole(m_mainBoard, m_height, m_width);
      cout << endl;
      m_futureBoard = c->iterateThroughBoard(m_board, m_mainBoard);
      cout << endl;
      ++m_genCount;
      printBoardToConsole(m_futureBoard, m_height, m_width);
      //check if stable
      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        //if file, output to file
        cout << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
      cout << "Press enter to continue: ";
      cin.ignore();
    }
  } else if (playType == "3") {
    //for outputFile
    string outputFile = "";
    cout << "Enter the name of the file you want to output to: " << endl;
    cin >> outputFile;
    m_outFS.open(outputFile);
    m_outFS << "-----------------------------------------------------";
    m_outFS << endl;
    m_outFS << "START OF GAME OF LIFE: " << endl;
    while ((m_isStable) == false) {
      m_outFS << "Generation #: " << m_genCount << endl;
      printToOutputFile(m_mainBoard, m_height, m_width);
      m_futureBoard = c->iterateThroughBoard(m_board, m_mainBoard);
      m_outFS << endl;
      ++m_genCount;
      printToOutputFile(m_futureBoard, m_height, m_width);

      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        m_outFS << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
    }
    m_outFS.close();
  }
}

//method used if player chooses mirror mode
void SimulateGame::playMirror(MirrorMode *m, string playType) {
  //play
  //first print what genertation 0 is
  cout << "-----------------------------------------------------";
  cout << endl;
  cout << "START OF GAME OF LIFE: " << endl;
  //work with play type
  if (playType == "1") {
    //for pause
    while ((m_isStable == false)) {
      cout << "Generation #: " << m_genCount << endl;
      printBoardToConsole(m_mainBoard, m_height, m_width);
      cout << endl;
      m_futureBoard = m->iterateThroughBoard(m_board, m_mainBoard);
      cout << endl;
      ++m_genCount;
      printBoardToConsole(m_futureBoard, m_height, m_width);
      //check if stable
      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        //if file, output to file
        cout << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
      sleep(1);
    }
  } else if (playType == "2") {
    //for enter
    while ((m_isStable == false)) {
      cout << "Generation #: " << m_genCount << endl;
      printBoardToConsole(m_mainBoard, m_height, m_width);
      cout << endl;
      m_futureBoard = m->iterateThroughBoard(m_board, m_mainBoard);
      cout << endl;
      ++m_genCount;
      printBoardToConsole(m_futureBoard, m_height, m_width);
      //check if stable
      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        //if file, output to file
        cout << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
      cout << "Press enter to continue: ";
      cin.ignore();
    }
  } else if (playType == "3") {
    //for outputFile
    string outputFile = "";
    cout << "Enter the name of the file you want to output to: " << endl;
    cin >> outputFile;
    m_outFS.open(outputFile);
    m_outFS << "-----------------------------------------------------";
    m_outFS << endl;
    m_outFS << "START OF GAME OF LIFE: " << endl;
    while ((m_isStable) == false) {
      m_outFS << "Generation #: " << m_genCount << endl;
      printToOutputFile(m_mainBoard, m_height, m_width);
      m_futureBoard = m->iterateThroughBoard(m_board, m_mainBoard);
      m_outFS << endl;
      ++m_genCount;
      printToOutputFile(m_futureBoard, m_height, m_width);

      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        m_outFS << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
    }
    m_outFS.close();
  }
}

//method used if player chooses donut mode
void SimulateGame::playDonut(DonutMode *d, string playType) {
  //play
  //first print what genertation 0 is
  cout << "-----------------------------------------------------";
  cout << endl;
  cout << "START OF GAME OF LIFE: " << endl;
  //work with play type
  if (playType == "1") {
    //for pause
    while ((m_isStable == false)) {
      cout << "Generation #: " << m_genCount << endl;
      printBoardToConsole(m_mainBoard, m_height, m_width);
      cout << endl;
      m_futureBoard = d->iterateThroughBoard(m_board, m_mainBoard);
      cout << endl;
      ++m_genCount;
      printBoardToConsole(m_futureBoard, m_height, m_width);
      //check if stable
      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        //if file, output to file
        cout << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
      sleep(1);
    }
  } else if (playType == "2") {
    //for enter
    while ((m_isStable == false)) {
      cout << "Generation #: " << m_genCount << endl;
      printBoardToConsole(m_mainBoard, m_height, m_width);
      cout << endl;
      m_futureBoard = d->iterateThroughBoard(m_board, m_mainBoard);
      cout << endl;
      ++m_genCount;
      printBoardToConsole(m_futureBoard, m_height, m_width);
      //check if stable
      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        //if file, output to file
        cout << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
      cout << "Press enter to continue: ";
      cin.ignore();
    }
  } else if (playType == "3") {
    //for outputFile
    string outputFile = "";
    cout << "Enter the name of the file you want to output to: " << endl;
    cin >> outputFile;
    m_outFS.open(outputFile);
    m_outFS << "-----------------------------------------------------";
    m_outFS << endl;
    m_outFS << "START OF GAME OF LIFE: " << endl;
    while ((m_isStable) == false) {
      m_outFS << "Generation #: " << m_genCount << endl;
      printToOutputFile(m_mainBoard, m_height, m_width);
      m_futureBoard = d->iterateThroughBoard(m_board, m_mainBoard);
      m_outFS << endl;
      ++m_genCount;
      printToOutputFile(m_futureBoard, m_height, m_width);

      m_isStable = true; //first assume true
      for (int i  = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          if (m_mainBoard[i][j] != m_futureBoard[i][j]) {
            m_isStable = false;
            break;
          }
        }
      }
      if (m_isStable == true) {
        m_outFS << "Stabilized (current generation board and future genertation board equal each other)" << endl;
        cout << "End of game" << endl;
        break;
      }
      for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
          m_mainBoard[i][j] = m_futureBoard[i][j];
        }
      }
    }
    m_outFS.close();
  }
}

//method to print boards from the game to the console
void SimulateGame::printBoardToConsole(int**array, int h, int w) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int cell = array[i][j];
      if (cell == 0) {
        cout << "-";
      } else if (cell == 1) {
        cout << "X";
      }
    }
    cout << endl;
  }
}

//method to print boards from the game to the output file of the users choice
void SimulateGame::printToOutputFile(int**array, int h, int w) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int cell = array[i][j];
      if (cell == 0) {
        m_outFS << "-";
      } else if (cell == 1) {
        m_outFS << "X";
      }
    }
    m_outFS << endl;
  }
}
