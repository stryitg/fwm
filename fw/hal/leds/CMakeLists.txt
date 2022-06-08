add_library(leds STATIC leds.cpp)
target_link_libraries(leds PRIVATE
	MSP)
target_include_directories(leds PUBLIC ./)
