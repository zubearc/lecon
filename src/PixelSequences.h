#ifndef PIXELSEQUENCES_H
#define PIXELSEQUENCES_H

#include <stdlib.h>
#include <string>
#include "Values.h"
#include "Render.h"
#include "Util.h"

#define delay SleepMS

void renderLoopText(String &text, int textLen, long rgba, int speed = 100, int startingIndex = 10);

void renderScrolling(const String &text, int textLen, long rgba, int until, int speed = 100, int startingIndex = 0);

void writeScrollable(const String &text, long color, int speed = 200);

void writeFlashing(String &text, long color, int speed = 900, int startingIndex = 0);

void writeFlashingTimed(String &text, long color, int completeWithinMS, int startingIndex = 0);

void run_weather();

void run_disco();

void run_disco2();

void run_text();

#include "PixelSequenceText.h"

#endif