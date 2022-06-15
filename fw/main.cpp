#include <leds.hpp>
#include <hw_uart.hpp>
#include <log.hpp>

#include <msp430g2553.h>

int main()
{

	WDTCTL = WDTPW | WDTHOLD;
	BCSCTL1 = CALBC1_1MHZ;      // Set DCO
  	DCOCTL  = CALDCO_1MHZ;

	hal::leds::init();
	hal::hw_uart::init();

	// temp s{.v = 3};	
	int n = 3;

	while (true)
	{
		__delay_cycles(1000000);
		hal::leds::toggle_green();

		LOG_INFO << "Hello, world!" << 10 << " " << -42 << " " << 0 << LOG_ENDL;
	}
}