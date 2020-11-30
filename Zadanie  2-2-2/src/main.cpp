#include <avr/io.h>
#define LED_LENGTH 8 

int main(){
  DDRD |= 0xFF;
  while (1){
    for (uint8_t i = 0; i < LED_LENGTH; i++)
    {
      PORTD = (1<<i);
      for (uint32_t j=0x1FFFF; j > 0; j--){
        asm volatile("nop");
      }
    }
    for (uint8_t i = 1; i < (LED_LENGTH - 1); i++){
      PORTD = (PORTD >> 1);
      for (uint32_t j = 0x1FFFF; j > 0; j--)
      {
        asm volatile("nop");
      }
    }
  }
}
