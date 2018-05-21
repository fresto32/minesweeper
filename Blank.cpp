#include "Blank.h"

Blank::Blank(int bombs) {
  nearby_bombs = bombs;
}

Blank::Blank() {
  nearby_bombs = 0;
}

int Blank::getData() {
  return nearby_bombs;
}

void Blank::incrementData() {
  nearby_bombs++;
}

void Blank::setNearbyBombs(int bombs) {
  nearby_bombs = bombs;
}

Blank::~Blank() {}
