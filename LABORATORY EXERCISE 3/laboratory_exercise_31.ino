#include <Keypad.h>

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4] = {9, 8, 7, 6};
byte colPins[4] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

int seg[7] = {A0, A1, A2, A3, A4, A5, 10};


byte pattern[14][7] = {
  {1,1,1,1,1,1,0}, 
  {0,1,1,0,0,0,0}, 
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1}, 
  {0,1,1,0,0,1,1}, 
  {1,0,1,1,0,1,1}, 
  {1,0,1,1,1,1,1}, 
  {1,1,1,0,0,0,0}, 
  {1,1,1,1,1,1,1}, 
  {1,1,1,1,0,1,1}, 
  {1,1,1,0,1,1,1}, 
  {0,0,1,1,1,1,1}, 
  {1,0,0,1,1,1,0}, 
  {0,1,1,1,1,0,1}  
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
  char key = keypad.getKey();

  if (key >= '0' && key <= '9') {
    show(key - '0');
  }
  else if (key >= 'A' && key <= 'D') {
    show(key - 'A' + 10);
  }
}

void show(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(seg[i], pattern[n][i]);
  }
}