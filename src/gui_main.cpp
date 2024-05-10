#include <iostream>
#include "raylib.h"
#include "gui_colors.hpp"


int main() {
    InitWindow(1024, 720, "The Game Of Life");

    bool menuUp = false;
    Texture menuButton = LoadTexture("resources/menu-button.png");
    Rectangle menuButtonSource = {
        0,
        0,
        (float)menuButton.width,
        (float)menuButton.height
    };
    Rectangle menuButtonBounds = {
        -64,
        35,
        (float)menuButton.width, 
        (float)menuButton.height
    };

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), menuButtonBounds)) {
                menuUp ? menuUp = false : menuUp = true;
                std::cout << menuUp << '\n';
            };
        };

        BeginDrawing();
            ClearBackground(DEEPOCEANBLUE);

            DrawTextureRec(
                menuButton,
                menuButtonSource,
                (Vector2){menuButtonBounds.x, menuButtonBounds.y},
                WHITE
            );
        EndDrawing();
    };

    CloseWindow();

    return 0;
}