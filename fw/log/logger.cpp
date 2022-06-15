#include <logger.hpp>

#include <hw_uart.hpp>

namespace log
{

void logger::log_char(char c)
{
	hal::hw_uart::write(static_cast<uint8_t>(c));
}

void logger::log_str(const char *str)
{
	while (*str != '\0')
	{
		log_char(*str);
		++str;
	}
}

void logger::log_uint(uint16_t val)
{
	auto exp = get_floor10_exp(val);
	while (exp)
	{
		log_char(static_cast<char>('0' + (val / exp)));
		val %= exp;
		exp /= 10;
	}
}

void logger::log_int(int16_t val)
{
	if (val >= 0)
	{
		log_uint(static_cast<uint16_t>(val));
	}
	else
	{
		log_char('-');
		log_uint(static_cast<uint16_t>(-val));
	}
}

uint16_t logger::get_floor10_exp(uint16_t val)
{
	size_t res = 1;
	while (val /= 10)
	{
		res *= 10;
	}
	return res;
}

}










