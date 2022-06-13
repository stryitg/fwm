#include <hw_uart.hpp>

#include <msp430g2553.h>

namespace hw_uart
{

void init()
{
	P1SEL |= BIT2;
	P1SEL2 |= BIT2;

  	UCA0CTL1 |= UCSWRST;
  	
  	// SMCLK 1MHz 9600	
  	UCA0CTL1 |= UCSSEL_2;                     
  	UCA0BR0 = 109;                             
  	UCA0BR1 = 0;                              
  	UCA0MCTL = UCBRS1;                        

  	UCA0CTL1 &= ~UCSWRST;       

}

void write(uint8_t c)
{
	while (!(IFG2 & UCA0TXIFG));

	UCA0TXBUF = c;
}

}


