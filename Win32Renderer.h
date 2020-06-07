#pragma once

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <vector>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

#include "ConsoleInter.h"
#include "src/Lecon2.h"
#include "src/LeconConfig.h"
#include "src/Screen.h"

Screen* console = nullptr;

void drawBoard(HDC hdc) {

    Graphics graphics(hdc);
    SolidBrush red(Color(0xff, 0, 0));
    SolidBrush white(Color(0xff, 0xff, 0xff));

    int pixelSize = 10;
    int pixelPad = pixelSize * 1.75;

    Rect r = { 0, 0, 2000, 1000 };
    graphics.FillRectangle(&white, r);

    auto rects = std::vector<Rect>();

    if (!console) {
        return;
    }
    int width = screen->width;
    int height = screen->height;

    //screen->test();

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Rect rect = { (x * pixelPad), (y * pixelPad), pixelSize, pixelSize };
            if (console) {
                auto val = console->get(x, y);
                if (val >= 1) {
                    //auto i = screen->width * y + x;
                    //_ASSERT(y < 10);

                    //rects.push_back(rect);
                    graphics.FillRectangle(&red, rect);
                } else {
                    //graphics.FillRectangle(&white, rect);
                }
            }
        }
    }



}

int col = 0xf0;

VOID OnPaint(HDC hdc) {
    Graphics graphics(hdc);
    Pen      pen(Color(255, 0, 0, 255));
    graphics.DrawLine(&pen, 0, 0, 200, 100);

    Rect rect = { 30, 30, 30, 30 };
    //Brush brush{};
      //CreateSolidBrush(RGB(50, 151, 151));
    col = rand();
    //Gdiplus::SolidBrush red(Gdiplus::Color(col, col, 0));

    //graphics.FillRectangle(&red, rect);

    drawBoard(hdc);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    HWND                hWnd;
    MSG                 msg;
    WNDCLASS            wndClass;
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;

    // Initialize GDI+.
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = TEXT("Lecon");

    RegisterClass(&wndClass);

    hWnd = CreateWindow(
        TEXT("Lecon"),   // window class name
        TEXT("Lecon"),  // window caption
        WS_OVERLAPPEDWINDOW,      // window style
        CW_USEDEFAULT,            // initial x position
        CW_USEDEFAULT,            // initial y position
        CW_USEDEFAULT,            // initial x size
        CW_USEDEFAULT,            // initial y size
        NULL,                     // parent window handle
        NULL,                     // window menu handle
        hInstance,                // program instance handle
        NULL);                    // creation parameters

    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    //initBoard(32, 64);
    std::thread lecon(run);

    // wait for lecon to init
    Sleep(100);

    console = screen;


    //console = new Console(32, 64);

    /*while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        console->write("HELLO");
        InvalidateRect(hWnd, NULL, TRUE);
    }*/

    console->write("HELLO");

    int i = 0;

    while (true) {
        /*console->clear();
        //console->write(std::to_string(i++));
        console->set(i++, 0, 1);
        if (i > 63) {
            i = 0;
        }*/
        InvalidateRect(hWnd, NULL, TRUE);

        if (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg); 
            DispatchMessage(&msg);
        } else {
        }
        ///UpdateWindow(hWnd);
        Sleep(200);
    }

    lecon.join();
    GdiplusShutdown(gdiplusToken);
    return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC          hdc;
    PAINTSTRUCT  ps;

    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        OnPaint(hdc);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_ERASEBKGND:
        return true;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
} // WndProc