#pragma once

#define PROGMEM

struct XY {
  char y;
  char x;
};

void getChar(char c, const XY *&ptr, int &len, int fontflag = 0);