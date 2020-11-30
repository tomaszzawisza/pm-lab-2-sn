#include <avr/io.h>

int main()
{
  uint32_t i;

  DDRB |= (1 << 5);
  while (1)
  {
    PORTB |= (1 << 5);
    i = 0x3FFFF;
    do
    {
      asm volatile("nop");
    } while (i--);
    PORTB &= !(1<<5);
    i = 0x3FFFF;
    do
    {
      asm volatile("nop");
    } while (i--);

  }
}