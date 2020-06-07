#pragma once

#if 0

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

#include "WS2812Render.h"

#define NUM_LEDS LED_COUNT
#define DATA_PIN 6

inline void matrix_clear2(Window *window) {
    for (int i = 0; i < window->size; i++) {
        window->matrix[i] = 0;
    }
    // int x, y;

    // for (y = 0; y < (height ); y++) {
    //     for (x = 0; x < width; x++) {
    //         matrix[y * width + x] = 0;
    //     }
    // }
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

void draw(Window *window, int offset, long color);

void draw(Window *window,int x, int y, long color);

char drawChar(Window *window,short xoff, short yoff, char c, long rgb, FontType font = FontType::Old, bool dry = false);

int dryWrite(Window *window,const String &text, FontType font);

int write(Window *window,const String &text, long rgba, FontType font = FontType::Old);

void write(Window *window,const String &text, long rgba, int x, int y = 0, FontType font = FontType::Old);

void write(Window *window, int num, long rgba);

void writePixels(Window *window, std::vector<XY> &buffer, int color, int xoff = 0);

void writePixels(Window *window, std::vector<XY> &buffer, std::vector<int> colors, int xoff = 0);

// Draw

inline void draw(int offset, long color) {
    draw(&globalWindow, offset, color);
}

inline void draw(int x, int y, long color) {
    draw(&globalWindow, x, y, color);
}

inline char drawChar(short xoff, short yoff, char c, long rgb, FontType font = FontType::Old, bool dry = false) {
    return drawChar(&globalWindow, xoff, yoff, c, rgb, font, dry);
}

inline int dryWrite(const String &text, FontType font) {
    return dryWrite(&globalWindow, text, font);
}

inline int write(const String &text, long rgba, FontType font = FontType::Old) {
    return write(&globalWindow, text, rgba, font);
}

inline void write(const String &text, long rgba, int x, int y = 0, FontType font = FontType::Old) {
    write(&globalWindow, text, rgba, x, y, font);

}

inline void write(int num, long rgba) {
    write(&globalWindow, num, rgba);
}

inline void writePixels(std::vector<XY> &buffer, int color, int xoff = 0) {
    writePixels(&globalWindow, buffer, color, xoff);

}

inline void writePixels(std::vector<XY> &buffer, std::vector<int> colors, int xoff = 0) {
    writePixels(&globalWindow, buffer, colors, xoff);
}

// Redner

void render(Window *window);

inline void render() {
    render(&globalWindow);
}


void flushLeft(Window *window, int offset = 255);

void flushRight(Window *window, int offset = 255);

inline void flushLeft(int offset = 255) {
    return flushLeft(&globalWindow, offset);
}

inline void flushRight(int offset = 255) {
    return flushRight(&globalWindow, offset);
}

inline void flush(Window *window) {
	matrix_clear2(window);
}

inline void flush() {
    return flush(&globalWindow);
}

// Low-Level Buffer

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

#endif