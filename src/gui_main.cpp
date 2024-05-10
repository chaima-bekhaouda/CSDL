#include <iostream>
#include "raylib.h"
#include "gui_colors.hpp"


int main() {
    InitWindow(1024, 720, "The Game Of Life");

    Camera2D camera;
    camera.target = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

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

        if (IsKeyPressed(KEY_R)) {
            camera.target = (Vector2){
                GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f
            };
            camera.offset = (Vector2){
                GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f
            };
            camera.zoom = 1.0f;
        };

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            if (!CheckCollisionPointRec(GetMousePosition(), menuButtonBounds)) {
                Vector2 mouseDelta = GetMouseDelta();
                camera.target.x -= mouseDelta.x / camera.zoom;
                camera.target.y -= mouseDelta.y / camera.zoom;
            };
        };

        double mouseWheelMove = GetMouseWheelMove();
        if (mouseWheelMove != 0) {
            Vector2 mousePositionInWorld = GetScreenToWorld2D(
                GetMousePosition(), camera
            );
            camera.offset = GetMousePosition();
            camera.target = mousePositionInWorld;
            camera.zoom += mouseWheelMove * 0.25f * camera.zoom;
            if (camera.zoom < 1) {
                camera.zoom = 1;
            } else if (camera.zoom > 30) {
                camera.zoom = 30;
            };
        };

        BeginDrawing();
            ClearBackground(DEEPOCEANBLUE);

            BeginMode2D(camera);
                DrawText("0", 512, 360, 32, RED);
            EndMode2D();

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