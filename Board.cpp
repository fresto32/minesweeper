#include "Board.h"
#include "Spot.h"
#include "Bomb.h"
#include "Blank.h"
#include <vector>
#include <iostream>

using namespace std;

Board::Board(int rows, int cols, int num_bomb) {
  total_spots = rows*cols;
  num_revealed = 0;
  num_bombs = num_bomb;
  int temp_bombs = num_bombs;
  // Pushing prerequisite number of bombs and blanks onto board
  vector<Spot*> to_add;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (num_bomb > 0) {
        Spot *ptr = new Bomb();
        to_add.push_back(ptr);
        num_bomb--;
      } else {
        Spot *ptr = new Blank();
        to_add.push_back(ptr);
      }
    }
    spots.push_back(to_add);
    to_add.clear();
  } 

  // Randomizing location of bombs and blanks
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Spot *temp = spots[i][j];
      int rand_row = (i == 0) ? 0 : rand() % i;
      int rand_col = (j == 0) ? 0 : rand() % j;
      spots[i][j] = spots[rand_row][rand_col];
      spots[rand_row][rand_col] = temp;
    }
  }

  // Updating the blanks nearby bomb data
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (spots[i][j]->getData() == -1) {
        if (i - 1 >= 0) 
          spots[i-1][j]->incrementData();
        if (j - 1 >= 0) 
          spots[i][j-1]->incrementData();
        if ((i - 1 >= 0) && (j - 1 >= 0)) 
          spots[i-1][j-1]->incrementData();
        if (i + 1 < rows) 
          spots[i+1][j]->incrementData();
        if (j + 1 < cols) 
          spots[i][j+1]->incrementData();
        if ((i + 1 < rows) && (j + 1 < cols)) 
          spots[i+1][j+1]->incrementData();
        if ((i - 1 >= 0) && (j + 1 < cols))
          spots[i-1][j+1]->incrementData();
        if ((i + 1 < rows) && (j - 1 >= 0))
          spots[i+1][j-1]->incrementData();
      }
    }
  }
}

int Board::getNumBombs() {
  return num_bombs;
}

void Board::printBoard() {
  cout << endl << endl << endl;
  cout << "\t\t REVEALED BOARD" << endl << endl;
  for (int i = 0; i < spots.size(); i++) {
    cout << i << " ";
    for (int j = 0; j < spots[0].size(); j++) {
      if (spots[i][j]->getData() == -1) {
        cout << "B ";
      } else {
        cout << spots[i][j]->getData() << " ";
      }
    }
    cout << endl;
  }
  cout << "  ";
  for (int j = 0; j < spots[0].size(); j++) cout << j << " ";
  cout << endl << endl << endl;
}

void Board::printRevealedBoard() {
  cout << endl << endl << endl;
  cout << "\t\t Board " << endl << endl;
  for (int i = 0; i < spots.size(); i++) {
    cout << i << " " << flush;
    for (int j = 0; j < spots[0].size(); j++) {
      if (spots[i][j]->getIsRevealed()) {
        if (spots[i][j]->getData() == -1) {
          cout << "B ";
        } else {
          cout << spots[i][j]->getData() << " ";
        }
      } else if (spots[i][j]->getIsFlagged()) {
        cout << "F ";
      } else {
        cout << "* ";
      }
    }
    cout << endl;
  }
  cout << "  ";
  for (int j = 0; j < spots[0].size(); j++) cout << j << " ";
  cout << endl << endl << endl;
}

vector<vector<Spot*> > Board::getBoard() {
  return spots;
}

int Board::getTotalSpots() {
  return total_spots;
}

void Board::setFlag(int row, int col) {
  spots[row][col]->setIsFlagged();
}

Spot* Board::getSpot(int row, int col) {
  cout << spots[row][col]->getData() << endl;
  return spots[row][col];
}

int Board::getNumRevealed() {
  return num_revealed;
}

void Board::updateBoard(int row, int col) {
  if (spots[row][col]->getData() == -1) return;
  if (spots[row][col]->getIsRevealed()) return;

  spots[row][col]->setIsRevealed();
  num_revealed = num_revealed + 1;

  if (spots[row][col]->getData() != 0) return;

  int i = row;
  int j = col;
  int rows = spots.size();
  int cols = spots[0].size();

  if (i - 1 >= 0) updateBoard(i-1, j);
  if (j - 1 >= 0) updateBoard(i, j-1);
  if ((i - 1 >= 0) && (j - 1 >= 0)) updateBoard(i-1, j-1);
  if (i + 1 < rows) updateBoard(i+1, j);
  if (j + 1 < cols) updateBoard(i, j+1);
  if ((i + 1 < rows) && (j + 1 < cols)) updateBoard(i+1, j+1);
  if ((i - 1 >= 0) && (j + 1 < cols)) updateBoard(i-1, j+1);
  if ((i + 1 < rows) && (j - 1 >= 0)) updateBoard(i+1, j-1);
}

Board::~Board() {
  for (int i = 0; i < spots.size(); i++) {
    for (int j = 0; j < spots[0].size(); j++) {
      delete spots[i][j];
    }
  }
}
