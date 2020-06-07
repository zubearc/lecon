#include "PixelSequences.h"

#include <algorithm>

#include "WindowManager.h"

void renderVertSlide(bool up, int low, int high, int speed) {
    // matrix_clear2();

    screen->clear();
    //globalWindow->clear();

    for (int a = 0; a < HEIGHT; a++) {
    // for (int a = up ? HEIGHT + 7 : 0; up ? (a > (6)) : (a < WRITABLE_HEIGHT); up ? a-- : a++) {
        for (int x = /*0*/low; x < /*width*/high; x++) {
            for (int y = 0; y < HEIGHT; y++) {
                // auto Y = (y - 7) + a;
                auto Y = up ? (y - 7) + a : (y + 7) - a;
                if (Y < 0 || Y > 7) {
                    continue;
                }

                // auto t = (y * width) + (x + a);
                // auto n = (y * width) + x;
                //auto t = pixelMapToNP(x, Y);
                //auto n = pixelMapToNP(x, y);
                // fprintf(stderr, "Y=%d (%d), t=%d, n=%d\n", Y, (height - y), t, n);
                // if (n < 0 || n > LED_COUNT) {
                //     continue;
                // }


                screen->set(x, y, globalWindow->get(x, Y));
            }
        }

        Render::render();
        delay(speed);
    }
}

void renderVertSlide2(bool reverse, int speed) {
    screen->clear();

    //TODO: _directRender calls may have been replaced, these need to be re-impl'ed
    //because ::render() simply copies globalWindow->screen

    auto halfWidth = Render::fastFloor(screen->width / 2);

    for (int a = 0; a < screen->height; a++) {
        for (int x = 0; x < screen->width; x++) {
            for (int y = 0; y < screen->height; y++) {
                int Y;
                if (x < halfWidth) {
                    Y = reverse ? (y + 7) - a : (y - 7) + a;
                } else {
                    Y = reverse ? (y - 7) + a : (y + 7) - a;
                }
                // auto Y = (y - 7) + a;
                // auto Y = (y + 7) - a;
                if (Y < 0 || Y > 7) {
                    continue;
                }

                // auto t = (y * width) + (x + a);
                // auto n = (y * width) + x;
                //auto t = pixelMapToNP(x, Y);
                //auto n = pixelMapToNP(x, y);
                // fprintf(stderr, "Y=%d (%d), t=%d, n=%d\n", Y, (height - y), t, n);
                // if (n < 0 || n > LED_COUNT) {
                //     continue;
                // }


                screen->set(x, y, globalWindow->get(x, Y));
            }
        }
    //     // return;
    //     // matrix_render2();
    //     // render();
        //ws2811_render(&ledstring);
        Render::render();
        delay(speed);
    }
}

void renderHorizHighlight(int color, int speed, bool reverse) {
	if (color == 0xf0)
	{
		int red = randr(0, 100);
		int green = randr(0, 100);
		int blue = randr(0, 100);
		color = Render::pack(0, blue, green, red);
	}

    for (int x = 0; x < screen->width; x++) {
        for (int y = 0; y < screen->height; y++) {
            auto _x = reverse ? screen->width - 1 - x : x;
            auto _y = y;
            auto pix = screen->get(_x, _y);
            if (pix != 0) {
                screen->set(_x, _y, color);
            }
        }
        //_directRender();
        Render::render();
        delay(speed);
    }
}

void renderScrollingHighlight(const String &text, int lowerColor, int upperColor, int speed, FontType font, bool allowOverdraw) {
    auto len = Render::dryWrite(globalWindow, text, font);
    int xoff = 0;

    auto dif = screen->width - len;
	xoff = Render::fastFloor(dif / 2);

    bool didOverdraw = false;
    int oldWidth = globalWindow->width;
    int oldHeight = globalWindow->height;

    if (len > globalWindow->width) {
        xoff = 0;

        if (allowOverdraw) {
            //wRestoreWriteRegion();
            len = Render::dryWrite(globalWindow, text, font);
            if (len > globalWindow->width) {
                font = FontType::Old;
            }
            didOverdraw = true;
        } else {
            font = FontType::Old;
        }
    } else {
        // fprintf(stderr, "PIXEL_COLUMNS(%d) - len(%d)=%d, floor(/ 2) = %d\n", PIXEL_COLUMNS, len, dif, xoff);
    }

    auto wait_time = speed / text.size();

    for (int i = 0; i < text.size(); i++) {
        Render::flush();
        auto _c = text[i];

        auto x = xoff;
        auto lwlen = 0;
        for (int j = 0; j < text.size(); j++) {
            auto c = text[j];
            lwlen = Render::drawChar(globalWindow, x, 0, c, i >= j ? upperColor : lowerColor, font);
            x += lwlen + 1;
        }

        Render::render();
        delay(wait_time);
    }

    if (didOverdraw) {
        //wLimitWriteRegion(oldWidth, oldHeight);
    }

    return;
}

