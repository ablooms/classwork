cmake_minimum_required(VERSION 3.0)

project(spiffy_program)

add_executable(spiffy main.c)

# Need this if we need to link to math
#target_link_libraries(spiffy m)
