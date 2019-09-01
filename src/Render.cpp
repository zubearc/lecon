#include "Render.h"
#include "Values.h"
#include "Util.h"

long long boardStateHash = 0;

void draw(Window *window, int offset, long color) {
	u8 green = (color & 0xFF0000) >> (24 - 8);
	u8 red = (color & 0x00FF00) >> (16 - 8);
	u8 blue = (color & 0x0000FF) >> (8 - 8);

	if (color == 0xf0) {
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

	if (offset >= window->size) {
		return;
	}

	// printf("offset %d\n", color);
	//BGR

	window->matrix[offset] = color;
	return;
}

void draw(Window *window, int x, int y, long color) {
	int offset = pixelMapToNP(x, y);

	//printf("FakeDraw(%d,%d) %d RGB(%d)\n", x, y, offset, color);

	if (offset >= window->size) {
		return;
	}

	//printf("offset %d\n", offset);
	//leds[offset] = CRGB(red, /*randr(0x20, 0xEE)*/green, blue);
	draw(offset, color);
	return;
}

#define RB *

char drawChar(Window *window, short xoff, short yoff, char c, long rgb, FontType font, bool dry) {
	//auto pm = C[c];
	if (c == '~') return 0;
	const XY *pm = 0;
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

int write(Window *window, const String &text, long rgba, FontType font) {
	auto x = 0;
	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(window, x, 0, c, rgba, font);
		x += lwlen + 1;
	}

	return x;
}

int dryWrite(Window *window, const String &text, FontType font) {
	auto x = 0;
	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(window, x, 0, c, 0, font, true);
		x += lwlen + 1;
	}

	return x;
}

void write(Window *window, const String &text, long rgba, int x, int y, FontType font) {

	if (x == 0xffff) {
		auto len = dryWrite(window, text, font);
		auto dif = PIXEL_COLUMNS - len;
		x = fastFloor(dif / 2);
	}

	auto lwlen = 0;
	for (auto c : text) {
		lwlen = drawChar(window, x, y, c, rgba, font);
		x += lwlen + 1;
	}
}

void write(Window *window, int num, long rgba) {
	char str[16];
	sprintf(str, "%d", num);

	//write("HELLO", 0xff000000);
	write(window, str, 0x00ff0000);
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

void writePixels(Window *window, std::vector<XY> &buffer, int rgb, int ox) {
	auto xoff = ox;
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
		draw(x, y, rgb);
		// table[y][x] = style || 'background-color: green;';
	}
}

void writePixels(Window *window, std::vector<XY> &buffer, std::vector<int> colors, int ox) {
	auto xoff = ox;
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
		draw(x, y, colors[i]);
		// table[y][x] = style || 'background-color: green;';
	}
}

//

void render(Window *window) {
	auto hash = matrix_render2(window->matrix);
    if (boardStateHash) {
        if (hash == boardStateHash) {
            // fprintf(stderr, "%lld == %lld, not rendering!\n", hash, boardStateHash);
            return;
        } else {
            // fprintf(stderr, "%lld!\n", hash);
        }
    }
    // printf("Hash: %d\n", hash);
    boardStateHash = hash;
	ws2811_render(&ledstring);
}

void flushLeft(Window *window, int offset) {
    for (int i = 0; i < offset; i++) {
        window->matrix[i] = 0;
    }
}

void flushRight(Window *window, int offset) {
    for (int i = 0; i < offset; i++) {
        window->matrix[(WRITEABLE_COUNT - 1) - i] = 0;
    }
}