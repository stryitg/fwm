#include <msp430g2553.h>

int main()
{
	WDTCTL = WDTPW | WDTHOLD;

	P1DIR |= BIT0;
	P1OUT |= BIT0;

	while (true)
	{
		__delay_cycles(1000000);
		P1OUT ^= BIT0;
	}
}