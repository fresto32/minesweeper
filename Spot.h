#ifndef _SPOT_H_
#define _SPOT_H_

class Spot {
  bool is_revealed;
  bool is_flagged;
 public:
  // Default constructor
  Spot();

  // Pure virtual function which will be overridden by derived classes
  virtual int getData() = 0;

  // Getters and setters
  void setIsRevealed();
  void setIsFlagged();
  bool getIsRevealed();
  bool getIsFlagged();

  // Pure virtual function to increment data, will be overidden by derived 
  // classes
  virtual void incrementData() = 0;

  virtual ~Spot();
};

#endif //_SPOT_H_
