#pragma once

#include <vector>
#include <stdint.h>

extern "C" {
#include <clk.h>
#include <gpio.h>
#include <dma.h>
#include <pwm.h>
#include <version.h>
#include <ws2811.h>
#include "BoardConfig.h"
}

#include "Values.h"
#include "PixelFonts2.h"

#define NUM_LEDS LED_COUNT
#define DATA_PIN 6

inline long long matrix_render2(void) {
    int x, y;
    long long hash = 0;

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[y * WIDTH + x];
            hash += (x * y) + matrix[y * WIDTH + x];
        }
    }
    return hash;
}

inline void matrix_clear2(void) {
    int x, y;

    for (y = 0; y < (height ); y++)
    {
        for (x = 0; x < width; x++)
        {
            matrix[y * width + x] = 0;
        }
    }
}

inline int pixelMapToNP(int x, int y) {
	int pixnum = x * 8;
	if (x % 2) {
		pixnum += 7 - (y % 8);
	} else {
		pixnum += y % 8;
	}

	return pixnum;
}

inline int pack(char c1, char c2, char c3, char c4) {
    return ((int)(((unsigned char)c1) << 24)
            |  (int)(((unsigned char)c2) << 16)
            |  (int)(((unsigned char)c3) << 8)
            |  (int)((unsigned char)c4));
}

inline int fastFloor(double V) {
    return ((V) >= 0 ? (int)(V) : (int)((V) - 1));
}

inline int getPixel(int x, int y) {
    auto i = pixelMapToNP(x, y);
    if (i > WRITEABLE_COUNT || i < 0) return 0; //bounds check
    return matrix[i];
}

void draw(int offset, long color);

void draw(int x, int y, long color);

char drawChar(short xoff, short yoff, char c, long rgb, FontType font = FontType::Old, bool dry = false);

int dryWrite(const String &text, FontType font);

int write(const String &text, long rgba, FontType font = FontType::Old);

void write(const String &text, long rgba, int x, int y = 0, FontType font = FontType::Old);

void write(int num, long rgba);

void writePixels(std::vector<XY> &buffer, int color, int xoff = 0);

void writePixels(std::vector<XY> &buffer, std::vector<int> colors, int xoff = 0);

inline void render()
{
	auto hash = matrix_render2();
    if (boardStateHash) {
        if (hash == boardStateHash) {
            // fprintf(stderr, "%lld == %lld, not rendering!\n", hash, boardStateHash);
            return;
        } else {
            // fprintf(stderr, "%lld!\n", hash);
        }
    }
    // printf("Hash: %d\n", hash);
    boardStateHash = hash;
	ws2811_render(&ledstring);
}

inline void flushLeft(int offset = 255) {
    for (int i = 0; i < offset; i++) {
        matrix[i] = 0;
    }
}

inline void flushRight(int offset = 255) {
    for (int i = 0; i < offset; i++) {
        matrix[(WRITEABLE_COUNT - 1) - i] = 0;
    }
}

inline void flush() {
    if (flushRegion == Left) {
        return flushLeft();
    }
	matrix_clear2();
}

inline void _directDraw(int x, int y, int color) {
    // auto i = (x * width) + y;
    auto i = pixelMapToNP(x, y);
    if (i > WRITEABLE_COUNT || i < 0) return; //bounds check
    ledstring.channel[0].leds[i] = color;
}

inline void _directFlush() {
    for (int i = 0; i < WRITEABLE_COUNT; i++) {
        ledstring.channel[0].leds[i] = 0;
    }
}

inline void _directFlush(int startX, int endX, int startY, int endY) {
    for (int x = startX; x < endX; x++) {
        for (int y = startY; y < endY; y++) {
            auto i = (y * width) + x;
            if (i > WRITEABLE_COUNT || i < 0) continue; //bounds check
            ledstring.channel[0].leds[i] = 0;
        }
    }
}

inline void _directRender() {
    ws2811_render(&ledstring);
}