#ifndef PIXELSEQUENCES_H
#define PIXELSEQUENCES_H

#include <stdlib.h>
#include <string>
#include "Values.h"
#include "Render2.h"
#include "PixelFonts2.h"
#include "Util.h"

#define delay SleepMS

void renderVertSlide(bool up, int low, int high, int speed = 100); //LL

void renderVertSlide2(bool up, int speed = 100); //LL

void renderHorizHighlight(int color, int delay, bool reverse = false);

void renderScrollingHighlight(const String &text, int lowerColor, int upperColor, int speed, FontType font = FontType::New, bool allowOverdraw = false);

void renderLoopText(String &text, int textLen, long rgba, int speed = 100, int startingIndex = 10);

void renderScrolling(const String &text, int textLen, long rgba, int until, int speed = 100, int startingIndex = 0, FontType font = FontType::New);

void renderScrolling2(const String &text, int textLen, long rgba, int until, int speed = 100, int startingIndex = 0, FontType font = FontType::New);

void writeScrollable(const String &text, long color, int speed = 200, FontType font = FontType::New);

void writeFlashing(const String &text, long color, int speed = 900, int startingIndex = 0);

void writeFlashingTimed(const String &text, long color, int completeWithinMS, bool allowOverdraw = false);

void displayFlyingArrow(bool rightToLeft, int startX, int endX);

void wipe(int time);

void run_weather();

void run_disco();

void run_disco2();

void run_text();

#include "PixelSequenceText.h"

#endif