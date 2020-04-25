#include "BoardConfig.h"

__thread int width = WIDTH;
__thread int height = HEIGHT;
__thread int led_count = LED_COUNT;

ws2811_t ledstring {
	100,
	0,
	0,
	TARGET_FREQ,
	DMA,
	{channel1, channel2}
};

ws2811_channel_t channel1{
	GPIO_PIN, // gpionum
	0, //invert
	LED_COUNT,
	STRIP_TYPE,
	0,
	30
	// BRIGHTNESS
};

ws2811_channel_t channel2{
	GPIO2_PIN, // gpionum
	0, //invert
	LED_COUNT,
	STRIP_TYPE,
	0,
	30
	// BRIGHTNESS
};

ws2811_led_t *matrix = 0;
uint8_t running = 1;

char lowBrightness = false;

FontType globalDefaultFont = FontType::Old;

FlushRegion flushRegion = FlushRegion::Both;


__thread Window globalWindow;

