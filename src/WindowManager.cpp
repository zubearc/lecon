#include "WindowManager.h"

/*void wLimitWriteRegion(Window &window, int maxX, int maxY) {
    // width = maxX;
    // height = maxY;
    // led_count = width * height;

    window.width = maxX;
    window.height = maxY;
    window.size = maxX * maxY;
}

void wRestoreWriteRegion(Window &window) {
    window.width = WIDTH;
    window.height = HEIGHT;
    window.size = LED_COUNT;
}*/

// void wCreateWriteRegion(int _width, int _height) {
//     ws2811_led_t *new_window = (ws2811_led_t *) malloc(sizeof(ws2811_led_t) * _width * _height);
// }