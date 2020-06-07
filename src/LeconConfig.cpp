#include "LeconConfig.h"

FontType globalDefaultFont = FontType::Old;

char cLowBrightness = false;

unsigned int loops = 0;
LeconMode programMode = LeconMode::DisplayingDefault;
Screen* screen = nullptr;
THREADLOCAL Window* globalWindow = nullptr;

void initBoard(int height, int width) {
	screen = new Screen(height, width);
	globalWindow = new Window(width, height);
}