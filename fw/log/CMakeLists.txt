add_library(log STATIC logger.cpp)
target_link_libraries(log PRIVATE
	hw_uart)
target_include_directories(log PUBLIC ./)
