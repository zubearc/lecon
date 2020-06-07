cmake_minimum_required(VERSION 3.7)

project (Lecon)

file(GLOB_RECURSE sources src/*.c src/*.cpp)


find_package(CURL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)

link_libraries(${CURL_LIBRARIES})
include_directories(${CURL_INCLUDE_DIRS})

add_executable(Lecon src/Lecon.cpp src/ ${sources})


include_directories(src/ /home/pi/Documents/LED/rpi_ws281x/)
link_directories(/home/pi/Documents/LED/rpi_ws281x/)

target_link_libraries (Lecon /home/pi/Documents/LED/rpi_ws281x/libws2811.a)
target_link_libraries (Lecon pthread)
add_definitions(-D_WS2812)