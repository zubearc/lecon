// LeconSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

#include "Win32Renderer.h"
#include "src/Lecon2.h"
#include "src/LeconConfig.h"
#include "src/Screen.h"


// Win32 Console Impl
int main() {
    std::cout << "Hello World!\n";

    auto console = new Screen(32, 64);
    //console->set(0, 0, 1);
    console->set(2, 0, 1);
    //console->write('C');
    console->write("Hello");

    for (int i = 0; i < 100; i++) {
        console->clear();
        system("cls");
        if (i % 2 == 0) {
            console->write("Hello");
        } else {
            console->write("World");
        }
        console->draw();
        Sleep(2000);
    }

    //system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
