#pragma once

#include <thread>
#include <unistd.h>

#define PIXEL_COLUMNS 32
#define PIXEL_ROWS 8


typedef unsigned char u8;
#define PROGMEM
#include <string>
using String = std::string;

extern unsigned int loops;

enum LeconMode {
    DisplayingDefault,
    DisplayingAnimated,
    DisplayingBuffer,
    DisplayingLyrics,
    Blocked
};

extern LeconMode programMode;

inline unsigned int randr(unsigned int min, unsigned int max) {
	double scaled = (double)rand() / RAND_MAX;

	return (max - min + 1) * scaled + min;
}

inline void SleepMS(int milliseconds) {
    usleep(milliseconds * 1000);
}

extern int childThreadPID;