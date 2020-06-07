#include "Lecon2.h"


#include "LeconConfig.h"
#include "Render2.h"
#include "PixelSequences.h"
#include "PixelSequenceTime.h"
#include "PixelSequenceAlert.h"
#include "PixelSequenceLyrics.h"
#include "PixelSequenceWeather.h"
#include "PixelSequenceText.h"
#include "InterfaceSpotify.h"

bool running = true;
int hour;
bool slideIn = false;

#ifdef _WS2812
#include "LeconWS2812.h"
#endif

bool runInterruptableChecks() {
    iSpotifyNPLTick();
    if (programMode != DisplayingDefault) {
        return true;
    }
    return false;
}

void runDefault() {
    if (qAlertHasNearby()) {
        qNearbyAlertStart();
    }

    if ((loops % 1060) == 0) {
        if (hour > 6 && hour < 18) {
            qWeatherUpdate();
        }
        if (hour > 7 && hour < 18) {
            setBoardBrightness(25);
            //ledstring.channel[0].brightness = 25;
            //ledstring.channel[1].brightness = 25;//patch
        } else if (hour < 7) {
            setBoardBrightness(7);
            //ledstring.channel[0].brightness = 7;
            //ledstring.channel[1].brightness = 25;//patch
        }
        qNearbyUpdate();
    }


    if ((loops % 14) == 0) {
        // printf("would check, [%s]\n", qLyricAuthor.c_str());
        runInterruptableChecks();
    }

    if ((loops % 160) == 0 && hour > 6 && hour < 18) {
        qWeatherStart();
        if (runInterruptableChecks()) {
            return;
        }
        qWeatherStart();
    }
}

void resumeNormalOperations(int signum) {
    printf("GOT resumeNormalOperations!\n");
    globalWindow->clear();
    programMode = DisplayingDefault;
    slideIn = true;
}

