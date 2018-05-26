#define RED_00 7
#define RED_10 6
#define RED_20 5
#define GREEN_00 4
#define GREEN_10 3
#define GREEN_20 2
#define RED_01 13
#define RED_11 12
#define RED_21 11
#define GREEN_01 10
#define GREEN_11 9
#define GREEN_21 8
#define RED_02 13
#define RED_12 12
#define RED_22 11
#define GREEN_02 10
#define GREEN_12 9
#define GREEN_22 8

#include "TicTacToeCell.h"

TicTacToeCell* board[3][3];

int buttons[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

int currentPlayer = 0;

void setup(){
  setUpBoard();
  setupButtons();
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

void setupButtons(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      pinMode(buttons[i][j], INPUT);
    }
  }
}

void loop(){
  /*
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j]->green();
      delay(1000);
      board[i][j]->red();
      delay(1000);
    }
  }
  */

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int buttonState = digitalRead(buttons[i][j]);
      if (buttonState == HIGH) {

        if(board[i][j]->isOn()){ 
          notifyError(); // cell already taken
        }
        else{
          turnOn(i, j);
           if(checkWin(currentPlayer)){
            setUpBoard();
           }
        //digitalWrite(ledPin, HIGH);
  
          togglePlayer();
        }
        
        break;
      }
    }
  }

  delay(3000);
}

void notifyError(){
  // cell already colored
}

void turnOn(int i, int j){
  if(currentPlayer == 0){
    board[i][j]->turnOn(currentPlayer, 0);
  }
  else{
    board[i][j]->turnOn(currentPlayer, 1);
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


