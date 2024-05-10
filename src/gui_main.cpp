#include <vector>
#include <cmath>
#include "gol_elements.hpp"
#include "raylib.h"
#include "gui_colors.hpp"


int main() {
    InitWindow(1024, 720, "The Game Of Life");

    Vector2 screenTopLeft = {0, 0};
    Vector2 screenBottomRight = {1024, 720};

    bool drawFPS = false;
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


    Camera2D camera;
    camera.target = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), menuButtonBounds)) {
                menuUp ? menuUp = false : menuUp = true;
                std::cout << menuUp << '\n';
            };
        };

        if (IsKeyPressed(KEY_F)) {
            drawFPS ? drawFPS = false : drawFPS = true;
        }


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

        Vector2 worldTopLeft = GetScreenToWorld2D(screenTopLeft, camera);
        Vector2 worldBottomRight = GetScreenToWorld2D(screenBottomRight, camera);

        BeginDrawing();
            ClearBackground(DEEPOCEANBLUE);

            BeginMode2D(camera);
            /*
                for (int y = 0; y < whateverMatrix.size(); y++) {
                    if (
                        y + 1 < worldTopLeft.y ||
                        y - 1 > worldBottomRight.y
                    ) {
                        continue;
                    };
                    for (int x = 0; x < whateverMatrix[y].size(); x++) {
                        if (
                            x + 1 < worldTopLeft.x ||
                            x - 1 > worldBottomRight.x
                        ) {
                            continue;
                        };
                        DrawRectangle(
                            x,
                            y,
                            1,
                            1,
                            Color
                        );
                    };
                };
            */
            EndMode2D();

            DrawTextureRec(
                menuButton,
                menuButtonSource,
                (Vector2){menuButtonBounds.x, menuButtonBounds.y},
                WHITE
            );
            if (drawFPS) DrawFPS(900, 0);
        EndDrawing();
    };

    CloseWindow();

    return 0;
}