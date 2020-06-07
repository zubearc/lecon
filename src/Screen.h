#pragma once

#include "PixelFonts2.h"

#include <string>

class Screen {
public:
	int height;
	int width;
	int length;

	int* matrix;

	Screen(int height, int width) {
		this->width = width;
		this->height = height;
		this->length = width * height;
		this->matrix = new int[height * width]();
	}

	int get(int x, int y) {
		auto i = this->width * y + x;
		return this->matrix[i];
	}

	void set(int x, int y, int val) {
		auto i = this->width * y + x;
		this->matrix[i] = val;
	}

	int write(char c, int xOff = 0, int yOff = 0) {
		const XY* val = nullptr;
		int len = 0;
		getChar(c, val, len);
		int w = 0;
		for (int i = 0; i < len; i++) {
			auto pix = val[i];
			set(pix.x + xOff, pix.y + yOff, 1);
			w = pix.x > w ? pix.x : w;
		}
		return w + 2;
	}

	int write(std::string str) {
		int xpadding = 0;
		for (auto c : str) {
			xpadding += write(c, xpadding);
		}
		return xpadding;
	}

	void clear() {
		for (int i = 0; i < this->length; i++) {
			this->matrix[i] = 0;
		}
	}

	void draw() {
		for (int y = 0; y < height; y++) {
			printf("%d ", y);
			for (int x = 0; x < width; x++) {
				auto val = get(x, y);
				printf(val >= 1 ? "x" : ".");
			}
			printf("\n");
		}
	}

	~Screen() {
		delete[] matrix;
	}
};