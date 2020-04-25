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

if (SOCKETS)
    find_library(uwebsockets REQUIRED)

	target_link_libraries(Lecon ZLIB::ZLIB)
	target_link_libraries(Lecon OpenSSL::SSL OpenSSL::Crypto)
	target_link_libraries(Lecon ${uv_LIBRARIES})
	target_link_libraries(Lecon ${uwebsockets_LIBRARIES})
	target_link_libraries(Lecon ${OPENSSL_LIBRARIES})

    message("ZLIB install lib dir is ${ZLIB_LIBRARIES}")
	message("OPENSSL intall lib dir is ${OPENSSL_LIBRARIES}")

    include_directories(${uwebsockets_INCLUDE_DIR})
#	add_compile_definitions(WEBSOCKETS)
	add_definitions(-DWEBSOCKETS)
endif()