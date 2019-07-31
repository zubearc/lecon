cmake_minimum_required(VERSION 3.7)

project (Lecon)

file(GLOB_RECURSE sources src/*.c src/*.cpp)

add_executable(Lecon src/Lecon.cpp src/ ${sources})


include_directories(src/ /home/pi/Documents/LED/rpi_ws281x/)
link_directories(/home/pi/Documents/LED/rpi_ws281x/)

target_link_libraries (Lecon /home/pi/Documents/LED/rpi_ws281x/libws2811.a)
