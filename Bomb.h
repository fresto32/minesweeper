#ifndef _BOMB_H_
#define _BOMB_H_

#include "Spot.h"
#include <utility>

class Bomb : public Spot {
 public:
  // Default constructor
  Bomb();
  // Returns -1 to signal that this spot is a bomb
  int getData(); 
  void incrementData();

  ~Bomb();
};

#endif // _BOMB_H_
