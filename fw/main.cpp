#include <leds.hpp>

#include <msp430g2553.h>

int main()
{
	WDTCTL = WDTPW | WDTHOLD;

	leds::init();


	while (true)
	{
		__delay_cycles(1000000);
		leds::toggle_green();
	}
}