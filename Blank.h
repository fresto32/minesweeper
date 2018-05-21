#ifndef _BLANK_H_
#define _BLANK_H_

#include "Spot.h"

class Blank : public Spot {
  int nearby_bombs;
 public:
  // Default constructor
  Blank();
  // Constructor that sets num of nearby_bombs
  Blank(int bombs);
  
  // Getters and setters
  int getData();
  void setNearbyBombs(int bombs);

  // Increments the number of nearby bombs
  void incrementData();

  ~Blank();
};

#endif // _BLANK_H_
