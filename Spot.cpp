#include "Spot.h"

Spot::Spot() {
  is_flagged = false;
  is_revealed = false;
}

void Spot::setIsFlagged(){
  is_flagged = true;
}

bool Spot::getIsFlagged() {
  return is_flagged;
}

bool Spot::getIsRevealed() {
  return is_revealed;
}

void Spot::setIsRevealed() {
  is_revealed = true;
}

Spot::~Spot() {
}
