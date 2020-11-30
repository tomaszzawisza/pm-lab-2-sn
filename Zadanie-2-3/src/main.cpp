#include <Arduino.h>
volatile int state = LOW;
int main(){
  init();
  DDRB |=B00110000;
  PORTD |= (1<<PORTD2);
  EICRA |=(1<<ISC00);
  EIMSK |=(1<<INT0);
  sei();
  while(1){
    PORTB |=(1<<PORTB5);
    delay(500);
    PORTB &=(1<<PORTB5);
    delay(500);
  }
}
ISR(INT0_vect){
  state = !state;
  digitalWrite(12,state);
}