#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(int rows, int cols, int bombs) {
  board = new Board(rows, cols, bombs);
  dimensions.push_back(rows);
  dimensions.push_back(cols);
  dimensions.push_back(bombs);
}

void Controller::playGame() {
  bool round_results = true;

  if (dimensions[0] == 0 || dimensions[1] == 0 || 
      dimensions[2] > dimensions[0] * dimensions[1]) {
    cout << "Invalid number of rows, columns, and bombs" << endl;
    return;
  }

  while ((board->getNumRevealed() < board->getTotalSpots() - 
        board->getNumBombs()) && round_results) {
    board->printRevealedBoard();
    round_results = playRound();
  }
   
  board->printBoard();
  if (round_results) cout << "You win!" << endl;
  else cout << "You lose!" << endl;
}

bool Controller::playRound() {
  string a;
  int row, col;
  bool noCommand = true;
  while (noCommand) {
    cout << "Please enter a command or '0 0 0' for instructions" << endl;
    cin >> a;
    cin >> row >> col;
    if (row >= dimensions[0] || col >= dimensions[1]) continue;
  
    if (a == "0") {
      cout << "First command: F, S" << endl;
      cout << "F: Flag || S: Select" << endl;
      cout << "The following two numbers are the indices of your selection\n";
      cout << "Format: Row Col" << endl;
      cout << "Thus: Command Row Col" << endl << endl;
    } else if (a == "F") {
      board->setFlag(row,col);
      noCommand = false;
    } else if (a == "S") {
      if ((board->getSpot(row, col))->getData() == -1) return false;
      board->updateBoard(row, col);
      noCommand = false;
    }
  }
  return true;
}

Controller::~Controller() {
  delete board;
}