void renderLoopText(String &text, int textLen, long rgba, int speed, int startingIndex) {
    auto ti = startingIndex;
    
    auto running = true;

    while (running) {
        Render::flush();

        Render::write(globalWindow, text, rgba, ti--);

        // TODO: not use black magic
        auto fw = textLen * 5;
        if ((ti <= -fw)) {
        // if (ti < -60) {
            running = false;
        }

        Render::render();
        delay(speed);
    }
}

void renderScrolling(const String &text, int textLen, long rgba, int until, int speed, int startingIndex, FontType font) {
    auto ti = startingIndex;
    
    auto running = true;

    while (running) {
        Render::flush();

        Render::write(globalWindow, text, rgba, ti--, 0, font);

        // write(CurrentTimeMS() & 0xFFFFFF, 0x20);

        // write(textRenderLen, 0x20);

        // TODO: not use black magic
        // auto fw = textLen * 5;
        // Serial.println(ti);
        // Serial.println(PIXEL_COLUMNS - until);
        if (ti <= (globalWindow->width - until)) {
        // if (ti < -60) {
            running = false;
        }

        Render::render();
        delay(speed);
    }
    delay(1050);
}

void renderScrolling2(const String &text, int textLen, long rgba, int until, int speed, int startingIndex, FontType font) {
    // if ()
}

void writeScrollable(const String &text, long color, int speed, FontType font) {
    Render::flush();
    auto w = Render::write(globalWindow, text, color, font);
    // flush();
    // write(w, color);
    // render();
    // delay(1000);
    // return;
    if (w > globalWindow->width) {
        return renderScrolling(text, text.length(), color, w, speed, 0, font);
    } else {
        Render::render();
    }
}

void writeFlashing(const String &text, long color, int speed, int startingIndex) {
    // auto s = text.split(' ');
    auto ti = startingIndex;
    auto tempTime = 0;

    int pos = 0;
    String s;

    while (splitString(' ', text, pos, s)) {
        Render::flush();
		// Serial.println(s);
        auto len = Render::write(globalWindow, s, color);

        if (len > globalWindow->width) {
            Render::flush();
            Render::write(globalWindow, s, color, FontType::Old);
            // render();
            // delay(400);
            // renderScrolling(s, s.length(), color, len, 100);
        }

        Render::render();
        if (len < 30)
            delay(speed);
        else
            delay(speed + 300);
    }
    // flush();
    // render();

    auto timer = nullptr;
}

void writeFlashingTimed(const String &text, long color, int completeWithinMS, bool allowOverdraw) {
    auto tempTime = 0;

	auto count = std::count(text.begin(), text.end(), ' ') + 1;
	if (count == 0) {
		return writeFlashing(text, color);
	}
	float speed = (float)abs(completeWithinMS) / (float)count;
	// printf("%d / %d -> Speed: %4.4f\n", completeWithinMS, count, speed);

    int pos = 0;
    String s;

    while (splitString(' ', text, pos, s)) {
        Render::flush();
		// Serial.println(s);

//
        // renderScrollingHighlight(s, 0x20, 0x2000F0, speed);
        renderScrollingHighlight(s, 0x20, color, speed, FontType::New, allowOverdraw);
        continue;
//

        auto len = Render::write(globalWindow, s, color);

        if (len > globalWindow->width) {
            Render::flush();
            Render::write(globalWindow, s, color, FontType::Old);
            // render();
            // delay(400);
            // renderScrolling(s, s.length(), color, len, 100);
        }

        Render::render();
        // if (len < 30)
            // delay(speed - 100);
        // else
            delay(speed);
    }
    // flush();
    // render();

    auto timer = nullptr;
}

void wipe(int time) {
    auto sleep_time = time / globalWindow->width;
    // printf("Sleep time:%d\n",sleep_time);
    for (int x = 0; x < globalWindow->width; x++) {
        for (int y = 0; y < globalWindow->height; y++) {
            Render::draw(globalWindow, x, y, 0);
        }

        Render::render();
        delay(sleep_time);
    }
}


