#include <avr/io.h>
#define SOLUTION 0
uint8_t button;
bool state = true;

void togglePinD13(bool *state) {
  PORTB = (*state << 5);
  *state = !(*state);
}

void delay() {
  for (uint32_t j = 0x1FFFF; j > 0; j--)
  asm volatile("nop");
}

int main() {
  DDRB &= !(1 << 0 );
  DDRB |= (1 << 5);
  while (1)
  {
    #if (SOLUTION == 0 )
    button = (PINB & (1 << PINB0));
    if (button == 0) {
      togglePinD13(&state);
      delay();
    }
    else 
    delay();
  #elif (SOLUTION == 1)
  while(!(PINB & (1 << PINB0))){
    togglePinD13(&state);
    delay();
  }
  #endif
  }
}