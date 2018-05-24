#include "Arduino.h"
#include "TicTacToeCell.h"

TicTacToeCell::TicTacToeCell(int red_pin, int green_pin)
{
  pinMode(red_pin, OUTPUT);
  _red_pin = red_pin;
  pinMode(green_pin, OUTPUT);
  _green_pin = green_pin;
}

void TicTacToeCell::red()
{
  digitalWrite(_green_pin, LOW);
  digitalWrite(_red_pin, HIGH);
}

void TicTacToeCell::green()
{
  digitalWrite(_red_pin, LOW);
  digitalWrite(_green_pin, HIGH);
}
