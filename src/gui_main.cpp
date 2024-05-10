#include <iostream>
#include "raylib.h"

// To declare and define elsewhere
// https://lospec.com/palette-list/bluem0ld
Color MIDNIGHTBLACK = {25, 27, 26, 255};
Color DEEPOCEANBLUE = {41, 66, 87, 255};
Color MINTYTEAL = {87, 156, 154, 255};
Color PALEJADE = {153, 201, 179};


int main() {
    InitWindow(1024, 720, "The Game Of Life");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(DEEPOCEANBLUE);
        EndDrawing();
    }

    return 0;
}