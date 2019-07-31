#pragma once

#include <unistd.h>

#define PIXEL_COLUMNS 32
#define PIXEL_ROWS 8


typedef unsigned char u8;
#define PROGMEM
#include <string>
using String = std::string;

extern unsigned int loops;

inline unsigned int randr(unsigned int min, unsigned int max) {
	double scaled = (double)rand() / RAND_MAX;

	return (max - min + 1) * scaled + min;
}

inline void SleepMS(int milliseconds) {
    usleep(milliseconds * 1000);
}

