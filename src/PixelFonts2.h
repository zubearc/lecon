#pragma once

#include <cctype>
#define PROGMEM

struct XY {
  char y;
  char x;
};

#pragma region Fonts
const XY ft1_char0[13] /* 0 */ PROGMEM = {{1,0},{1,1},{1,2},{3,2},{3,2},{2,2},{4,2},{5,2},{5,1},{5,0},{4,0},{3,0},{2,0}};
const XY ft1_char1[7] /* 1 */ PROGMEM = {{2,0},{1,1},{1,2},{2,2},{3,2},{4,2},{5,2}};
const XY ft1_char2[10] /* 2 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,2},{3,1},{4,0},{5,0},{5,1},{5,2}};
const XY ft1_char3[10] /* 3 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,2},{3,1},{4,2},{5,2},{5,1},{5,0}};
const XY ft1_char4[10] /* 4 */ PROGMEM = {{1,0},{2,0},{3,0},{3,1},{3,2},{1,2},{2,2},{3,2},{4,2},{5,2}};
const XY ft1_char5[9] /* 5 */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{3,1},{4,2},{5,1},{5,0}};
const XY ft1_char6[12] /* 6 */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2},{4,2},{3,2},{3,1}};
const XY ft1_char7[7] /* 7 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,1},{4,1},{5,1}};
const XY ft1_char8[13] /* 8 */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,2},{3,1},{3,0},{2,0},{4,0},{5,0},{5,1},{5,2},{4,2}};
const XY ft1_char9[12] /* 9 */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{3,1},{3,2},{2,2},{4,2},{5,2},{5,1},{5,0}};
const XY ft1_char10[14] /* A */ PROGMEM = {{5,0},{3,0},{3,0},{4,0},{2,0},{1,1},{1,2},{2,3},{3,3},{3,3},{4,3},{5,3},{3,1},{3,2}};
const XY ft1_char11[14] /* B */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{1,1},{1,2},{2,3},{3,3},{3,2},{3,1},{5,1},{5,2},{4,3}};
const XY ft1_char12[9] /* C */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2}};
const XY ft1_char13[13] /* D */ PROGMEM = {{1,0},{2,0},{3,0},{3,0},{4,0},{5,0},{1,1},{1,2},{5,1},{5,2},{2,3},{3,3},{4,3}};
const XY ft1_char14[10] /* E */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2},{3,1}};
const XY ft1_char15[9] /* F */ PROGMEM = {{1,0},{1,1},{1,2},{2,0},{3,0},{4,0},{5,0},{3,1},{3,2}};
const XY ft1_char16[16] /* G */ PROGMEM = {{1,2},{1,1},{1,0},{3,0},{3,0},{3,0},{2,0},{4,0},{5,0},{5,1},{5,2},{5,3},{4,3},{3,3},{3,2},{1,3}};
const XY ft1_char17[12] /* H */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{3,1},{3,2},{1,2},{2,2},{3,2},{4,2},{5,2}};
const XY ft1_char18[10] /* I */ PROGMEM = {{1,0},{1,1},{1,2},{2,1},{3,1},{4,1},{4,1},{5,1},{5,0},{5,2}};
const XY ft1_char19[10] /* J */ PROGMEM = {{1,0},{1,1},{1,2},{1,3},{2,2},{3,2},{4,2},{5,1},{5,0},{5,2}};
const XY ft1_char20[10] /* K */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{3,1},{4,2},{5,3},{2,2},{1,3}};
const XY ft1_char21[8] /* L */ PROGMEM = {{1,0},{1,0},{2,0},{3,0},{4,0},{5,0},{5,1},{5,2}};
const XY ft1_char22[13] /* M */ PROGMEM = {{5,0},{4,0},{3,0},{2,0},{1,0},{2,1},{3,2},{2,3},{1,4},{2,4},{4,4},{3,4},{5,4}};
const XY ft1_char23[12] /* N */ PROGMEM = {{5,0},{4,0},{3,0},{2,0},{1,0},{2,1},{3,2},{1,3},{2,3},{3,3},{4,3},{5,3}};
const XY ft1_char24[15] /* O */ PROGMEM = {{1,0},{2,0},{2,0},{4,0},{5,0},{5,1},{5,2},{3,0},{1,1},{1,2},{1,3},{2,3},{3,3},{4,3},{5,3}};
const XY ft1_char25[10] /* P */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{1,1},{1,2},{2,2},{3,2},{3,1}};
const XY ft1_char26[13] /* Q */ PROGMEM = {{5,3},{4,2},{3,3},{2,3},{5,0},{5,1},{4,0},{3,0},{2,0},{1,0},{1,1},{1,2},{1,3}};
const XY ft1_char27[16] /* R */ PROGMEM = {{1,0},{2,0},{3,0},{3,0},{4,0},{5,0},{1,1},{1,2},{1,2},{1,3},{2,3},{3,3},{3,2},{3,1},{4,2},{5,3}};
const XY ft1_char28[11] /* S */ PROGMEM = {{1,2},{1,1},{1,0},{2,0},{3,0},{3,1},{3,2},{4,2},{5,2},{5,1},{5,0}};
const XY ft1_char29[7] /* T */ PROGMEM = {{1,0},{1,1},{1,2},{2,1},{3,1},{4,1},{5,1}};
const XY ft1_char30[10] /* U */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,1},{5,2},{4,3},{3,3},{2,3},{1,3}};
const XY ft1_char31[9] /* V */ PROGMEM = {{1,0},{2,0},{3,0},{4,1},{5,2},{4,3},{3,4},{2,4},{1,4}};
const XY ft1_char32[16] /* W */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,1},{4,2},{3,2},{3,2},{2,2},{2,2},{1,2},{5,3},{4,4},{3,4},{2,4},{1,4}};
const XY ft1_char33[9] /* X */ PROGMEM = {{1,0},{2,1},{3,2},{4,3},{5,4},{5,0},{4,1},{2,3},{1,4}};
const XY ft1_char34[7] /* Y */ PROGMEM = {{1,0},{2,1},{3,2},{2,3},{1,4},{4,2},{5,2}};
const XY ft1_char35[9] /* Z */ PROGMEM = {{1,0},{1,1},{1,2},{2,2},{3,1},{4,0},{5,0},{5,1},{5,2}};
const XY ft1_char36[4] /* ° */ PROGMEM = {{1,0},{0,1},{1,2},{2,1}};
const XY ft1_char37[5] /* ! */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{5,0}};
const XY ft1_char38[2] /* ' */ PROGMEM = {{0,0},{1,0}};
const XY ft1_char39[9] /* ? */ PROGMEM = {{0,0},{0,1},{0,2},{1,2},{2,2},{3,2},{3,1},{4,1},{6,1}};
const XY ft1_char40[10] /* .130 */ PROGMEM = {{0,2},{1,1},{2,0},{1,2},{2,2},{3,2},{4,2},{5,2},{1,3},{2,4}};
const XY ft1_char41[10] /* .131 */ PROGMEM = {{0,2},{1,2},{2,2},{3,2},{4,2},{5,2},{4,1},{3,0},{4,3},{3,4}};
const XY ft1_char42[14] /* % */ PROGMEM = {{0,0},{1,0},{1,1},{0,1},{5,0},{4,1},{3,2},{2,3},{1,4},{0,5},{5,4},{5,5},{4,5},{4,4}};
const XY ft1_char43[5] /* + */ PROGMEM = {{3,0},{3,1},{2,1},{3,2},{4,1}};
const XY ft1_char44[3] /* - */ PROGMEM = {{3,0},{3,1},{3,2}};
const XY ft1_char45[14] /* a */ PROGMEM = {{6,1},{6,2},{6,3},{6,4},{5,4},{4,4},{3,4},{2,3},{2,2},{2,1},{4,3},{4,2},{4,1},{5,0}};
const XY ft1_char46[16] /* b */ PROGMEM = {{6,0},{6,1},{6,2},{6,3},{5,4},{4,4},{3,4},{2,3},{2,2},{3,1},{5,0},{4,0},{3,0},{2,0},{1,0},{0,0}};
const XY ft1_char47[11] /* c */ PROGMEM = {{6,1},{6,2},{6,3},{5,4},{5,0},{4,0},{3,0},{2,1},{2,2},{2,2},{2,3}};
const XY ft1_char48[16] /* d */ PROGMEM = {{6,1},{6,2},{6,3},{6,4},{5,4},{3,4},{4,4},{1,4},{2,4},{0,4},{4,0},{5,0},{3,0},{2,1},{2,2},{3,3}};
const XY ft1_char49[14] /* e */ PROGMEM = {{6,1},{6,2},{6,3},{5,0},{4,0},{3,0},{2,1},{2,2},{2,3},{3,4},{4,4},{4,3},{4,2},{4,1}};
const XY ft1_char50[11] /* f */ PROGMEM = {{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,2},{0,3},{1,4},{3,2},{3,0}};
const XY ft1_char51[14] /* g */ PROGMEM = {{6,1},{6,2},{6,3},{5,4},{4,4},{3,4},{2,4},{2,2},{2,3},{2,1},{3,0},{4,1},{4,2},{4,3}};
const XY ft1_char52[13] /* h */ PROGMEM = {{6,0},{5,0},{4,0},{3,0},{2,0},{0,0},{1,0},{4,1},{3,2},{3,3},{4,4},{5,4},{6,4}};
const XY ft1_char53[7] /* i */ PROGMEM = {{5,0},{6,0},{3,0},{3,0},{2,0},{4,0},{0,0}};
const XY ft1_char54[8] /* j */ PROGMEM = {{5,0},{6,1},{6,2},{5,3},{4,3},{3,3},{2,3},{0,3}};
const XY ft1_char55[13] /* k */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{4,0},{4,0},{5,0},{6,0},{4,1},{5,2},{6,3},{3,2},{2,3}};
const XY ft1_char56[9] /* l */ PROGMEM = {{1,0},{1,1},{2,1},{3,1},{5,1},{4,1},{6,1},{6,0},{6,2}};
const XY ft1_char57[15] /* m */ PROGMEM = {{6,0},{5,0},{4,0},{3,0},{2,0},{2,1},{3,2},{4,2},{5,2},{6,2},{2,3},{3,4},{4,4},{5,4},{6,4}};
const XY ft1_char58[12] /* n */ PROGMEM = {{6,0},{5,0},{3,0},{4,0},{2,0},{3,1},{2,2},{2,3},{3,4},{4,4},{5,4},{6,4}};
const XY ft1_char59[12] /* o */ PROGMEM = {{3,0},{4,0},{5,0},{6,1},{6,2},{6,3},{5,4},{4,4},{3,4},{2,1},{2,2},{2,3}};
const XY ft1_char60[12] /* p */ PROGMEM = {{6,0},{5,0},{4,0},{4,1},{4,2},{4,3},{3,4},{2,3},{2,1},{2,2},{2,0},{3,0}};
const XY ft1_char61[17] /* q */ PROGMEM = {{6,4},{6,4},{5,4},{4,4},{3,4},{6,4},{5,4},{4,4},{3,4},{2,4},{3,3},{4,3},{4,2},{4,1},{3,0},{2,1},{2,2}};
const XY ft1_char62[10] /* r */ PROGMEM = {{6,0},{5,0},{4,0},{4,0},{3,0},{2,0},{3,1},{2,2},{2,3},{3,4}};
const XY ft1_char63[12] /* s */ PROGMEM = {{6,0},{6,1},{6,2},{6,3},{5,4},{4,3},{4,1},{4,2},{3,0},{2,1},{2,2},{2,3}};
const XY ft1_char64[11] /* t */ PROGMEM = {{6,2},{6,3},{5,4},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1},{2,0},{2,2}};
const XY ft1_char65[13] /* u */ PROGMEM = {{6,1},{6,2},{5,3},{5,4},{6,4},{3,4},{4,4},{2,4},{5,0},{4,0},{4,0},{3,0},{2,0}};
const XY ft1_char66[9] /* v */ PROGMEM = {{2,0},{3,0},{4,0},{5,1},{6,2},{5,3},{4,4},{3,4},{2,4}};
const XY ft1_char67[12] /* w */ PROGMEM = {{2,0},{3,0},{4,0},{5,0},{6,1},{5,2},{4,2},{6,3},{5,4},{4,4},{3,4},{2,4}};
const XY ft1_char68[9] /* x */ PROGMEM = {{2,0},{3,1},{4,2},{5,3},{6,4},{5,1},{6,0},{3,3},{2,4}};
const XY ft1_char69[12] /* y */ PROGMEM = {{2,0},{3,0},{4,1},{4,2},{4,3},{3,4},{2,4},{4,4},{5,4},{6,3},{6,2},{6,1}};
const XY ft1_char70[14] /* z */ PROGMEM = {{6,0},{6,1},{6,2},{6,3},{6,4},{5,1},{4,2},{3,3},{2,4},{2,3},{2,2},{2,0},{2,1},{2,1}};
const XY ft1_char71[1] /* . */ PROGMEM = {{5,0}};
const XY ft2_char0[18] /* A */ PROGMEM = {{6,0},{4,0},{5,0},{3,0},{2,0},{1,0},{0,1},{0,2},{0,3},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{3,3},{3,2},{3,1}};
const XY ft2_char1[20] /* B */ PROGMEM = {{0,0},{2,0},{3,0},{1,0},{4,0},{5,0},{6,0},{6,1},{6,2},{6,3},{5,4},{4,4},{3,3},{3,2},{3,1},{2,4},{1,4},{0,3},{0,2},{0,1}};
const XY ft2_char2[11] /* C */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,2},{6,1},{0,1},{0,2},{6,3},{0,3}};
const XY ft2_char3[16] /* D */ PROGMEM = {{0,0},{2,0},{3,0},{6,0},{4,0},{5,0},{1,0},{0,1},{0,2},{2,3},{1,3},{3,3},{4,3},{5,3},{6,2},{6,1}};
const XY ft2_char4[15] /* E */ PROGMEM = {{0,0},{0,1},{0,2},{0,3},{1,0},{3,0},{4,0},{2,0},{5,0},{6,0},{6,1},{6,2},{6,3},{3,1},{3,2}};
const XY ft2_char5[12] /* F */ PROGMEM = {{6,0},{5,0},{4,0},{0,0},{2,0},{3,0},{1,0},{0,1},{0,2},{0,3},{3,1},{3,2}};
const XY ft2_char6[17] /* G */ PROGMEM = {{0,1},{0,2},{1,0},{3,0},{2,0},{4,0},{5,0},{6,1},{6,2},{0,3},{6,3},{5,4},{4,4},{3,4},{3,3},{3,2},{1,4}};
const XY ft2_char7[16] /* H */ PROGMEM = {{1,0},{2,0},{0,0},{4,0},{3,0},{5,0},{6,0},{3,1},{3,2},{3,3},{2,3},{0,3},{1,3},{4,3},{5,3},{6,3}};
const XY ft2_char8[11] /* I */ PROGMEM = {{0,0},{0,1},{0,2},{1,1},{2,1},{3,1},{4,1},{5,1},{6,0},{6,1},{6,2}};
const XY ft2_char9[9] /* J */ PROGMEM = {{0,3},{6,1},{5,0},{6,2},{5,3},{4,3},{3,3},{2,3},{1,3}};
const XY ft2_char10[14] /* K */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{3,1},{4,2},{5,3},{6,4},{2,2},{1,3},{0,4}};
const XY ft2_char11[9] /* L */ PROGMEM = {{0,0},{2,0},{1,0},{3,0},{4,0},{5,0},{6,0},{6,1},{6,2}};
const XY ft2_char12[18] /* M */ PROGMEM = {{6,0},{5,0},{3,0},{4,0},{1,0},{2,0},{0,0},{2,2},{1,1},{3,2},{1,3},{0,4},{1,4},{2,4},{3,4},{5,4},{6,4},{4,4}};
const XY ft2_char13[17] /* N */ PROGMEM = {{6,0},{5,0},{4,0},{2,0},{1,0},{3,0},{0,0},{0,4},{1,4},{2,4},{3,4},{4,4},{6,4},{5,4},{4,3},{3,2},{2,1}};
const XY ft2_char14[14] /* O */ PROGMEM = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,1},{6,2},{5,3},{4,3},{2,3},{1,3},{3,3},{0,1},{0,2}};
const XY ft2_char15[13] /* P */ PROGMEM = {{6,0},{5,0},{2,0},{4,0},{3,0},{1,0},{0,0},{0,1},{0,2},{1,3},{2,3},{3,1},{3,2}};
const XY ft2_char16[17] /* Q */ PROGMEM = {{2,0},{1,0},{0,1},{0,2},{3,0},{4,0},{5,0},{6,1},{6,2},{4,2},{5,3},{0,3},{1,4},{2,4},{3,4},{4,4},{6,4}};
const XY ft2_char17[18] /* R */ PROGMEM = {{0,0},{1,0},{4,0},{5,0},{6,0},{2,0},{3,0},{0,1},{0,2},{4,2},{5,3},{0,3},{1,4},{2,4},{3,3},{3,2},{3,1},{6,4}};
const XY ft2_char18[12] /* S */ PROGMEM = {{0,1},{0,2},{1,3},{1,0},{2,0},{3,1},{3,2},{4,3},{5,3},{6,2},{6,1},{5,0}};
const XY ft2_char19[11] /* T */ PROGMEM = {{0,0},{0,2},{0,1},{0,3},{0,4},{1,2},{2,2},{4,2},{5,2},{3,2},{6,2}};
const XY ft2_char20[14] /* U */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,1},{6,2},{5,3},{4,3},{3,3},{2,3},{1,3},{0,3}};
const XY ft2_char21[13] /* V */ PROGMEM = {{0,0},{1,0},{4,0},{2,0},{3,0},{5,1},{6,2},{5,3},{4,4},{3,4},{2,4},{0,4},{1,4}};
const XY ft2_char22[16] /* W */ PROGMEM = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,1},{5,2},{4,2},{6,3},{5,4},{4,4},{3,4},{2,4},{0,4},{1,4}};
const XY ft2_char23[13] /* X */ PROGMEM = {{0,0},{1,0},{2,1},{3,2},{6,0},{5,0},{4,1},{2,3},{4,3},{1,4},{0,4},{5,4},{6,4}};
const XY ft2_char24[11] /* Y */ PROGMEM = {{0,0},{2,0},{1,0},{3,1},{4,2},{3,3},{2,4},{1,4},{0,4},{5,2},{6,2}};
const XY ft2_char25[15] /* Z */ PROGMEM = {{0,0},{0,1},{0,2},{0,3},{0,4},{1,4},{2,3},{3,2},{4,1},{5,0},{6,0},{6,1},{6,2},{6,3},{6,4}};
const XY ft2_char26[14] /* y */ PROGMEM = {{2,0},{3,0},{4,0},{5,1},{5,2},{7,3},{7,2},{7,1},{5,3},{6,4},{5,4},{4,4},{3,4},{2,4}};
const XY ft2_char27[16] /* g */ PROGMEM = {{7,1},{7,2},{7,3},{6,4},{5,4},{4,4},{3,0},{2,1},{2,2},{2,3},{2,4},{3,4},{4,0},{5,1},{5,2},{5,3}};
const XY ft2_char28[11] /* p */ PROGMEM = {{7,0},{6,0},{4,0},{3,0},{5,0},{2,0},{2,1},{2,2},{3,3},{4,2},{4,1}};
const XY ft2_char29[12] /* q */ PROGMEM = {{3,0},{2,1},{4,1},{3,3},{4,3},{5,3},{7,3},{4,2},{2,2},{6,3},{6,4},{2,3}};
const XY ft2_char30[8] /* j */ PROGMEM = {{6,0},{7,1},{7,2},{6,3},{4,3},{3,3},{5,3},{1,3}};
XY* const oldFontTable[255] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char37,nullptr,nullptr,nullptr,(XY*)&ft1_char42,nullptr,(XY*)&ft1_char38,nullptr,nullptr,nullptr,(XY*)&ft1_char43,nullptr,(XY*)&ft1_char44,(XY*)&ft1_char71,nullptr,(XY*)&ft1_char0,(XY*)&ft1_char1,(XY*)&ft1_char2,(XY*)&ft1_char3,(XY*)&ft1_char4,(XY*)&ft1_char5,(XY*)&ft1_char6,(XY*)&ft1_char7,(XY*)&ft1_char8,(XY*)&ft1_char9,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char39,nullptr,(XY*)&ft1_char10,(XY*)&ft1_char11,(XY*)&ft1_char12,(XY*)&ft1_char13,(XY*)&ft1_char14,(XY*)&ft1_char15,(XY*)&ft1_char16,(XY*)&ft1_char17,(XY*)&ft1_char18,(XY*)&ft1_char19,(XY*)&ft1_char20,(XY*)&ft1_char21,(XY*)&ft1_char22,(XY*)&ft1_char23,(XY*)&ft1_char24,(XY*)&ft1_char25,(XY*)&ft1_char26,(XY*)&ft1_char27,(XY*)&ft1_char28,(XY*)&ft1_char29,(XY*)&ft1_char30,(XY*)&ft1_char31,(XY*)&ft1_char32,(XY*)&ft1_char33,(XY*)&ft1_char34,(XY*)&ft1_char35,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char45,(XY*)&ft1_char46,(XY*)&ft1_char47,(XY*)&ft1_char48,(XY*)&ft1_char49,(XY*)&ft1_char50,(XY*)&ft1_char51,(XY*)&ft1_char52,(XY*)&ft1_char53,(XY*)&ft1_char54,(XY*)&ft1_char55,(XY*)&ft1_char56,(XY*)&ft1_char57,(XY*)&ft1_char58,(XY*)&ft1_char59,(XY*)&ft1_char60,(XY*)&ft1_char61,(XY*)&ft1_char62,(XY*)&ft1_char63,(XY*)&ft1_char64,(XY*)&ft1_char65,(XY*)&ft1_char66,(XY*)&ft1_char67,(XY*)&ft1_char68,(XY*)&ft1_char69,(XY*)&ft1_char70,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char40,(XY*)&ft1_char41,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char36,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,};
short const oldFontTableLen[255] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,14,0,2,0,0,0,5,0,3,1,0,13,7,10,10,10,9,12,7,13,12,0,0,0,0,0,9,0,14,14,9,13,10,9,16,12,10,10,10,8,13,12,15,10,13,16,11,7,10,9,16,9,7,9,0,0,0,0,0,0,14,16,11,16,14,11,14,13,7,8,13,9,15,12,12,12,17,10,12,11,13,9,12,9,12,14,0,0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
XY* const mixedFontTable[255] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char37,nullptr,nullptr,nullptr,(XY*)&ft1_char42,nullptr,(XY*)&ft1_char38,nullptr,nullptr,nullptr,(XY*)&ft1_char43,nullptr,(XY*)&ft1_char44,(XY*)&ft1_char71,nullptr,(XY*)&ft1_char0,(XY*)&ft1_char1,(XY*)&ft1_char2,(XY*)&ft1_char3,(XY*)&ft1_char4,(XY*)&ft1_char5,(XY*)&ft1_char6,(XY*)&ft1_char7,(XY*)&ft1_char8,(XY*)&ft1_char9,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char39,nullptr,(XY*)&ft2_char0,(XY*)&ft2_char1,(XY*)&ft2_char2,(XY*)&ft2_char3,(XY*)&ft2_char4,(XY*)&ft2_char5,(XY*)&ft2_char6,(XY*)&ft2_char7,(XY*)&ft2_char8,(XY*)&ft2_char9,(XY*)&ft2_char10,(XY*)&ft2_char11,(XY*)&ft2_char12,(XY*)&ft2_char13,(XY*)&ft2_char14,(XY*)&ft2_char15,(XY*)&ft2_char16,(XY*)&ft2_char17,(XY*)&ft2_char18,(XY*)&ft2_char19,(XY*)&ft2_char20,(XY*)&ft2_char21,(XY*)&ft2_char22,(XY*)&ft2_char23,(XY*)&ft2_char24,(XY*)&ft2_char25,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char45,(XY*)&ft1_char46,(XY*)&ft1_char47,(XY*)&ft1_char48,(XY*)&ft1_char49,(XY*)&ft1_char50,(XY*)&ft2_char27,(XY*)&ft1_char52,(XY*)&ft1_char53,(XY*)&ft2_char30,(XY*)&ft1_char55,(XY*)&ft1_char56,(XY*)&ft1_char57,(XY*)&ft1_char58,(XY*)&ft1_char59,(XY*)&ft2_char28,(XY*)&ft2_char29,(XY*)&ft1_char62,(XY*)&ft1_char63,(XY*)&ft1_char64,(XY*)&ft1_char65,(XY*)&ft1_char66,(XY*)&ft1_char67,(XY*)&ft1_char68,(XY*)&ft2_char26,(XY*)&ft1_char70,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char40,(XY*)&ft1_char41,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,(XY*)&ft1_char36,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,};
short const mixedFontTableLen[255] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,14,0,2,0,0,0,5,0,3,1,0,13,7,10,10,10,9,12,7,13,12,0,0,0,0,0,9,0,18,20,11,16,15,12,17,16,11,9,14,9,18,17,14,13,17,18,12,11,14,13,16,13,11,15,0,0,0,0,0,0,14,16,11,16,14,11,16,13,7,8,13,9,15,12,12,11,12,10,12,11,13,9,12,9,14,14,0,0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

#pragma endregion

inline void getChar(char c, const XY *&ptr, int &len, int fontflag = 0) {
    if (c == '`') {
        c = 176;
    }

    if (fontflag == 0) {
        // wtf?! there's a C API to convert between upper/lower-case ASCII. TIL! <3 C
        c = toupper(c);
        ptr = oldFontTable[c];
        len = oldFontTableLen[c];
    } else if (fontflag == 1) {
        ptr = mixedFontTable[c];
        len = mixedFontTableLen[c];
    } else {
        ptr = mixedFontTable[c];
        len = mixedFontTableLen[c];
    }
}