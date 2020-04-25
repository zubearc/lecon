#include "PSTask.h"

#include "Render.h"
#include "WindowManager.h"
#include "Util.h"

#define delay SleepMS

struct RScrollingTaskParamaters {
    Window win;
    const String text;
    int speed;
    int len;
    Window *parentWindow;

    bool destroy;
};

RTask rCreateScrollingTask(const String &text, long rgba, int speed, int startingIndex, FontType font, Window *parentWindow) {
    auto len = dryWrite(text, font);

    Window *win = wCreateWindowPtr(HEIGHT, MAX(len, parentWindow->width));

    write(win, text, rgba, font);

    // win.xOffset = -16;
    // render(&win);
    // delay(1000);

    // auto running = true;

    // auto params = new RScrollingTaskParamaters{ win, text, speed, len, parentWindow };

    // auto exec = [](void *_params) {
    auto exec = [=]() {
        // auto params = (RScrollingTaskParamaters*)_params;
        // _directFlush();
        // flush(&win);

        win->xOffset -= 1;

        if (win->xOffset <= (parentWindow->width - len)) {
            wDestroyWindowPtr(win);
            write(parentWindow, text, rgba, font);
            matrix_render2(parentWindow);
            // render(parentWindow);
            return false;
        }

        overlay(win, parentWindow);
        // render(parentWindow);
        // render(win);
        delay(speed);
        return true;     
    };

    return RTask{ true, ScrollingTask, (void*)0, exec };
}

bool rDestroyTask(RTask &task) {
    //til C++14 has lambda capture by value via '=' so no need to void* paramaters!
    if (task.paramaters != nullptr) {
        auto args = task.paramaters;
        if (task.id == ScrollingTask) {
            // todo: deal with cleanup
            delete (RScrollingTaskParamaters*)args;
        }
    }
}