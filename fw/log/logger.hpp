#pragma once

#include <unistd.h>
#include <type_traits>

namespace log
{

class logger
{
public:
	logger() = default;
	logger(const logger &) = delete;
	logger(logger &&) = delete;

	logger & operator=(const logger &) = delete;
	logger & operator=(logger &&) = delete;

	template <typename T>
	logger & operator << (T val);

private:
	void log_char(char c);
	void log_str(const char *str);
	void log_uint(uint16_t val);
	void log_int(int16_t val);

	uint16_t get_floor10_exp(uint16_t val);
};

template <typename T>
logger & logger::operator << (T val)
{
	if constexpr (std::is_same_v<T, char>)
	{
		log_char(val);
	}
	else if constexpr (std::is_same_v<T, const char *>)
	{
		log_str(val);
	}
	else if constexpr (std::is_unsigned_v<T>)
	{
		log_uint(val);
	}
	else if constexpr (std::is_integral_v<T>)
	{
		log_int(val);
	}
	return *this;
}


}

