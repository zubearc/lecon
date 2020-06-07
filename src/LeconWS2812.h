#pragma once

#ifdef _WS2812
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

extern "C" {
#include <clk.h>
#include <gpio.h>
#include <dma.h>
#include <pwm.h>
#include <version.h>
#include <ws2811.h>
#include "BoardConfig.h"
}

void matrix_clear(void) {
    int x, y;

    for (y = 0; y < (HEIGHT); y++) {
        for (x = 0; x < WIDTH; x++) {
            matrix[y * WIDTH + x] = 0;
        }
    }
}

void matrix_render(void) {
    int x, y;

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[y * WIDTH + x];
        }
    }
}

static void ctrl_c_handler(int signum) {
    (void)(signum);
    running = 0;
}
#endif