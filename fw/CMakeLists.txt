add_subdirectory(hal)
add_subdirectory(log)

add_library(MSP INTERFACE)
target_include_directories(MSP INTERFACE ${MSP_INCLUDE})
target_link_directories(MSP INTERFACE ${MSP_INCLUDE})

add_executable(fw main.cpp)
target_link_libraries(fw PRIVATE
	MSP
	leds
	hw_uart
	log)