#include <leds.hpp>

#include <msp430g2553.h>

namespace leds
{

void init()
{
	P1DIR |= BIT0;
}

void toggle_green()
{
	P1OUT ^= BIT0;
}

}