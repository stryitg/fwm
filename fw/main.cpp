#include <leds.hpp>
#include <hw_uart.hpp>

#include <msp430g2553.h>

int main()
{
	WDTCTL = WDTPW | WDTHOLD;
	BCSCTL1 = CALBC1_1MHZ;      // Set DCO
  	DCOCTL  = CALDCO_1MHZ;

	leds::init();
	hw_uart::init();
	

	while (true)
	{
		__delay_cycles(1000000);
		leds::toggle_green();

		hw_uart::write(static_cast<uint8_t>('d'));
	}
}