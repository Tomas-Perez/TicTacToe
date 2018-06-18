#ifndef TicTacToeCell_h
#define TicTacToeCell_h

#include "Arduino.h"

class TicTacToeCell
{
  public:
    TicTacToeCell(int red_pin, int green_pin);
    void green();
    void red();
    void off();
    void turnOff();
    boolean isOn();
    void turnOn(int player, int color);// 0 = green, 1 = red
    int getPlayer();
    void reset();
  private:
    boolean _isOn; 
    int _player;
    int _red_pin;
    int _green_pin;
};

#endif

