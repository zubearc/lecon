#pragma once

#include <functional>
#include "BoardConfig.h"
#include "Values.h"

enum RTasks {
    ScrollingTask = 20
};

struct RTask {
    bool ok;
    int id;
    void *paramaters;
    // std::function<bool(void*)> callback;
    std::function<bool()> callback;
};

RTask rCreateScrollingTask(const String &text, long rgba, int speed, int startingIndex, FontType font, Window *parentWindow);

bool rDestroyTask(RTask &task);