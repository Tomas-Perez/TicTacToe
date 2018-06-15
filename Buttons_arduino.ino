int buttons[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
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

void loop() {
  int button = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int buttonState = digitalRead(buttons[i][j]);
      int old_value = old_values[i][j];
      bool buttonPressed = buttonState != old_value;
      ++button;
      if (buttonPressed) {
        byte byteButton = (byte) button;
        Serial.write(byteButton);
        delay(10);
        break;
      }
    }
  }
}
