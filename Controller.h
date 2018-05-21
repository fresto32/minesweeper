#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Board.h"
#include <vector>

class Controller {
  Board *board;
  bool playRound();
  std::vector<int> dimensions;
 public:
  Controller(int rows, int cols, int bombs);
  void playGame();
  ~Controller();
};

#endif // _CONTROLLER_H_
