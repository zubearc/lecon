#pragma once

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

#define ARRAY_SIZE(stuff)       (sizeof(stuff) / sizeof(stuff[0]))

// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18
#define DMA                     10
//#define STRIP_TYPE            WS2811_STRIP_RGB		// WS2812/SK6812RGB integrated chip+leds
#define STRIP_TYPE              WS2811_STRIP_GBR		// WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE            SK6812_STRIP_RGBW		// SK6812RGBW (NOT SK6812RGB)

#define WIDTH                   32
#define HEIGHT                  8
#define LED_COUNT               (WIDTH * HEIGHT)

static int width = WIDTH;
static int height = HEIGHT;
static int led_count = LED_COUNT;

#define BRIGHTNESS 7

static int clear_on_exit = 0;

static ws2811_channel_t channel1{
	GPIO_PIN, // gpionum
	0, //invert
	LED_COUNT,
	STRIP_TYPE,
	0,
	BRIGHTNESS
};

static ws2811_channel_t channel2{};

extern ws2811_t ledstring;

extern ws2811_led_t *matrix;

extern uint8_t running;

extern char lowBrightness;