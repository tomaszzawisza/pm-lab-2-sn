#include <avr/io.h>

uint8_t ledState[] = {0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x18, 0x3C, 0x7E};
uint8_t *pLedState = ledState;
bool state = true;

void togglePinD13(bool state)
{
  PORTB = (state << 5);
  state = !(state);
}

void delay()
{
  for (uint32_t j = 0x2FFFF; j > 0; j--){
    asm volatile("nop");
  }
}

int main()
{
  DDRB |=(1 << 5);
  DDRD |=0xFF;
  while (1){
    togglePinD13(&state);
    delay();
    for (uint8_t i = 0; i < sizeof(ledState); i++){
      PORTD = ledState[i];
      delay();
    }
    pLedState = ledState;
    for (uint8_t i = 0; i < sizeof(ledState); i++){
      PORTD = *pLedState;
      pLedState++;
      delay();
    }
  }
}
