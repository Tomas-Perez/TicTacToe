#include "Arduino.h"
#include "TicTacToeCell.h"

TicTacToeCell::TicTacToeCell(int red_pin, int green_pin)
{
  _isOn = false;
  _player = -1;
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

int TicTacToeCell::getPlayer(){
  return _player;
}

boolean TicTacToeCell::isOn()
{
  return _isOn;
}

void TicTacToeCell::turnOn(int player, int color)
{
  _isOn = true;
  _player = player;
  if(color == 0){
    green();
  } else{
    red();
  }
}

