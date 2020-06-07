#pragma once

#ifdef _WS2812

inline long long _ws2812MatrixRender(ws2811_led_t* matrix) {
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

inline int _ws2812PixelMap(int x, int y) {
    int pixnum = x * 8;
    if (x % 2) {
        pixnum += 7 - (y % 8);
    }
    else {
        pixnum += y % 8;
    }

    return pixnum;
}

inline void _ws2812DirectRender() {
    ws2811_render(&ledstring);
}

#endif