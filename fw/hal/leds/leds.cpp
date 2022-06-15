#include <leds.hpp>

#include <msp430g2553.h>

namespace hal
{

void leds::init()
{
	P1DIR |= BIT0;
}

void leds::toggle_green()
{
	P1OUT ^= BIT0;
}

}