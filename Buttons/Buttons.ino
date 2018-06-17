int buttons[3][3] = {{6, 5, 4}, {9, 8, 7}, {12, 11, 10}};
int old_values[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

void setup() {
  Serial.begin(9600);
  setupButtons();
  setupValues();
  Serial.flush();
}

void setupButtons(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      pinMode(buttons[i][j], INPUT_PULLUP);
    }
  }
}

void setupValues(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      old_values[i][j] = digitalRead(buttons[i][j]);
    }
  }
}

void resetOldValues(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      old_values[i][j] = 0;
    }
  }
}

void loop() {
  int button = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int buttonState = !digitalRead(buttons[i][j]);
      int old_value = old_values[i][j];
      bool buttonPressed = buttonState != old_value;
      ++button;
      if (buttonPressed) old_values[i][j] = buttonState;
      if (buttonPressed && buttonState == HIGH) {
        delay(10);
        byte byteButton = (byte) button;
        Serial.write(byteButton);
        old_values[i][j] = buttonState;
        break;
      }
    }
  }
}

