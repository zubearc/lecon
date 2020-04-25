#include "Render.h"
#include "Values.h"
#include "Util.h"

long long boardStateHash = 0;

long long matrix_render2(Window *window) {
    int x, y;
    long long hash = 0;

    for (x = 0; x < window->width; x++) {
        for (y = 0; y < window->height; y++) {
			if ((x + window->xOffset) > WIDTH) {
				break;
			}
			auto inew = pixelMapToNP(x + window->xOffset, y + window->yOffset);//((y + window->yOffset) * WIDTH) + (x + window->xOffset);
			auto iold = pixelMapToNP(x, y);
			if (inew < LED_COUNT && inew >= 0) {
				auto v = window->matrix[iold];
				if (v != 0) {
					// v = (y % 2) == 0 ? 0x20 : 0x200000;
				}
				
				_directDraw(inew, v);
    	        hash += (x * y) + _directGet(inew);

				// if (inew > 256) {
		        //     ledstring.channel[1].leds[256 - inew] = v;
    	        // 	hash += (x * y) + ledstring.channel[1].leds[256 - inew];
				// } else {
		        //     ledstring.channel[0].leds[inew] = v;
    	        // 	hash += (x * y) + ledstring.channel[0].leds[inew];
				// }
			} else {
				continue;
			}
        }
    }
    return hash;
}

long long overlay(Window *window, Window *onTo) {
    int x, y;
    long long hash = 0;

    for (x = 0; x < window->width; x++) {
        for (y = 0; y < window->height; y++) {
			if ((x + onTo->xOffset) > WIDTH) {
				printf("%d + %d > WIDTH\n", x, onTo->xOffset);
				break;
			}
			auto inew = pixelMapToNP(x, y);//((y + window->yOffset) * WIDTH) + (x + window->xOffset);
			auto iold = pixelMapToNP(x - window->xOffset, y - window->yOffset);

			// auto inew = pixelMapToNP(x + onTo->xOffset, y + onTo->yOffset);//((y + window->yOffset) * WIDTH) + (x + window->xOffset);
			// auto iold = pixelMapToNP(x - window->xOffset, y - window->yOffset);
			// if (inew < onTo->size && inew >= 0 && x < onTo->width && iold < window->size && iold >= 0) {	
			// printf("P1: inew < onTo->size=%d, inew >= 0=%d, x < onTo->width=%d, iold < window->size=%d, iold >= 0=%d\n", 
			// 	inew < onTo->size, inew >= 0, x < onTo->width, iold < window->size, iold >= 0);
			if (inew < onTo->size && inew >= 0 && x < onTo->width && iold < window->size && iold >= 0) {
				auto v = window->matrix[iold];
				if (v != 0) {
					// v = (y % 2) == 0 ? 0x20 : 0x200000;
				}
	            onTo->matrix[inew] = v;
            	hash += (x * y) + onTo->matrix[inew];
			} else {
				continue;
			}
        }
    }
    return hash;
}

long long matrix_render2() {
    int x, y;
    long long hash = 0;

    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
			auto i = (y * width) + x;
			_directDraw(i, matrix[y * width + x]);
	        hash += (x * y) + _directGet(i);

			// if (i > 256) {
	        //     ledstring.channel[0].leds[256 - i] = matrix[y * width + x];
	        //     hash += (x * y) + ledstring.channel[0].leds[256 - i];
			// } else {
	        //     ledstring.channel[0].leds[i] = matrix[y * width + x];
    	    //     hash += (x * y) + ledstring.channel[0].leds[i];
			// }
        }
    }

    return hash;	
}


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
	draw(window, offset, color);
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
	overlay(window, &globalWindow);
	auto hash = matrix_render2(&globalWindow);
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