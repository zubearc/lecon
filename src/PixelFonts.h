#ifndef PIXREND_H
#define PIXREND_H
#include "Values.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct XY {
  char y;
  char x;
};

const XY char0[13] /* 0 */ PROGMEM = {{1,0},{1,1},{1,2},{3,2},{3,2},{2,2},{4,2},{5,2},{5,1},{5,0},{4,0},{3,0},{2,0}};
const XY char1[7] /* 1 */ PROGMEM = {{2,0},{1,1},{1,2},{2,2},{3,2},{4,2},{5,2}};
const XY char2[10] /* 2 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,2},{3,1},{4,0},{5,0},{5,1},{5,2}};
const XY char3[10] /* 3 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,2},{3,1},{4,2},{5,2},{5,1},{5,0}};
const XY char4[10] /* 4 */ PROGMEM = {{1,0},{2,0},{3,0},{3,1},{3,2},{1,2},{2,2},{3,2},{4,2},{5,2}};
const XY char5[9] /* 5 */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{3,1},{4,2},{5,1},{5,0}};
const XY char6[12] /* 6 */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2},{4,2},{3,2},{3,1}};
const XY char7[7] /* 7 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,1},{4,1},{5,1}};
const XY char8[13] /* 8 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,2},{3,1},{3,0},{2,0},{4,0},{5,0},{5,1},{5,2},{4,2}};
const XY char9[12] /* 9 */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{3,1},{3,2},{2,2},{4,2},{5,2},{5,1},{5,0}};
const XY char10[14] /* A */ PROGMEM = {{5,0},{3,0},{3,0},{4,0},{2,0},{1,1},{1,2},{2,3},{3,3},{3,3},{4,3},{5,3},{3,1},{3,2}};
const XY char11[14] /* B */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{1,1},{1,2},{2,3},{3,3},{3,2},{3,1},{5,1},{5,2},{4,3}};
const XY char12[9] /* C */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2}};
const XY char13[13] /* D */ PROGMEM = {{1,0},{2,0},{3,0},{3,0},{4,0},{5,0},{1,1},{1,2},{5,1},{5,2},{2,3},{3,3},{4,3}};
const XY char14[10] /* E */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2},{3,1}};
const XY char15[9] /* F */ PROGMEM = {{1,0},{1,1},{1,2},{2,0},{3,0},{4,0},{5,0},{3,1},{3,2}};
const XY char16[16] /* G */ PROGMEM = {{1,2},{1,1},{1,0},{3,0},{3,0},{3,0},{2,0},{4,0},{5,0},{5,1},{5,2},{5,3},{4,3},{3,3},{3,2},{1,3}};
const XY char17[12] /* H */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{3,1},{3,2},{1,2},{2,2},{3,2},{4,2},{5,2}};
const XY char18[10] /* I */ PROGMEM = {{1,0},{1,1},{1,2},{2,1},{3,1},{4,1},{4,1},{5,1},{5,0},{5,2}};
const XY char19[10] /* J */ PROGMEM = {{1,0},{1,1},{1,2},{1,3},{2,2},{3,2},{4,2},{5,1},{5,0},{5,2}};
const XY char20[10] /* K */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{3,1},{4,2},{5,3},{2,2},{1,3}};
const XY char21[8] /* L */ PROGMEM = {{1,0},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2}};
const XY char22[13] /* M */ PROGMEM = {{5,0},{4,0},{3,0},{2,0},{1,0},{2,1},{3,2},{2,3},{1,4},{2,4},{4,4},{3,4},{5,4}};
const XY char23[12] /* N */ PROGMEM = {{5,0},{4,0},{3,0},{2,0},{1,0},{2,1},{3,2},{1,3},{2,3},{3,3},{4,3},{5,3}};
const XY char24[15] /* O */ PROGMEM = {{1,0},{2,0},{2,0},{4,0},{5,0},{5,1},{5,2},{3,0},{1,1},{1,2},{1,3},{2,3},{3,3},{4,3},{5,3}};
const XY char25[10] /* P */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{1,1},{1,2},{2,2},{3,2},{3,1}};
const XY char26[13] /* Q */ PROGMEM = {{5,3},{4,2},{3,3},{2,3},{5,0},{5,1},{4,0},{3,0},{2,0},{1,0},{1,1},{1,2},{1,3}};
const XY char27[16] /* R */ PROGMEM = {{1,0},{2,0},{3,0},{3,0},{4,0},{5,0},{1,1},{1,2},{1,2},{1,3},{2,3},{3,3},{3,2},{3,1},{4,2},{5,3}};
const XY char28[15] /* S */ PROGMEM = {{1,3},{1,2},{1,1},{1,0},{2,0},{3,0},{3,2},{3,2},{3,1},{3,3},{5,3},{4,3},{5,2},{5,0},{5,1}};
const XY char29[7] /* T */ PROGMEM = {{1,0},{1,1},{1,2},{2,1},{3,1},{4,1},{5,1}};
const XY char30[10] /* U */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,1},{5,2},{4,3},{3,3},{2,3},{1,3}};
const XY char31[9] /* V */ PROGMEM = {{1,0},{2,0},{3,0},{4,1},{5,2},{4,3},{3,4},{2,4},{1,4}};
const XY char32[16] /* W */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,1},{4,2},{3,2},{3,2},{2,2},{2,2},{1,2},{5,3},{4,4},{3,4},{2,4},{1,4}};
const XY char33[9] /* X */ PROGMEM = {{1,0},{2,1},{3,2},{4,3},{5,4},{5,0},{4,1},{2,3},{1,4}};
const XY char34[7] /* Y */ PROGMEM = {{1,0},{2,1},{3,2},{2,3},{1,4},{4,2},{5,2}};
const XY char35[9] /* Z */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,1},{4,0},{5,0},{5,1},{5,2}};
const XY char36[4] /* ` */ PROGMEM = {{1,0},{0,1},{1,2},{2,1}};
const XY char37[5] /* ! */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{5,0}};
const XY char38[14] /* a */ PROGMEM = {{6,1},{6,2},{6,3},{6,4},{5,4},{4,4},{3,4},{2,3},{2,2},{2,1},{4,3},{4,2},{4,1},{5,0}};
const XY char39[16] /* b */ PROGMEM = {{6,0},{6,1},{6,2},{6,3},{5,4},{4,4},{3,4},{2,3},{2,2},{3,1},{5,0},{4,0},{3,0},{2,0},{1,0},{0,0}};
const XY char40[11] /* c */ PROGMEM = {{6,1},{6,2},{6,3},{5,4},{5,0},{4,0},{3,0},{2,1},{2,2},{2,2},{2,3}};
const XY char41[16] /* d */ PROGMEM = {{6,1},{6,2},{6,3},{6,4},{5,4},{3,4},{4,4},{1,4},{2,4},{0,4},{4,0},{5,0},{3,0},{2,1},{2,2},{3,3}};
const XY char42[14] /* e */ PROGMEM = {{6,1},{6,2},{6,3},{5,0},{4,0},{3,0},{2,1},{2,2},{2,3},{3,4},{4,4},{4,3},{4,2},{4,1}};
const XY char43[11] /* f */ PROGMEM = {{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,2},{0,3},{1,4},{3,2},{3,0}};
const XY char44[14] /* g */ PROGMEM = {{6,1},{6,2},{6,3},{5,4},{4,4},{3,4},{2,4},{2,2},{2,3},{2,1},{3,0},{4,1},{4,2},{4,3}};
const XY char45[13] /* h */ PROGMEM = {{6,0},{5,0},{4,0},{3,0},{2,0},{0,0},{1,0},{4,1},{3,2},{3,3},{4,4},{5,4},{6,4}};
const XY char46[7] /* i */ PROGMEM = {{5,0},{6,0},{3,0},{3,0},{2,0},{4,0},{0,0}};
const XY char47[8] /* j */ PROGMEM = {{5,0},{6,1},{6,2},{5,3},{4,3},{3,3},{2,3},{0,3}};
const XY char48[13] /* k */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{4,0},{4,0},{5,0},{6,0},{4,1},{5,2},{6,3},{3,2},{2,3}};
const XY char49[9] /* l */ PROGMEM = {{1,0},{1,1},{2,1},{3,1},{5,1},{4,1},{6,1},{6,0},{6,2}};
const XY char50[15] /* m */ PROGMEM = {{6,0},{5,0},{4,0},{3,0},{2,0},{2,1},{3,2},{4,2},{5,2},{6,2},{2,3},{3,4},{4,4},{5,4},{6,4}};
const XY char51[12] /* n */ PROGMEM = {{6,0},{5,0},{3,0},{4,0},{2,0},{3,1},{2,2},{2,3},{3,4},{4,4},{5,4},{6,4}};
const XY char52[12] /* o */ PROGMEM = {{3,0},{4,0},{5,0},{6,1},{6,2},{6,3},{5,4},{4,4},{3,4},{2,1},{2,2},{2,3}};
const XY char53[12] /* p */ PROGMEM = {{6,0},{5,0},{4,0},{4,1},{4,2},{4,3},{3,4},{2,3},{2,1},{2,2},{2,0},{3,0}};
const XY char54[17] /* q */ PROGMEM = {{6,4},{6,4},{5,4},{4,4},{3,4},{6,4},{5,4},{4,4},{3,4},{2,4},{3,3},{4,3},{4,2},{4,1},{3,0},{2,1},{2,2}};
const XY char55[10] /* r */ PROGMEM = {{6,0},{5,0},{4,0},{4,0},{3,0},{2,0},{3,1},{2,2},{2,3},{3,4}};
const XY char56[12] /* s */ PROGMEM = {{6,0},{6,1},{6,2},{6,3},{5,4},{4,3},{4,1},{4,2},{3,0},{2,1},{2,2},{2,3}};
const XY char57[11] /* t */ PROGMEM = {{6,2},{6,3},{5,4},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1},{2,0},{2,2}};
const XY char58[13] /* u */ PROGMEM = {{6,1},{6,2},{5,3},{5,4},{6,4},{3,4},{4,4},{2,4},{5,0},{4,0},{4,0},{3,0},{2,0}};
const XY char59[9] /* v */ PROGMEM = {{2,0},{3,0},{4,0},{5,1},{6,2},{5,3},{4,4},{3,4},{2,4}};
const XY char60[12] /* w */ PROGMEM = {{2,0},{3,0},{4,0},{5,0},{6,1},{5,2},{4,2},{6,3},{5,4},{4,4},{3,4},{2,4}};
const XY char61[9] /* x */ PROGMEM = {{2,0},{3,1},{4,2},{5,3},{6,4},{5,1},{6,0},{3,3},{2,4}};
const XY char62[12] /* y */ PROGMEM = {{2,0},{3,0},{4,1},{4,2},{4,3},{3,4},{2,4},{4,4},{5,4},{6,3},{6,2},{6,1}};
const XY char63[14] /* z */ PROGMEM = {{6,0},{6,1},{6,2},{6,3},{6,4},{5,1},{4,2},{3,3},{2,4},{2,3},{2,2},{2,0},{2,1},{2,1}};

