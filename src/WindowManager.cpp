#include "WindowManager.h"

void wLimitWriteRegion(Window &window, int maxX, int maxY) {
    // width = maxX;
    // height = maxY;
    // led_count = width * height;

    window.width = maxX;
    window.height = maxY;
    window.size = maxX * maxY;
    // window.xOffset = 32;
}

void wRestoreWriteRegion(Window &window) {
    window.width = WIDTH;
    window.height = HEIGHT;
    window.size = LED_COUNT;
    window.xOffset = 0;
}

Window wCreateWindow(int _height, int _width, int x, int y) {
    ws2811_led_t *new_window = new unsigned int[_width * _height]();
    Window window;
    window.width = _width;
    window.height = _height;
    window.size = _width * _height;
    window.xOffset = x;
    window.yOffset = y;
    window.matrix = new_window;
    return window;
}

Window* wCreateWindowPtr(int _height, int _width, int x, int y) {
    ws2811_led_t *new_window = new unsigned int[_width * _height]();
    auto window = new Window;
    window->width = _width;
    window->height = _height;
    window->size = _width * _height;
    window->xOffset = x;
    window->yOffset = y;
    window->matrix = new_window;
    return window;
}

void wDestroyWindow(Window &window) {
    delete[] (window.matrix);
}

void wDestroyWindowPtr(Window *window) {
    delete[] window->matrix;
    delete window;
}


// void wCreateWriteRegion(int _width, int _height) {
//     ws2811_led_t *new_window = (ws2811_led_t *) malloc(sizeof(ws2811_led_t) * _width * _height);
// }