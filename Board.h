#ifndef _BOARD_H_
#define _BOARD_H_

#include "Spot.h"
#include <vector>

class Board {
  std::vector<std::vector<Spot*> > spots;
  int num_bombs;
  int total_spots;
  int num_revealed;
 public:
  // Creates teh spots vector of vectors with specified num of rows and columns
  // with the number of bombs. Randomizes the location of bombs and sets the
  // data of each Spot*
  Board(int rows, int cols, int num_bombs);

  // Prints the board
  void printBoard();
  // Prints the board with revealed and unrevealed locations
  void printRevealedBoard();
 
  // Updates the board to reveal all non-bombs in vicinity of selection,
  // assumes called on blank spot. Called recursively as in DFS.
  void updateBoard(int row, int col);
  
  // Getters & Setters
  std::vector<std::vector<Spot*> > getBoard();
  int getNumBombs();
  int getTotalSpots();
  void setFlag(int row, int col);
  Spot* getSpot(int row, int col);
  int getNumRevealed();
 
  // Destructor
  ~Board();
};

#endif // _BOARD_H_
