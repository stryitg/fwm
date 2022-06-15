#pragma once

#include <unistd.h>


namespace hal
{

class hw_uart 
{
public:
	hw_uart() = delete;
	
	static void init();
	static void write(uint8_t c);
};

}