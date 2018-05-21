#include "Board.h"
#include "Controller.h"
#include <iostream>

using namespace std;

int main() {
  int rows, cols, bombs;
  cout << "Input nums rows, cols, bombs" << endl;
  cin >> rows >> cols >> bombs;
  Controller con(rows, cols, bombs);
  con.playGame();
  return 0;
}
