
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup() {

  
  for (int i = 0; i < 11; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {

 

  for (int i = 0; i < 5; i++) {

    digitalWrite(leds[i], HIGH);         
    digitalWrite(leds[10 - i], HIGH);   

    delay(500);

    digitalWrite(leds[i], LOW);
    digitalWrite(leds[10 - i], LOW);
  }

  
  digitalWrite(leds[5], HIGH);
  delay(500);
  digitalWrite(leds[5], LOW);

  delay(500);

  
  digitalWrite(leds[5], HIGH);
  delay(500);
  digitalWrite(leds[5], LOW);

  for (int i = 4; i >= 0; i--) {

    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[10 - i], HIGH);

    delay(500);

    digitalWrite(leds[i], LOW);
    digitalWrite(leds[10 - i], LOW);
  }

  delay(500);
}