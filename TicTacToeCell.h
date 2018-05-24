#ifndef TicTacToeCell_h
#define TicTacToeCell_h

#include "Arduino.h"

class TicTacToeCell
{
  public:
    TicTacToeCell(int red_pin, int green_pin);
    void green();
    void red();
  private:
    int _red_pin;
    int _green_pin;
};

#endif
