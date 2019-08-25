#include "PixelSequences.h"

#include <algorithm>


void renderVertSlide(bool up, int low, int high, int speed) {
    // matrix_clear2();

    auto clower = pixelMapToNP(low, 0);
    auto cupper = pixelMapToNP(high, HEIGHT - 1);
    for (int i = clower; i < cupper; i++) {
        ledstring.channel[0].leds[i] = 0;
    }

    for (int a = 0; a < HEIGHT; a++) {
        for (int x = /*0*/low; x < /*width*/high; x++) {
            for (int y = 0; y < HEIGHT; y++) {
                // auto Y = (y - 7) + a;
                auto Y = (y + 7) - a;
                if (Y < 0 || Y > 7) {
                    continue;
                }

                // auto t = (y * width) + (x + a);
                // auto n = (y * width) + x;
                auto t = pixelMapToNP(x, Y);
                auto n = pixelMapToNP(x, y);
                // fprintf(stderr, "Y=%d (%d), t=%d, n=%d\n", Y, (height - y), t, n);
                // if (n < 0 || n > LED_COUNT) {
                //     continue;
                // }

                if (t < 0 || t > LED_COUNT) {
                    continue;
                }

                ledstring.channel[0].leds[n] = matrix[t];
            }
        }
    //     // return;
    //     // matrix_render2();
    //     // render();
        ws2811_render(&ledstring);
        delay(speed);
    }


    // for (int a = 0; a < height; a++) {
    //     for (int x = low; x < high; x++) {
    //         for (int y = 0; y < height; y++) {
    //             // auto Y = (y - height) + a;
    //             // if (Y < 0 || Y > height) {
    //             //     continue;
    //             // }
    //             auto t = y * 32 + x;
    //             auto n = (y * 32) + x;
    //             // auto t = pixelMapToNP(x, y);
    //             // auto n = pixelMapToNP(x, y);
    //             // fprintf(stderr, "Y=%d (%d), t=%d, n=%d\n", Y, (height - y), t, n);
    //             // if (n < 0 || n > LED_COUNT) {
    //             //     continue;
    //             // }

    //             // if (t < 0 || t > LED_COUNT) {
    //             //     continue;
    //             // }

    //             ledstring.channel[0].leds[n] = matrix[t];
    //         }
    //     }
    //     // return;
    //     // matrix_render2();
    //     // render();
    //     ws2811_render(&ledstring);
    //     delay(100);
    // }

    // matrix_render2();
}

void renderVertSlide2(bool up, int speed) {
    for (int i = 0; i < LED_COUNT; i++) {
        ledstring.channel[0].leds[i] = 0;
    }

    for (int a = 0; a < HEIGHT; a++) {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < HEIGHT; y++) {
                int Y;
                if (x < 32) {
                    Y = (y - 7) + a;
                } else {
                    Y = (y + 7) - a;
                }
                // auto Y = (y - 7) + a;
                // auto Y = (y + 7) - a;
                if (Y < 0 || Y > 7) {
                    continue;
                }

                // auto t = (y * width) + (x + a);
                // auto n = (y * width) + x;
                auto t = pixelMapToNP(x, Y);
                auto n = pixelMapToNP(x, y);
                // fprintf(stderr, "Y=%d (%d), t=%d, n=%d\n", Y, (height - y), t, n);
                // if (n < 0 || n > LED_COUNT) {
                //     continue;
                // }

                if (t < 0 || t > LED_COUNT) {
                    continue;
                }

                ledstring.channel[0].leds[n] = matrix[t];
            }
        }
    //     // return;
    //     // matrix_render2();
    //     // render();
        ws2811_render(&ledstring);
        delay(speed);
    }
}

void renderScrollingHighlight(const String &text, int lowerColor, int upperColor, int speed, FontType font) {
    auto len = dryWrite(text, font);
    int xoff = 0;
    if (len > PIXEL_COLUMNS) {
        font = FontType::Old;
    } else {
        auto dif = PIXEL_COLUMNS - len;
	    xoff = fastFloor(dif / 2);
        // fprintf(stderr, "PIXEL_COLUMNS(%d) - len(%d)=%d, floor(/ 2) = %d\n", PIXEL_COLUMNS, len, dif, xoff);
    }

    auto wait_time = speed / text.size();

    for (int i = 0; i < text.size(); i++) {
        flush();
        auto _c = text[i];

        auto x = xoff;
        auto lwlen = 0;
        for (int j = 0; j < text.size(); j++) {
            auto c = text[j];
            lwlen = drawChar(x, 0, c, i >= j ? upperColor : lowerColor, font);
            x += lwlen + 1;
        }

        render();
        delay(wait_time);
    }

    return;
}

