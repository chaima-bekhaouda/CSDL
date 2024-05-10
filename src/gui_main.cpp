#include "raylib.h"
#include "gui_colors.hpp"


int main() {
    InitWindow(1024, 720, "The Game Of Life");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(DEEPOCEANBLUE);
        EndDrawing();
    }

    return 0;
}