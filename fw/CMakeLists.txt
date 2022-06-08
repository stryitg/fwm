add_library(MSP INTERFACE)
target_include_directories(MSP INTERFACE ${MSP_INCLUDE})
target_link_directories(MSP INTERFACE ${MSP_INCLUDE})

add_executable(fw main.cpp)
target_link_libraries(fw 
	MSP)