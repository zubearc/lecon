#pragma once

#ifdef _WS2812

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <stdarg.h>
#include <getopt.h>

#include "clk.h"
#include "gpio.h"
#include "dma.h"
#include "pwm.h"
#include "version.h"

#include "ws2811.h"
#include "Window.h"

#include "LeconConfig.h"

#define ARRAY_SIZE(stuff)       (sizeof(stuff) / sizeof(stuff[0]))

// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18
#define DMA                     10
//#define STRIP_TYPE            WS2811_STRIP_RGB		// WS2812/SK6812RGB integrated chip+leds
#define STRIP_TYPE              WS2811_STRIP_GBR		// WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE            SK6812_STRIP_RGBW		// SK6812RGBW (NOT SK6812RGB)



// extern __thread int width;
// extern __thread int height;
// extern __thread int led_count;

#define BRIGHTNESS 7
// #define BRIGHTNESS 50


static int clear_on_exit = 0;

extern ws2811_channel_t channel1;
static ws2811_channel_t channel2{};

extern ws2811_t ledstring;

extern ws2811_led_t *matrix;

extern long long boardStateHash;

enum FlushRegion : int {
    Both = 0,
    Left,
    Right
};

// extern FlushRegion flushRegion;

// inline void boardWindowInit() {
//     globalWindow.width = width;
//     globalWindow.height = height;
//     globalWindow.size = led_count;
//     globalWindow.matrix = matrix;
//}

#endif