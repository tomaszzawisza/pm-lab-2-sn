#include <Arduino.h>
volatile int state = LOW;
void myISR();
int main() {
  init();
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  attachInterrupt(0,myISR, CHANGE);
  sei ();
  while (1) {
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
  }
  void myISR(){
    state = !state;
    digitalWrite(12, state);
  }