#pragma once

#include "Screen.h"
#include "Window.h"

#define WIDTH                   64
#define HEIGHT                  8
#define LED_COUNT               (WIDTH * HEIGHT)

#define WRITABLE_WIDTH globalWindow.width
#define WRITABLE_HEIGHT globalWindow.height
#define WRITEABLE_COUNT globalWindow.size


enum class FontType :int {
    Old,
    New
};

extern FontType globalDefaultFont;

extern char cLowBrightness;

#ifdef _WIN32
#define THREADLOCAL
#else
#define THREADLOCAL __thread
#endif


extern Screen* screen;
extern THREADLOCAL Window* globalWindow;


void initBoard(int height, int width);