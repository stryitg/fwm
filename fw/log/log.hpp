#pragma once

#include <logger.hpp>

#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG_DETAILS  "[INFO]" << ' ' << '[' <<  __FILENAME__  << '/' << __func__  << ']' << ' '


#define LOG_INFO log::g_out << LOG_DETAILS

#define LOG_ENDL "\r\n";

namespace log
{

inline logger g_out;

}