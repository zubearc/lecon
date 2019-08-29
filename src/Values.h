#pragma once

#include <thread>
#include <unistd.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define PIXEL_COLUMNS width
#define PIXEL_ROWS height


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