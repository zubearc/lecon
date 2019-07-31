#include "BoardConfig.h"

ws2811_t ledstring {
	100,
	0,
	0,
	TARGET_FREQ,
	DMA,
	{channel1, channel2}
};

ws2811_led_t *matrix = 0;
uint8_t running = 1;

char lowBrightness = true;