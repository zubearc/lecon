#pragma once

#include <string>
#include <thread>
#ifndef _WIN32
#include <unistd.h>
#endif
#include "Window.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define PIXEL_COLUMNS globalWindow.width
#define PIXEL_ROWS globalWindow.height
#define PROGMEM

typedef unsigned char u8;
typedef std::string String;

extern unsigned int loops;

enum LeconMode {
    DisplayingDefault,
    DisplayingAnimated,
    DisplayingBuffer,
    DisplayingLyrics,
    Blocked,
    Minimal,
};

extern LeconMode programMode;

#ifndef _WIN32
// Threads
extern int childThreadPID;
extern pthread_t childThread;
#endif