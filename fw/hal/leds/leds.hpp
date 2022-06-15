#pragma once

namespace hal
{

class leds
{
public:
	leds() = delete;

	static void init();
	static void toggle_green();
};

}