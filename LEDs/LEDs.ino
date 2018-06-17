#define RED_02 11
#define RED_01 12
#define RED_00 13
#define GREEN_02 8
#define GREEN_01 9
#define GREEN_00 10
#define RED_12 5
#define RED_11 6
#define RED_10 7
#define GREEN_12 2
#define GREEN_11 3
#define GREEN_10 4
#define RED_22 A0
#define RED_21 A1
#define RED_20 A2
#define GREEN_22 A3
#define GREEN_21 A4
#define GREEN_20 A5

#include "TicTacToeCell.h"

TicTacToeCell* board[3][3];
int currentPlayer;

void setup(){
  Serial.begin(9600);
  pinMode(0, INPUT);
  setUpBoard();
  currentPlayer = 0;
  Serial.flush();
}

void setUpBoard(){
  board[0][0] = new TicTacToeCell(RED_00, GREEN_00);
  board[0][1] = new TicTacToeCell(RED_01, GREEN_01);
  board[0][2] = new TicTacToeCell(RED_02, GREEN_02);
  board[1][0] = new TicTacToeCell(RED_10, GREEN_10);
  board[1][1] = new TicTacToeCell(RED_11, GREEN_11);
  board[1][2] = new TicTacToeCell(RED_12, GREEN_12);
  board[2][0] = new TicTacToeCell(RED_20, GREEN_20);
  board[2][1] = new TicTacToeCell(RED_21, GREEN_21);
  board[2][2] = new TicTacToeCell(RED_22, GREEN_22);
}

void reset(){
  currentPlayer = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j]->reset();
    }
  }
}


void loop(){
  byte buttonChanged = getButtonPressed();
  if(buttonChanged){
    TicTacToeCell* cellPressed = getBoardCell(buttonChanged);
    if(cellPressed->isOn()){ 
      notifyError(); // cell already taken
    }
    else{
      turnOn(cellPressed);
      if(checkWin(currentPlayer)){
        reset();
      }
      else togglePlayer();
    }
  }
}

byte getButtonPressed(){
  if(!Serial.available()) return 0;
  
  byte data = Serial.read();
  if(data == 10) {
    reset();
  } 
  if(data < 0 || data > 9) return 0;

  return data;
}

TicTacToeCell* getBoardCell(byte buttonChanged){
  if (buttonChanged == 1) return board[0][0];
  if (buttonChanged == 2) return board[0][1];
  if (buttonChanged == 3) return board[0][2];
  if (buttonChanged == 4) return board[1][0];
  if (buttonChanged == 5) return board[1][1];
  if (buttonChanged == 6) return board[1][2];
  if (buttonChanged == 7) return board[2][0];
  if (buttonChanged == 8) return board[2][1];
  if (buttonChanged == 9) return board[2][2];
}

void notifyError(){
  // cell already colored
}

void turnOn(TicTacToeCell* cellPressed){
  if(currentPlayer == 0){
    cellPressed->turnOn(currentPlayer, 0);
  }
  else{
    cellPressed->turnOn(currentPlayer, 1);
  }
}

void togglePlayer(){
  if(currentPlayer == 0){
    currentPlayer = 1;
  }
  else{
    currentPlayer = 0;
  }
}


boolean checkWin(int playerNumber) {
  if(board[0][0]->getPlayer() == playerNumber && board[1][0]->getPlayer() == playerNumber && board[2][0]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  }
  else if(board[0][0]->getPlayer() == playerNumber && board[0][1]->getPlayer() == playerNumber && board[0][2]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  }
  else if(board[0][0]->getPlayer() == playerNumber && board[1][1]->getPlayer() == playerNumber && board[2][2]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  } 
  else if(board[1][0]->getPlayer() == playerNumber && board[1][1]->getPlayer() == playerNumber && board[1][2]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  } 
  else if(board[2][0]->getPlayer() == playerNumber && board[2][1]->getPlayer() == playerNumber && board[2][2]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  } 
  else if(board[0][1]->getPlayer() == playerNumber && board[1][1]->getPlayer() == playerNumber && board[2][1]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  } 
  else if(board[0][2]->getPlayer() == playerNumber && board[1][2]->getPlayer() == playerNumber && board[2][2]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  } 
  else if(board[2][0]->getPlayer() == playerNumber && board[1][1]->getPlayer() == playerNumber && board[0][2]->getPlayer() == playerNumber){
    winAnimation(playerNumber);
    return true;
  } 
  return false;
}

int winAnimation(int playerNumber) {
  int color = 0;
  if(playerNumber == 1){
    color = 1;
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j]->turnOn(playerNumber, color);
    }
  }
  delay(5000);
}

