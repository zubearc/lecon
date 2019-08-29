#pragma once

#include "BoardConfig.h"

inline void wLimitWriteRegion(int maxX, int maxY) {
    width = maxX;
    height = maxY;
    led_count = width * height;
}

inline void wRestoreWriteRegion() {
    width = WIDTH;
    height = HEIGHT;
    led_count = LED_COUNT;
}