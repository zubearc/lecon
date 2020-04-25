#include "InterfaceTestOS.h"

#include <cstdio>
#include "PixelSequences.h"
#include "WindowManager.h"
#include "PSTask.h"

// bool testosRunning = true;

void iTestosInit() {

}


enum OSOperation {
    None,
    Menu,
    PlaySpotify,
    Play,
    Aborting
};

OSOperation currentOperation = Menu;

void iosStartMenu() {
    Window testosWin = wCreateWindow(8, 5);
    Window testosRightWin = wCreateWindow(8, 64 - 5, 5);

    RTask menuOptionScrollingTask;
    bool runMenuOptionScrollingTask = false;

    std::vector<std::string> iostexts = { "Play Media", "Control Device", "Set an alarm" };

    int menuIndex = 0;

    int thisloops = 0;

    while (currentOperation == Menu) {
        write(&testosWin, "\x86", 0x20);
        matrix_render2(&testosWin);

        if (runMenuOptionScrollingTask) {
            flush(&testosRightWin);
            runMenuOptionScrollingTask = menuOptionScrollingTask.callback();
            matrix_render2(&testosRightWin);
        } else {
            flush(&testosRightWin);
            write(&testosRightWin, iostexts[menuIndex], 0xA0, FontType::New);
            matrix_render2(&testosRightWin);
            _directRender();
            delay(1500);

            rDestroyTask(menuOptionScrollingTask);
            menuOptionScrollingTask = rCreateScrollingTask(iostexts[menuIndex], 0x40, 10, 0, FontType::New, &testosRightWin);
            runMenuOptionScrollingTask = menuOptionScrollingTask.callback();
            matrix_render2(&testosRightWin);
        }

        // auto c = getchar();
        // // printf("Got char: %d\n", c);

        // if (c == 66) {
        // }

        if (thisloops % 20) {
            menuIndex++;
            if (menuIndex > (iostexts.size() - 1)) {
                menuIndex = 0;
            }
        }

        _directRender();
        delay(200);
        thisloops++;
    }

    // while ()
}

void iTestosRun() {
    while (programMode == 20) {

        if (currentOperation == Menu) {
            iosStartMenu();
        } else if (currentOperation == None) {
            renderScrollingHighlight("INVISION", 0x200000, 0xf10000, 600, FontType::Old);
        }

        // flush();

        // write(&testosRightWin, "Play Spotify", 0x20);
        // matrix_render2(&testosRightWin);

        // globalWindow.width = 32;
        // globalWindow.xOffset = 32;
        // globalWindow.size = 8*32;
        // renderScrolling2("Play Something", 0x20, 50);

        // write(&testosRightWin, "Play Media.......", 0x20);
        // matrix_render2(&testosRightWin);




        // if (keepRunningCallback) {
        //     keepRunningCallback = task.callback();
        //     matrix_render2(&testosRightWin);
        //     flush(&testosRightWin);
        // } else {
        //     texti++;
        //     if (texti > (iostexts.size() - 1)) {
        //         texti = 0;
        //     }
        //     rDestroyTask(task);
        //     task = rCreateScrollingTask(iostexts[texti], 0x40, 10, 0, FontType::New, &testosRightWin);
        //     keepRunningCallback = task.callback();
        //     matrix_render2(&testosRightWin);
        // }

        // auto hash = overlay(&testosWin, &testosRightWin);
        // matrix_render2(&testosRightWin);
        // printf("hash: %lld\n", hash);

        // _directRender();

        delay(200);
    }
}