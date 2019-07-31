#include "Render.h"
#include "Values.h"

void draw(int offset, long color) {
	u8 green = (color & 0xFF0000) >> (24 - 8);
	u8 red = (color & 0x00FF00) >> (16 - 8);
	u8 blue = (color & 0x0000FF) >> (8 - 8);

	if (color == 0xf0)
	{
		red = randr(0, 100);
		green = randr(0, 100);
		blue = randr(0, 100);
		color = pack(0, blue, green, red);
	}
	// printf("FakeDraw(%d,%d) %d RGB(%d, %d, %d)\n", 0, color, offset, red, green, blue);

    if (lowBrightness) {
        red = MIN(0x20, red);
        green = MIN(0x20, green);
        blue = MIN(0x20, blue);
		color = pack(0, red, green, blue);
    }

	// printf("FakeDraw(%d,%d) %d RGB(%d, %d, %d)\n", 0, 0, offset, red, green, blue);

	if (offset >= NUM_LEDS) {
		return;
	}

	// printf("offset %d\n", color);
	//BGR

	matrix[offset] = color;
	return;
}

void draw(int x, int y, long color) {
	int offset = pixelMapToNP(x, y);

	//printf("FakeDraw(%d,%d) %d RGB(%d)\n", x, y, offset, color);

	if (offset >= NUM_LEDS) {
		return;
	}

	//printf("offset %d\n", offset);
	//leds[offset] = CRGB(red, /*randr(0x20, 0xEE)*/green, blue);
	draw(offset, color);
	return;
}

#define RB *

char drawChar(char xoff, char yoff, char c, long rgb) {
	//auto pm = C[c];
	if (c == '~') return 0;
	const XY *pm = 0;
	int len = 0;
	getChar(c, pm, len);
	//printf("charlen:%d\n",len);
	if (!len)
	{
		return 1; // dont have pixel map for char, spaces
	}
	//printf("pm.x, pm.y %d %d\n", char0[0].x, char0[0].y);
	int cwidth = 0;
	for (int i = 0; i < len; i++)
	{
		auto pix = pm[i];
		cwidth = MAX(cwidth, pix.x + 1);
		auto x = pix.x + xoff;
		auto y = pix.y + yoff;
		if (x >= PIXEL_COLUMNS || y >= PIXEL_ROWS || x < 0 || y < 0)
			continue;
		draw(x, y, rgb);
		// table[y][x] = style || 'background-color: green;';
	}
	return cwidth;
}

int write(String text, long rgba) {
	auto x = 0;
	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(x, 0, c, rgba);
		x += lwlen + 1;
	}

    return x;
}

void write(String text, long rgba, int x, int y) {
	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(x, y, c, rgba);
		x += lwlen + 1;
	}
}

void write(int num, long rgba) {
    char str[4];
	sprintf(str, "%d", num);

	//write("HELLO", 0xff000000);
	write(str, 0x00ff0000);
}

/*void write(char *data, int len, long rgba) {
	auto x = 0;
	auto lwlen = 0;
	for (int i = 0; i < len; i++) {
	auto c = data[i];
	lwlen = drawChar(x, 0, c, rgba);
	x += lwlen + 1;
	}

}*/

void writePixels(std::vector<XY> &buffer, int rgb) {
    auto xoff = 0;
    auto yoff = 0;
    auto pm = buffer;
    auto len = buffer.size();
    for (int i = 0; i < len; i++) {
		auto pix = pm[i];
		// cwidth = pix.x + 1;
		auto x = pix.x + xoff;
		auto y = pix.y + yoff;
		if (x >= PIXEL_COLUMNS || y >= PIXEL_ROWS || x < 0 || y < 0)
			continue;
		draw(x, y, rgb);
		// table[y][x] = style || 'background-color: green;';
	}
}