void run() {
	initBoard(HEIGHT, WIDTH);

    qWeatherUpdate();
    qNearbyUpdate();
    qTextInit();
    qLyricsInit();

    iSpotifyInit();
    // iSpotifyNPLTick();

    renderScrollingHighlight("INVISION", 0x200000, 0xf10000, 600, FontType::Old);

    int ic = 0;

    while (running) {
        loops++;

        hour = getCurrentHour();

        ic++;
        if (ic > 511)ic = 0;

        // String s = " stealing TIME";
        // writeScrollable(s, 0x20);

        // flush();render();

        globalWindow->clear();

        if (programMode == DisplayingDefault) {
            String ts = qGetTimeString();
            Render::write(globalWindow, ts, 0x30, 32, 0, FontType::Old);

            String ds = qGetDateString();
            // printf("[%s]\n", ds.c_str());
            Render::write(globalWindow, ds, 0x20, 4, 0, FontType::Old);

            // String ts = qGetTimeString();
            // write(ts, 0x30, 0, 0, FontType::Old);

            // String ds = qGetDateString();
            // // printf("[%s]\n", ds.c_str());
            // write(ds, 0x20, 4, 0, FontType::Old);

            if ((loops % 12) != 0) {
                if (ts[0] == ' ') {
                    Render::draw(globalWindow, 6 + 32, 2, 0x20);
                    Render::draw(globalWindow, 6 + 32, 4, 0x20);
                } else {
                    Render::draw(globalWindow, 8 + 32, 2, 0x20);
                    Render::draw(globalWindow, 8 + 32, 4, 0x20);
                }
            }

            // draw(300, 0xFF);
            // draw(33, 0, 0xFF00);
            // write("              hello", 0x2000);
            runDefault();
            // renderScrollingHighlight(qGetTimeString(), 0x20, 0xFF, 1000);
            // writeFlashingTimed("Good Morning have a nice day", 0xFF, 9000, 0);
        } else if (programMode == Minimal) {
            //flushRight(128);
            String ts = qGetTimeString();
            Render::write(globalWindow, ts, 0x300000, 47, 0, FontType::Old);

            if (ts[0] == ' ') {
                Render::draw(globalWindow, WIDTH - 11, 2, 0x200000);
                Render::draw(globalWindow, WIDTH - 11, 4, 0x200000);
            } else {
                Render::draw(globalWindow, WIDTH - 9, 2, 0x200000);
                Render::draw(globalWindow, WIDTH - 9, 4, 0x200000);
            }

            // write(".", 0x300000, WIDTH - 10, 0, FontType::Old);

            if ((loops % 40) == 0) {
                runInterruptableChecks();
            }

            goto finish;
        }
        else if (programMode == DisplayingLyrics) {
            writeScrollable("5", 0xFF);
            delay(2000);
            writeScrollable("4", 0xFF);
            delay(1000);
            writeScrollable("3", 0xFF);
            delay(1000);
            writeScrollable("2", 0xFF);
            delay(1000);
            writeScrollable("1", 0xFF);
            delay(1000);
            qLyricsRun();
        }
        else if (programMode == DisplayingBuffer) {
            /*auto bufloc = slurp("../data/buffer.bin");
            auto buf = loadDisplayLitBuffer(bufloc.data(), bufloc.length());
            writePixels(buf, 0x2F0000);*/
        } else if (programMode == Blocked) {
            if ((loops % 40) == 0) {
                runInterruptableChecks();
            }
            goto finish;
        } else if (programMode == 9) {
            // write(loops, 0x100000);
            // renderScrollingHighlight("123456789", 0x10, 0x50, 4000);
            // runColorTest();
            renderScrollingHighlight("INVISION", 0x200000, 0xf10000, 600, FontType::Old);
            renderScrollingHighlight("INVISION", 0xf10000, 0x200000, 600, FontType::Old);


            renderScrollingHighlight("LECON v2", 0x200000, 0x200000, 600, FontType::Old);

            // runDefault();

            // writeFlashingTimed("We were dysfunctional", 0xF0, 2000, 0);
            // writeScrollable("abcdefghijklmnopqrstuvwxyz", 0x20, 20);
            // writeScrollable("Due to recent severe heat, traffic signals without power may be", 0x300000, 50);

            qTextRun();

            // flush();
            // write("BROOKLYN BRIDGE", 0x20, 0xffff, 0, FontType::Old);
            // render();
            // delay(1000);

            // flush();
            // write("3 AV - 138 ST", 0x20, 0xffff, 0, FontType::Old);
            // render();
            // delay(1000);
        } else if (programMode == 10) {
            // std::vector<XY> buf = {{0,2},{1,1},{0,5},{1,6},{1,5},{2,2},{2,3},{2,4},{2,4},{7,21},{6,20},{5,19},{4,18},{3,18},{2,19},{2,20},{3,21},{2,22},{2,23},{3,24},{4,24},{5,23},{6,22},{3,19},{3,19},{3,20},{4,22},{3,23},{3,23},{3,22},{4,23},{5,22},{4,21},{5,22},{5,21},{6,22},{6,21},{5,20},{4,20},{4,19},{0,6},{2,6},{2,6},{2,5},{2,1},{0,1},{1,2},{1,3},{1,4},{0,3},{0,4},{0,28},{1,28},{0,29},{1,29},{0,30},{1,31},{1,30},{0,31},{1,10},{0,10},{2,10},{0,11},{1,11},{2,11},{0,12},{1,12},{2,12},{0,13},{1,13},{2,13},{0,14},{1,14},{2,14},{2,27},{2,28},{2,29},{2,30},{2,31},{1,27},{0,27},{7,9},{6,9},{5,9},{5,8},{5,7},{4,7},{3,7},{3,8},{3,9},{3,10},{3,11},{4,11},{5,11},{5,10},{4,8},{4,9},{4,10}};        
            // std::vector<XY> buf = {{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{0,20},{0,21},{0,22},{1,23},{1,13},{2,24},{3,24},{4,24},{5,24},{6,24},{7,23},{7,22},{7,21},{7,20},{7,19},{7,18},{7,17},{7,16},{7,15},{7,14},{3,12},{5,12},{6,12},{7,13},{6,18},{5,17},{4,16},{4,19},{4,20},{3,15},{2,15},{2,21},{1,20},{2,19},{1,16},{2,17},{3,18},{3,19},{2,20},{3,21},{3,20},{4,18},{5,19},{5,18},{4,17},{2,16},{3,16},{3,17},{6,3},{6,5},{6,4},{6,7},{7,8},{7,25},{7,26},{7,27},{7,29},{7,30},{7,31},{7,28},{6,29},{6,31},{6,30},{6,1},{7,1},{6,2},{7,3},{7,2},{6,8},{6,9},{7,10},{7,9},{7,7},{7,6},{7,5},{7,4},{6,6},{6,0},{7,0},{6,11},{7,11},{7,12},{7,24},{6,28},{6,27},{6,26},{6,25},{0,0},{1,0},{5,31},{2,31},{3,31},{4,31},{1,31},{0,31},{0,30},{1,30},{3,30},{4,30},{5,30},{5,29},{4,29},{3,29},{2,29},{1,29},{2,30},{0,29},{1,28},{2,28},{3,28},{3,27},{5,28},{4,28},{4,27},{5,27},{5,26},{5,25},{4,25},{4,26},{3,25},{3,26},{2,26},{0,23},{0,24},{1,24},{0,25},{1,25},{2,25},{0,26},{1,26},{0,27},{2,27},{1,27},{0,28},{5,11},{4,12},{4,11},{2,12},{2,11},{1,11},{1,12},{0,13},{0,12},{0,11},{0,10},{0,9},{0,8},{0,6},{0,7},{0,5},{1,4},{0,4},{6,10},{4,10},{3,11},{2,9},{1,8},{3,8},{2,8},{3,10},{1,10},{1,9},{3,9},{2,10},{1,5},{1,6},{1,7},{2,5},{2,6},{2,7},{5,10},{5,9},{4,9},{4,8},{5,8},{4,6},{5,6},{4,7},{5,7},{3,7},{2,3},{3,5},{3,6},{2,4},{3,4},{1,3},{3,3},{1,2},{0,1},{0,2},{0,3},{1,1},{2,2},{2,1},{2,0},{3,0},{3,1},{3,2},{4,5},{5,5},{5,4},{4,4},{4,3},{5,3},{5,2},{4,2},{5,1},{4,1},{4,0},{5,0},};
            // std::vector<XY> buf = {{2,0},{2,1},{1,1},{0,2},{0,3},{1,3},{1,2},{2,3},{2,2},{3,2},{3,3},{4,3},{5,3},{5,2},{4,2},{6,2},{6,3},{7,2},{7,3},{7,6},{7,7},{6,6},{6,7},{5,6},{5,7},{4,6},{4,7},{3,7},{3,6},{2,6},{2,7},{1,6},{1,7},{0,6},{0,7},{0,8},{1,8},{0,9},{1,9},{0,10},{1,10},{3,10},{2,10},{2,11},{3,11},{0,11},{1,11},{4,8},{4,9},{4,11},{5,10},{4,10},{5,11},{5,8},{5,9},{7,13},{7,14},{6,13},{6,14},{5,13},{5,14},{4,13},{4,14},{3,13},{3,14},{2,13},{2,14},{1,14},{1,15},{0,15},{0,16},{0,17},{1,17},{1,16},{1,18},{2,18},{2,19},{3,18},{3,19},{4,19},{4,18},{5,18},{5,19},{7,18},{7,19},{6,18},{6,19},{4,15},{5,15},{4,16},{5,16},{4,17},{5,17},{7,21},{7,22},{6,21},{6,22},{5,21},{5,22},{4,22},{4,21},{3,21},{3,22},{2,21},{2,22},{1,21},{1,22},{0,21},{0,22},{0,23},{1,23},{1,24},{0,24},{0,25},{1,25},{1,26},{0,26},{2,25},{2,26},{3,26},{3,25},{4,25},{4,26},{4,23},{4,24},{5,23},{5,24},{6,24},{6,25},{7,25},{7,26},{0,29},{0,28},{1,28},{1,29},{2,28},{2,29},{3,29},{3,28},{4,28},{4,29},{5,28},{5,29},{6,28},{6,29},{7,28},{7,29},{5,31},{4,31},{3,32},{3,33},{1,33},{2,33},{0,34},{1,34},{6,30},{5,30},{6,31},{7,31},{7,32},{4,32},};
            // std::vector<XY> buf = {{2,0},{1,0},{3,0},{4,0},{5,0},{6,0},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{5,5},{6,5},{2,5},{3,5},{4,5},{1,5},{5,2},{5,3},{3,3},{3,2},{3,4},{0,5},{0,1},{0,0},{0,2},{0,3},{0,4},{1,1},{1,2},{1,4},{1,3},};

            // flush();
            // write("STOCKS", 0x400000, 0xffff, 0, FontType::New);
            // render();
            // delay(2000);

            Render::flush();

            std::vector<XY> buf = { {5,2},{4,2},{3,2},{2,2},{1,2},{2,1},{3,0},{2,3},{3,4},{6,2}, };
            std::vector<int> cols = { 16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680 };

            // std::vector<int> cols = {16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680};
            // std::vector<int> cols = {65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280};
            // std::vector<int> cols = {65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,16711680,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280,65280};
            // writePixels(buf, 0x2000);

            // std::vector<XY> buf2 = {{5,1},{4,2},{3,3},{2,4},{1,5},{1,1},{5,5},{1,0},{6,5},{5,4},{6,4},{6,0},{2,1},{2,0},};//{{5,1},{4,2},{3,3},{2,4},{1,5},{6,0},{0,6},{1,1},{5,5},{1,0},{0,1},{5,6},{6,5},{0,0},{6,6},};
            // std::vector<int> cols2 = {16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680};//{16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680,16711680};

            // writePixels(buf2, 0x200000, 46);

            // std::vector<XY> buf3 = {{3,0},{3,1},{2,1},{3,2},{4,1},};

            // writePixels(buf3, 0x200000, 30);

            Render::write(globalWindow, "\x83", 0x2000);

            Render::write(globalWindow, "MSFT", 0xD00000, 8);

            Render::write(globalWindow, "-", 0x200000, 34);
            Render::write(globalWindow, "12.9", 0x20, 38);
            Render::write(globalWindow, "%", 0x200000, 52);

            renderVertSlide(false, 0, 32);
            // renderVertSlide2(false, 50);

            // render();
            delay(4000);

            // writeScrollable("6  177.BBR   3", 0x20);
            // writeScrollable(txt, 0x20, 30);
        } else if (programMode == 11) {
            Render::flush();

            Render::write(globalWindow, "6", 0x2000);

            Render::write(globalWindow, "177.BBR", 0x20, 10);


            Render::write(globalWindow, "3 M", 0x20, 50);

            Render::render();
            // delay(4000);
        } else if (programMode == 12) {
            writeScrollable("abcdefghijklmnopqrstuvwxyz", 0x20, 20);
        } else if (programMode == 13) {
            //wLimitWriteRegion(32, 8);
            Render::flush();
            String ts = qGetTimeString();
            Render::write(globalWindow, ts, 0x40, 32, 0, FontType::Old);

            String ds = qGetDateString();
            // printf("[%s]\n", ds.c_str());
            Render::write(globalWindow, ds, 0x20, 4, 0, FontType::Old);

            renderVertSlide(false, 0, WIDTH - 1, 50);
            delay(1000);
            renderVertSlide(true, 0, WIDTH - 1, 50);
            delay(1000);
            renderVertSlide2(false, 50);
            delay(1000);
            renderVertSlide2(true, 50);
            delay(1000);
            renderScrollingHighlight("~~" + ds + "~~" + ts, 0x20, 0xC0, 300, FontType::Old);
            delay(1000);
            renderScrollingHighlight("INVISION", 0x200000, 0xf10000, 600, FontType::Old);
            renderScrollingHighlight("INVISION", 0xf10000, 0x200000, 600, FontType::Old);
            delay(1000);
            renderScrollingHighlight("LECON", 0x200000, 0xf0, 600, FontType::Old);
            renderScrollingHighlight("LECON", 0xf0, 0x200000, 600, FontType::Old);
            delay(1000);
            displayFlyingArrow(false, 0, 0);
            delay(1000);
            writeFlashingTimed("HAVE A NICE DAY", 0x200000, 2500);
            writeScrollable("        HAVE A NICE DAY - Scrolling Test", 0x20, 20);
            wipe(1000);

            if ((loops % 2) == 0) {
                //wRestoreWriteRegion();
                programMode = DisplayingDefault;
                writeScrollable("that's it!", 0x2000, 20);
                delay(5000);
            }
        } else if (programMode == 14) {
            // wLimitWriteRegion(32, 8);
            // writeScrollable("THIS", 0x20, 20);
            // renderVertSlide(false, 0, WRITABLE_WIDTH, 30);
            // delay(1000);
            // writeScrollable("IS", 0x20, 20);
            // renderVertSlide(false, 0, WRITABLE_WIDTH, 30);
            // delay(1000);
            // writeScrollable("A", 0x20, 20);
            // renderVertSlide(false, 0, WRITABLE_WIDTH, 30);
            // delay(1000);
            // writeScrollable("TEST", 0x20, 20);
            // renderVertSlide(false, 0, WRITABLE_WIDTH, 30);
            // delay(1000);
            if (loops == 1) {
                Render::flush(); Render::render();
                //wLimitWriteRegion(32, 8);

                String ts = qGetTimeString();
                Render::write(globalWindow, ts, 0x30, 0, 0, FontType::Old);
                Render::render();
                // writeScrollable("Hello", 0x20, 20);
            }
            renderHorizHighlight(0xf0, 20, (loops % 2) == 0);
            goto finish;
        }

        if (slideIn) {
            displayFlyingArrow(false, 0, 0);
            slideIn = false;
        }

        screen->set(0, 0, 1);
        Render::render();
finish:
        // 15 frames /sec
#ifdef _WIN32
        Sleep(200);
#else
        usleep(1000000 / 5);
#endif
    }

}


#ifdef _WS2812

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

int main(int argc, char* argv[]) {
    ws2811_return_t ret;

    loops = 0;

    //sprintf(VERSION, "%d.%d.%d", VERSION_MAJOR, VERSION_MINOR, VERSION_MICRO);

    //parseargs(argc, argv, &ledstring);

    if (argc > 1) {
        if (strcmp(argv[1], "LYRIC") == 0) {
            programMode = DisplayingLyrics;
            printf("Lyric Mode\n");

            programMode = DisplayingLyrics;
        }
        // for (int i =  0; i < argc; i++) {
        //     auto arg = argv[i];
        //     printf("arg[%d] = %s\n", i, arg);
        // }
    }

    matrix = (ws2811_led_t*)malloc(sizeof(ws2811_led_t) * WIDTH * HEIGHT);
    //boardWindowInit();

    printf("mx:%d\n", matrix);

    setup_handlers();

    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }

    run();

    if (clear_on_exit) {
        matrix_clear();
        matrix_render();
        ws2811_render(&ledstring);
    }

    ws2811_fini(&ledstring);

    printf("\n");
    return ret;
}
#endif