const XY char99[1] /* . */ PROGMEM = {{5,0}};

inline void getChar(char c, const XY *&ptr, int &len) {
switch (c) {
case '0':
        ptr = (XY *)&char0;
        len = 13;
        break;
case '1':
        ptr = (XY *)&char1;
        len = 7;
        break;
case '2':
        ptr = (XY *)&char2;
        len = 10;
        break;
case '3':
        ptr = (XY *)&char3;
        len = 10;
        break;
case '4':
        ptr = (XY *)&char4;
        len = 10;
        break;
case '5':
        ptr = (XY *)&char5;
        len = 9;
        break;
case '6':
        ptr = (XY *)&char6;
        len = 12;
        break;
case '7':
        ptr = (XY *)&char7;
        len = 7;
        break;
case '8':
        ptr = (XY *)&char8;
        len = 13;
        break;
case '9':
        ptr = (XY *)&char9;
        len = 12;
        break;
case 'A':
        ptr = (XY *)&char10;
        len = 14;
        break;
case 'B':
        ptr = (XY *)&char11;
        len = 14;
        break;
case 'C':
        ptr = (XY *)&char12;
        len = 9;
        break;
case 'D':
        ptr = (XY *)&char13;
        len = 13;
        break;
case 'E':
        ptr = (XY *)&char14;
        len = 10;
        break;
case 'F':
        ptr = (XY *)&char15;
        len = 9;
        break;
case 'G':
        ptr = (XY *)&char16;
        len = 16;
        break;
case 'H':
        ptr = (XY *)&char17;
        len = 12;
        break;
case 'I':
        ptr = (XY *)&char18;
        len = 10;
        break;
case 'J':
        ptr = (XY *)&char19;
        len = 10;
        break;
case 'K':
        ptr = (XY *)&char20;
        len = 10;
        break;
case 'L':
        ptr = (XY *)&char21;
        len = 8;
        break;
case 'M':
        ptr = (XY *)&char22;
        len = 13;
        break;
case 'N':
        ptr = (XY *)&char23;
        len = 12;
        break;
case 'O':
        ptr = (XY *)&char24;
        len = 15;
        break;
case 'P':
        ptr = (XY *)&char25;
        len = 10;
        break;
case 'Q':
        ptr = (XY *)&char26;
        len = 13;
        break;
case 'R':
        ptr = (XY *)&char27;
        len = 16;
        break;
case 'S':
        ptr = (XY *)&char28;
        len = 15;
        break;
case 'T':
        ptr = (XY *)&char29;
        len = 7;
        break;
case 'U':
        ptr = (XY *)&char30;
        len = 10;
        break;
case 'V':
        ptr = (XY *)&char31;
        len = 9;
        break;
case 'W':
        ptr = (XY *)&char32;
        len = 16;
        break;
case 'X':
        ptr = (XY *)&char33;
        len = 9;
        break;
case 'Y':
        ptr = (XY *)&char34;
        len = 7;
        break;
case 'Z':
        ptr = (XY *)&char35;
        len = 9;
        break;
case '`':
        ptr = (XY *)&char36;
        len = 4;
        break;
case '!':
        ptr = (XY *)&char37;
        len = 5;
        break;
case 'a':
        ptr = (XY *)&char38;
        len = 14;
        break;
case 'b':
        ptr = (XY *)&char39;
        len = 16;
        break;
case 'c':
        ptr = (XY *)&char40;
        len = 11;
        break;
case 'd':
        ptr = (XY *)&char41;
        len = 16;
        break;
case 'e':
        ptr = (XY *)&char42;
        len = 14;
        break;
case 'f':
        ptr = (XY *)&char43;
        len = 11;
        break;
case 'g':
        ptr = (XY *)&char44;
        len = 14;
        break;
case 'h':
        ptr = (XY *)&char45;
        len = 13;
        break;
case 'i':
        ptr = (XY *)&char46;
        len = 7;
        break;
case 'j':
        ptr = (XY *)&char47;
        len = 8;
        break;
case 'k':
        ptr = (XY *)&char48;
        len = 13;
        break;
case 'l':
        ptr = (XY *)&char49;
        len = 9;
        break;
case 'm':
        ptr = (XY *)&char50;
        len = 15;
        break;
case 'n':
        ptr = (XY *)&char51;
        len = 12;
        break;
case 'o':
        ptr = (XY *)&char52;
        len = 12;
        break;
case 'p':
        ptr = (XY *)&char53;
        len = 12;
        break;
case 'q':
        ptr = (XY *)&char54;
        len = 17;
        break;
case 'r':
        ptr = (XY *)&char55;
        len = 10;
        break;
case 's':
        ptr = (XY *)&char56;
        len = 12;
        break;
case 't':
        ptr = (XY *)&char57;
        len = 11;
        break;
case 'u':
        ptr = (XY *)&char58;
        len = 13;
        break;
case 'v':
        ptr = (XY *)&char59;
        len = 9;
        break;
case 'w':
        ptr = (XY *)&char60;
        len = 12;
        break;
case 'x':
        ptr = (XY *)&char61;
        len = 9;
        break;
case 'y':
        ptr = (XY *)&char62;
        len = 12;
        break;
case 'z':
        ptr = (XY *)&char63;
        len = 14;
        break;
case '.':
        ptr = (XY *)&char99;
        len = 1;
        break;
};

}

#endif  
