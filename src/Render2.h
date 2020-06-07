#pragma once

#include <vector>
#include "Window.h"
#include "PixelFonts2.h"
#include "LeconConfig.h"

namespace Render {

	inline int pack(char c1, char c2, char c3, char c4) {
		return ((int)(((unsigned char)c1) << 24)
			| (int)(((unsigned char)c2) << 16)
			| (int)(((unsigned char)c3) << 8)
			| (int)((unsigned char)c4));
	}

	inline int fastFloor(double V) {
		return ((V) >= 0 ? (int)(V) : (int)((V)-1));
	}

	void draw(Window* window, int offset, long color);

	void draw(Window* window, int x, int y, long color);

	char drawChar(Window* window, short xoff, short yoff, char c, long rgb, FontType font = FontType::Old, bool dry = false);

	int dryWrite(Window* window, const String& text, FontType font);

	int write(Window* window, const String& text, long rgba, FontType font = FontType::Old);

	void write(Window* window, const String& text, long rgba, int x, int y = 0, FontType font = FontType::Old);

	void write(Window* window, int num, long rgba);

	void writePixels(Window* window, std::vector<XY>& buffer, int color, int xoff = 0);

	void writePixels(Window* window, std::vector<XY>& buffer, std::vector<int> colors, int xoff = 0);


	// Rendering

	void render(Window *window);
	void render();

	void flush();
}