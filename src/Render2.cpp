#include "Render2.h"

#include "LeconConfig.h"
#include "Values.h"
#include "Util.h"

#ifdef _WS2812
#include "WS2812Render.h"
#endif

void Render::draw(Window* window, int offset, long color) {
	u8 green = (color & 0xFF0000) >> (24 - 8);
	u8 red = (color & 0x00FF00) >> (16 - 8);
	u8 blue = (color & 0x0000FF) >> (8 - 8);

	if (color == 0xf0) {
		red = randr(0, 100);
		green = randr(0, 100);
		blue = randr(0, 100);
		color = pack(0, blue, green, red);
	}

	if (cLowBrightness) {
		red = MIN(0x20, red);
		green = MIN(0x20, green);
		blue = MIN(0x20, blue);
		color = pack(0, red, green, blue);
	}

	if (offset >= window->size) {
		return;
	}

	window->matrix[offset] = color;
	return;
}

void Render::draw(Window* window, int x, int y, long color) {
	window->set(x, y, color);
	return;
}

char Render::drawChar(Window* window, short xoff, short yoff, char c, long rgb, FontType font, bool dry) {
	if (c == '~') return 0;
	const XY* pm = 0;
	int len = 0;
	getChar(c, pm, len, (int)(font));
	//printf("charlen:%d\n",len);
	if (!len) {
		return 1; // dont have pixel map for char, spaces
	}
	//printf("pm.x, pm.y %d %d\n", char0[0].x, char0[0].y);
	int cwidth = 0;
	for (int i = 0; i < len; i++) {
		auto pix = pm[i];
		cwidth = MAX(cwidth, pix.x + 1); // the positioning on this makes me confused
		// moving it below the continue statement breaks stuff ¯\_(ツ)_/¯
		auto x = pix.x + xoff;
		auto y = pix.y + yoff;

		if (x >= window->width || y >= window->height || x < 0 || y < 0)
			continue;


		if (!dry) {
			// if (c != 'g' && c != 'q' && c != 'y')
			// draw(x, 7, 0x200000);
			draw(window, x, y, rgb);
		}
		// table[y][x] = style || 'background-color: green;';
	}
	return cwidth;
}

int Render::dryWrite(Window* window, const String& text, FontType font) {
	auto x = 0;
	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(window, x, 0, c, 0, font, true);
		x += lwlen + 1;
	}

	return x;
}

int Render::write(Window* window, const String& text, long rgba, FontType font) {

	return 0;
}

void Render::write(Window* window, const String& text, long rgba, int x, int y, FontType font) {
	//Center
	if (x == 0xffff) {
		auto len = dryWrite(window, text, font);
		auto dif = window->width - len;
		x = fastFloor(dif / 2);
	}

	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(window, x, y, c, rgba, font);
		x += lwlen + 1;
	}
}

void Render::write(Window* window, int num, long rgba) {
	char str[16];
	sprintf(str, "%d", num);

	//write("HELLO", 0xff000000);
	write(window, str, 0x00ff0000);
}

void Render::writePixels(Window* window, std::vector<XY>& buffer, int color, int xoff) {
	auto yoff = 0;
	auto pm = buffer;
	auto len = buffer.size();
	for (int i = 0; i < len; i++) {
		auto pix = pm[i];
		// cwidth = pix.x + 1;
		auto x = pix.x + xoff;
		auto y = pix.y + yoff;
		if (x >= window->width || y >= window->height || x < 0 || y < 0)
			continue;
		draw(window, x, y, color);
		// table[y][x] = style || 'background-color: green;';
	}
}

void Render::writePixels(Window* window, std::vector<XY>& buffer, std::vector<int> colors, int xoff) {
	auto yoff = 0;
	auto pm = buffer;
	auto len = buffer.size();
	for (int i = 0; i < len; i++) {
		auto pix = pm[i];
		// cwidth = pix.x + 1;
		auto x = pix.x + xoff;
		auto y = pix.y + yoff;
		if (x >= window->width || y >= window->height || x < 0 || y < 0)
			continue;
		draw(window, x, y, colors[i]);
		// table[y][x] = style || 'background-color: green;';
	}
}

void Render::render(Window* window) {
	window->drawTo(screen);
#ifdef _WS2812
	auto hash = _ws2812MatrixRender(screen);
	if (boardStateHash) {
		if (hash == boardStateHash) {
			// fprintf(stderr, "%lld == %lld, not rendering!\n", hash, boardStateHash);
			return;
		} else {
			// fprintf(stderr, "%lld!\n", hash);
		}
	}
	_ws2812DirectRender();
#endif
}

void Render::render() {

#ifdef _WS2812
	_ws2812MatrixRender(screen);
#else
	Render::render(globalWindow);
#endif


}

void Render::flush() {
	screen->clear();
}
