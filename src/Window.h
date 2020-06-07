#pragma once

#include "Util.h"
#include "Screen.h"

struct Window {
    int height = 0;
    int width = 0;
    int size = 0;
    uint32_t *matrix = 0;

    int x = 0;
    int y = 0;

    Window(int width, int height, int x = 0, int y = 0) {
        this->width = width;
        this->height = height;
        this->size = width * height;
        this->matrix = new unsigned int[width * height](); //< 0 filled
        this->x = x;
        this->y = y;
    }

    int get(int x, int y) {
        auto i = this->width * y + x;
        if (i > this->size) {
            return 0;
        }
        _ASSERT(i <= this->size);
        return this->matrix[i];
    }

    void set(int x, int y, int val) {
        auto i = this->width * y + x;
        if (i > this->size) {
            return;
        }
        _ASSERT(i <= this->size);
        this->matrix[i] = val;
    }

    void clear() {
        for (int i = 0; i < this->size; i++) {
            this->matrix[i] = 0;
        }
    }

    void drawTo(Screen *screen) {
        _ASSERT(screen);
        auto xoff = this->x;
        auto yoff = this->y;
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                auto val = this->get(x, y);
                auto X = x + xoff;
                auto Y = y + yoff;
                screen->set(X, Y, val);
            }
        }
    }   

    ~Window() {
        delete[] matrix;
    }
};