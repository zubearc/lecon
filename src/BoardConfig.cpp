#include "BoardConfig.h"

#ifdef _WS2812

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
	25,
	// BRIGHTNESS
};

ws2811_led_t *matrix = 0;

char lowBrightness = false;

FontType globalDefaultFont = FontType::Old;


#endif