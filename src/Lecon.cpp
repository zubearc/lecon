// A simple program that computes the square root of a number
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
#include "Render.h"
#include "PixelSequences.h"
#include "PixelSequenceTime.h"
#include "PixelSequenceAlert.h"

#include "PixelSequenceWeather.h"

//

unsigned int loops = 0;

void matrix_render(void) {
    int x, y;

    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            ledstring.channel[0].leds[(y * width) + x] = matrix[y * width + x];
        }
    }
}

void matrix_raise(void) {
    int x, y;

    for (y = 0; y < (height - 1); y++) {
        for (x = 0; x < width; x++) {
            // This is for the 8x8 Pimoroni Unicorn-HAT where the LEDS in subsequent
            // rows are arranged in opposite directions
            matrix[y * width + x] = matrix[(y + 1) * width + width - x - 1];
        }
    }
}

void matrix_clear(void) {
    int x, y;

    for (y = 0; y < (height); y++) {
        for (x = 0; x < width; x++) {
            matrix[y * width + x] = 0;
        }
    }
}

int dotspos[] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7
};
ws2811_led_t dotcolors[] = {
    0x00200000, // red
    0x00201000, // orange
    0x00202000, // yellow
    0x00002000, // green
    0x00002020, // lightblue
    0x00000020, // blue
    0x00100010, // purple
    0x00200010, // pink
};

ws2811_led_t dotcolors_rgbw[] = {
    0x00200000, // red
    0x10200000, // red + W
    0x00002000, // green
    0x10002000, // green + W
    0x00000020, // blue
    0x10000020, // blue + W
    0x00101010, // white
    0x10101010, // white + W

};

void matrix_bottom(void) {
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(dotspos)); i++) {
        dotspos[i]++;
        if (dotspos[i] > (width - 1)) {
            dotspos[i] = 0;
        }

        if (ledstring.channel[0].strip_type == SK6812_STRIP_RGBW) {
            matrix[dotspos[i] + (height - 1) * width] = dotcolors_rgbw[i];
        } else {
            matrix[dotspos[i] + (height - 1) * width] = dotcolors[i];
        }
    }
}

//

static void ctrl_c_handler(int signum) {
    (void)(signum);
    running = 0;
}

static void setup_handlers(void) {
    struct sigaction sa = {
        ctrl_c_handler,
    };

    sigaction(SIGINT, & sa, NULL);
    sigaction(SIGTERM, & sa, NULL);
}

//

int main2(int argc, char * argv[]) {
    if (argc < 2) {
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}

void qDisplayNearby() {
    write("NEARBY!", 0x4040);
    render();

    delay(2000);

    String tx = "Report of Shots Fired";
    writeFlashing(tx, 0x104040);

    String tx1 = " 99 PCT";
    writeScrollable(tx1, 0x4010);
    // render();

    delay(1000);

    String tx2 = "1776 Ave";
    writeScrollable(tx2, 0x40, 100);

    delay(1000);

    String tx3 = " 3M ago";
    writeScrollable(tx3, 0x4010);
    // render();

    delay(1000);
}

void qDisplayAmber() {
    String tx = "DANGER!";
    writeScrollable(tx, 0xFF);
}

int main(int argc, char * argv[]) {
    ws2811_return_t ret;

    loops = 0;

    //sprintf(VERSION, "%d.%d.%d", VERSION_MAJOR, VERSION_MINOR, VERSION_MICRO);

    //parseargs(argc, argv, &ledstring);

    matrix = (ws2811_led_t * ) malloc(sizeof(ws2811_led_t) * width * height);

    printf("mx:%d\n",matrix);

    setup_handlers();

    if ((ret = ws2811_init( & ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    } else {

    }
    int ic = 0;

    String txt = slurp("say.txt");
    printf("slurp'ed %d bytes\n", txt.length());

    qWeatherUpdate();
    qNearbyUpdate();

    while (running) {
        loops++;

        auto hour = getCurrentHour();

        //    matrix_raise();
        //    matrix_bottom();

        // matrix[ic] = 0x00FF0000;

        // txt = slurp("say.txt");

        // ic++;
        // if (ic>255)ic=0;

        write(qGetTimeString(), 0x20);

        // String s = " stealing TIME";
        // writeScrollable(s, 0x20);

        // std::vector<XY> buf = {{0,2},{1,1},{0,5},{1,6},{1,5},{2,2},{2,3},{2,4},{2,4},{7,21},{6,20},{5,19},{4,18},{3,18},{2,19},{2,20},{3,21},{2,22},{2,23},{3,24},{4,24},{5,23},{6,22},{3,19},{3,19},{3,20},{4,22},{3,23},{3,23},{3,22},{4,23},{5,22},{4,21},{5,22},{5,21},{6,22},{6,21},{5,20},{4,20},{4,19},{0,6},{2,6},{2,6},{2,5},{2,1},{0,1},{1,2},{1,3},{1,4},{0,3},{0,4},{0,28},{1,28},{0,29},{1,29},{0,30},{1,31},{1,30},{0,31},{1,10},{0,10},{2,10},{0,11},{1,11},{2,11},{0,12},{1,12},{2,12},{0,13},{1,13},{2,13},{0,14},{1,14},{2,14},{2,27},{2,28},{2,29},{2,30},{2,31},{1,27},{0,27},{7,9},{6,9},{5,9},{5,8},{5,7},{4,7},{3,7},{3,8},{3,9},{3,10},{3,11},{4,11},{5,11},{5,10},{4,8},{4,9},{4,10}};

        // writePixels(buf, 0x2F0000);

        if (qAlertHasNearby()) {
            qNearbyAlertStart();
        }

        if ((loops % 1060) == 0) {
            if (hour > 6 && hour < 18)
                qWeatherUpdate();
            qNearbyUpdate();
        }

        if ((loops % 90) == 0 && hour > 6 && hour < 18) {
            qWeatherStart();
            qWeatherStart();
        }

        // qDisplayNearby();
        // qDisplayAmber();

        // printf("started weather.\n");
        // qWeatherStart();
        // printf("did weather.\n");

        // run_disco();

        // run_text();

        // String tx = "hello world of cookies";
        // writeFlashing(tx, 0x20);

        // writeFlashing(txt, 0xf0);
        // run_weather();

        // String text = "Due to recent severe heat, traffic signals without power may be present in various parts of NYC";
        // // renderLoopText(text, text.length(), 0xf0);
        // writeFlashing(text, 0x400000);
        // String text2 = "Drivers should treat impacted intersections as an all-way stop, except when directed by NYPD";
        // writeFlashing(text2, 0x400000);
        // String text3 = "Drive with caution and always yield to pedestrians and cyclists";
        // writeFlashing(text3, 0x400000);

        matrix_render();

        // drawChar(0, 0, 'A', 0xFF00);

        if ((ret = ws2811_render( & ledstring)) != WS2811_SUCCESS) {
            fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
            break;
        }

        matrix_clear();

        // 15 frames /sec
        usleep(1000000 / 5);
    }

    if (clear_on_exit) {
        matrix_clear();
        matrix_render();
        ws2811_render( & ledstring);
    }

    ws2811_fini( & ledstring);

    printf("\n");
    return ret;
}