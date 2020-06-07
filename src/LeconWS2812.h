#pragma once

#ifdef _WS2812
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

extern "C" {
#include <clk.h>
#include <gpio.h>
#include <dma.h>
#include <pwm.h>
#include <version.h>
#include <ws2811.h>
#include "BoardConfig.h"
}

int childThreadPID = 0;
pthread_t childThread;

static void ctrl_c_handler(int signum) {
    (void)(signum);
    running = 0;
}

void resumeNormalOperations(int signum) {
    printf("GOT resumeNormalOperations!\n");
    flush();
    programMode = DisplayingDefault;
    slideIn = true;
}

static void setup_handlers(void) {
    struct sigaction sa = {
        ctrl_c_handler,
    };

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    struct sigaction resumeAction = {
        resumeNormalOperations
    };

    sigaction(SIGUSR1, &resumeAction, NULL);
}
#endif