void renderLoopText(String &text, int textLen, long rgba, int speed, int startingIndex) {
    auto ti = startingIndex;
    
    auto running = true;

    while (running) {
        flush();

        write(text, rgba, ti--);

        // TODO: not use black magic
        auto fw = textLen * 5;
        if ((ti <= -fw)) {
        // if (ti < -60) {
            running = false;
        }

        render();
        delay(speed);
    }
}

void renderScrolling(const String &text, int textLen, long rgba, int until, int speed, int startingIndex, FontType font) {
    auto ti = startingIndex;
    
    auto running = true;

    while (running) {
        flush();

        write(text, rgba, ti--, 0, font);

        // write(CurrentTimeMS() & 0xFFFFFF, 0x20);

        // write(textRenderLen, 0x20);

        // TODO: not use black magic
        // auto fw = textLen * 5;
        // Serial.println(ti);
        // Serial.println(PIXEL_COLUMNS - until);
        if (ti <= (PIXEL_COLUMNS - until)) {
        // if (ti < -60) {
            running = false;
        }

        render();
        delay(speed);
    }
    delay(1050);
}

void writeScrollable(const String &text, long color, int speed, FontType font) {
    flush();
    auto w = write(text, color, font);
    // flush();
    // write(w, color);
    // render();
    // delay(1000);
    // return;
    if (w > PIXEL_COLUMNS) {
        return renderScrolling(text, text.length(), color, w, speed, 0, font);
    } else {
        render();
    }
}

void writeFlashing(const String &text, long color, int speed, int startingIndex) {
    // auto s = text.split(' ');
    auto ti = startingIndex;
    auto tempTime = 0;

    int pos = 0;
    String s;

    while (splitString(' ', text, pos, s)) {
        flush();
		// Serial.println(s);
        auto len = write(s, color);

        if (len > PIXEL_COLUMNS) {
            flush();
            write(s, color, FontType::Old);
            // render();
            // delay(400);
            // renderScrolling(s, s.length(), color, len, 100);
        }

        render();
        if (len < 30)
            delay(speed);
        else
            delay(speed + 300);
    }
    // flush();
    // render();

    auto timer = nullptr;
}

void writeFlashingTimed(const String &text, long color, int completeWithinMS, int startingIndex) {
    // auto s = text.split(' ');
    auto ti = startingIndex;
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
        flush();
		// Serial.println(s);

//
        // renderScrollingHighlight(s, 0x20, 0x2000F0, speed);
        renderScrollingHighlight(s, 0x20, color, speed);
        continue;
//

        auto len = write(s, color);

        if (len > PIXEL_COLUMNS) {
            flush();
            write(s, color, FontType::Old);
            // render();
            // delay(400);
            // renderScrolling(s, s.length(), color, len, 100);
        }

        render();
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
    auto sleep_time = time / WIDTH;
    printf("Sleep time:%d\n",sleep_time);
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            draw(x, y, 0);
        }

        render();
        delay(sleep_time);
    }
}

// custom

void run_weather() {
	flush();
	write("   79` F", 0xFF071585);
	// write("NOW", 0xff0000, 16);
	render();
	delay(2000);

	//  write("partly cloudy with rain expected", 0xC7158500);
	////  write("NOW", 0xff0000, 16);
	//  render();
	//  delay(2000);

	flush();
	write("81`", 0x2000);
	write("1 HR", 0x2000, 16);
	render();
	delay(2000);

	flush();
	write("79`", 0x2000);
	write("2 HR", 0x2000, 16);
	render();
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
	flush();
	for (int i = 0; i < 32; i++) {
		draw(randr(0, 31), randr(0, 7), /*0xFF00*/ 0xf0);
		//      flush();
		//      draw(i, 0xf0);
		//      render();
		//      delay(200);
	}

	delay(150);

	render();
}

void run_disco2() {
	for (int i = 0; i < 255; i++) {
		//    draw(randr(0,31), randr(0, 7),  /*0xFF00*/0xf0);
		flush();
		draw(i, 0xf0);
		render();
		delay(200);
	}
}

int logo_id = 0;
int logo_flyin = -10;
int logo_loops = 10;

String texts[] = {"good morning!", "have a nice day", "spacex is going to MARS", "  BIDEN 2020", "   hello!", ""};

void run_text() {
	flush();
	//  write("partly cloudy w rain later", 0xff00, logo_loops--);
	//  write("police stand back 300 feet", 0xff00, logo_loops--);

	//    write("1141 underhill ave", 0xff00, logo_loops--);

	write(texts[logo_id], 0x2000, logo_loops--, logo_flyin);
	if ((logo_flyin + 1) != 1)
	{
		logo_flyin++;
	}

	//  write("the train approaching the station is not in service", 0xff0000, logo_loops--);

	// drawBottomScroller();

	render();
	delay(100);

	if (logo_loops < -120)
	{
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

