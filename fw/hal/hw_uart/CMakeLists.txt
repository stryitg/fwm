add_library(hw_uart STATIC hw_uart.cpp)
target_link_libraries(hw_uart PRIVATE
	MSP)
target_include_directories(hw_uart PUBLIC ./)
