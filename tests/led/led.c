#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>

/* 
 * In Arduino ATMEGA2560 CH340, LED corresponds to pin 13. 
 * On top of that, pin 13 is associated with Port B7 (PB7)
 * see: https://uelectronics.com/wp-content/uploads/2017/06/PINOUTAR0018-min.png
 *
 * To make LED blink, PORTB7 should have 5V as output (set PORTB to output 5V on 7)
 * and the direction register of that pin should also be set to 1
 * reg = reg | (1 << n), reg: register, n: how many left-shifts [bitwise]
 * to negate: reg = reg &~ (1 << n)
*/

int main(void)
{
  // set PORTB7 as an output
  DDRB = DDRB | (1 << DDB7);

  // loop forever
  while (1) {

    // set PORTB7
    PORTB = PORTB | (1 << PORTB7);

    // wait
    _delay_ms(1000);

    // unset PORTB7
    PORTB = PORTB & ~ (1 << PORTB7);

    _delay_ms(1000);

  }

  return EXIT_SUCCESS;
}
