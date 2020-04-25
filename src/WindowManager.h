#pragma once

#include "BoardConfig.h"

struct DrawWindow {
    ws2811_led_t *window;
    ws2811_led_t *global_matrix;
};

void wLimitWriteRegion(Window &window, int maxX, int maxY);

void wRestoreWriteRegion(Window &window);

inline void wLimitWriteRegion(int maxX, int maxY) {
    return wLimitWriteRegion(globalWindow, maxX, maxY);
}

inline void wRestoreWriteRegion() {
    return wRestoreWriteRegion(globalWindow);
}

Window wCreateWindow(int _height, int _width, int x = 0, int y = 0);
Window* wCreateWindowPtr(int _height, int _width, int x = 0, int y = 0);

void wDestroyWindow(Window &window);
void wDestroyWindowPtr(Window *window);

// DrawWindow wCreateWriteRegion(int _width, int _height);

// DrawWindow wSetWriteRegion(DrawWindow &window);

// void wDestroyWriteRegion(DrawWindow &window);