void displayFlyingArrow(bool rightToLeft, int startX, int endX) {
    //_directFlush();
    //_directRender();
    screen->clear();
    delay(1000);

    for (int x = 0; x < globalWindow->width; x+=3) {
        //_directFlush();
        screen->clear();
        for (int y = 0; y < (globalWindow->width - 1); y++) {
            auto _x = (x + y) - 1;
            auto _y = y;
            for (int X = 0; X < _x; X++) {
                screen->set(x, _y, globalWindow->get(X, _y));
                //_directDraw(X, _y, getPixel(X, _y));

                // for (int Y = 0; Y < 7; Y++) {
                //     _directDraw(X, Y, getPixel(X, Y));
                // }
            }
            //_directDraw(x + y, y, 0x20);
            screen->set(x + y, y, 0x20);
        }

        Render::render();
        //_directRender();
        delay(30);
    }


    // delay(500);

    // flush();

    // for (int x = 0; x < 64; x+=3) {
    //     for (int y = 0; y < 7; y++) {
    //         auto _x = (x + y) - 1;
    //         auto _y = y;
    //         for (int X = 0; X < _x; X++) {
    //             _directDraw(X, _y, getPixel(X, _y));

    //             // for (int Y = 0; Y < 7; Y++) {
    //             //     _directDraw(X, Y, getPixel(X, Y));
    //             // }
    //         }
    //         _directDraw(x + y, y, 0x20);
    //     }
    //     _directRender();
    //     delay(40);
    // }
    
}


// custom

void run_weather() {
    globalWindow->clear();
	//flush();
	Render::write(globalWindow, "   79` F", 0xFF071585);
	// write("NOW", 0xff0000, 16);
	//render();
    Render::render();
	delay(2000);

	//  write("partly cloudy with rain expected", 0xC7158500);
	////  write("NOW", 0xff0000, 16);
	//  render();
	//  delay(2000);

    globalWindow->clear();
	//flush();
	Render::write(globalWindow, "81`", 0x2000);
	Render::write(globalWindow, "1 HR", 0x2000, 16);
	Render::render();
	delay(2000);

	//flush();
    globalWindow->clear();
	Render::write(globalWindow, "79`", 0x2000);
	Render::write(globalWindow, "2 HR", 0x2000, 16);
	Render::render();
	delay(2000);
}


// void drawBottomScroller() {
// 	auto i = loops % 32;
// 	draw(31 - i, 0, 0xf0);
// 	draw(i, 7, 0xf0);

//   auto ip = (loops - 1) % 32;

//   draw(31 - ip, 0, 0);
//   draw(ip, 7, 0);

// 	//  render();
// }

void run_disco() {
    globalWindow->clear();
    //flush();
	
    for (int i = 0; i < 32; i++) {
		Render::draw(globalWindow, randr(0, 31), randr(0, 7), /*0xFF00*/ 0xf0);
		//      flush();
		//      draw(i, 0xf0);
		//      render();
		//      delay(200);
	}

	delay(150);

	Render::render();
}

void run_disco2() {
	for (int i = 0; i < LED_COUNT; i++) {
		//    draw(randr(0,31), randr(0, 7),  /*0xFF00*/0xf0);
        globalWindow->clear();
		Render::draw(globalWindow, i, 0xf0);
		Render::render();
		delay(200);
	}
}

int logo_id = 0;
int logo_flyin = -10;
int logo_loops = 10;

String texts[] = {"good morning!", "have a nice day", "spacex is going to MARS", "  BIDEN 2020", "   hello!", ""};

void run_text() {
    //flush();
    globalWindow->clear();
	//  write("partly cloudy w rain later", 0xff00, logo_loops--);
	//  write("police stand back 300 feet", 0xff00, logo_loops--);

	//    write("1141 underhill ave", 0xff00, logo_loops--);

	Render::write(globalWindow, texts[logo_id], 0x2000, logo_loops--, logo_flyin);
	if ((logo_flyin + 1) != 1) {
		logo_flyin++;
	}

	//  write("the train approaching the station is not in service", 0xff0000, logo_loops--);

	// drawBottomScroller();

	Render::render();
	delay(100);

	if (logo_loops < -120) {
		logo_loops = 10;
		logo_flyin = -10;
		logo_id++;
		if (logo_id > 4)
			logo_id = 0;
	}

	//  flush();
	//  write("B", 0);
	//  render();
	//  delay(1000);

	/*flush();
	write("NICE",0);
	render();
	delay(3000);*/

	//flush();
	/*write("DAY!", 0);
	render();
	delay(1000);*/
	return;
}

