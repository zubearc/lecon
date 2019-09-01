#pragma once

#include <string>
#include <thread>
#include <unistd.h>
#include "Window.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define PIXEL_COLUMNS globalWindow.width
#define PIXEL_ROWS globalWindow.height
#define PROGMEM

typedef unsigned char u8;
typedef std::string String;

typedef Window Window;

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


// Threads
extern int childThreadPID;
extern pthread_t childThread;