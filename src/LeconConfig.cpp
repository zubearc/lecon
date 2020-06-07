#include "LeconConfig.h"

FontType globalDefaultFont = FontType::Old;

char cLowBrightness = false;

unsigned int loops = 0;
//LeconMode programMode = (LeconMode)13;
LeconMode programMode = LeconMode::DisplayingDefault;
Screen* screen = nullptr;
THREADLOCAL Window* globalWindow = nullptr;

void initBoard(int height, int width) {
	screen = new Screen(height, width);
	globalWindow = new Window(width, height);
}


void setBoardBrightness(unsigned char level) {
#ifdef _WS2812
	ledstring.channel[0].brightness = level;
#endif
}

unsigned char getBoardBrightness() {
#ifdef _WS2812
	return ledstring.channel[0].brightness;
#else
	return 100;
#endif
}
