#include <iostream>
#include <vector>
#include <cmath>
#include "gol_elements.hpp"
#include "gol_file_handling.hpp"
#include "raylib.h"
#include "gui_colors.hpp"
#define MAX_ZOOM 60.0f


int main() {
    std::vector<std::vector<struct Cell>> grid(
        64,
        std::vector<struct Cell> (64, {0, 0})
    );

    InitWindow(1024, 720, "The Game Of Life");

    Vector2 screenTopLeft = {0, 0};
    Vector2 screenBottomRight = {1024, 720};

    bool drawFPS = false;

    Font jetBrainsMono = LoadFontEx(
        "resources/JetBrainsMono-Regular.ttf",
        26,
        NULL,
        0
    );

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

    Texture menuBar = LoadTexture("resources/menu-bar.png");
    Rectangle menuBarSource = {
        0,
        0,
        (float)menuBar.width,
        (float)menuBar.height
    };
    Rectangle menuBarBounds = {
        -51.5,
        572.6,
        (float)menuBar.width,
        (float)menuBar.height
    };

    bool play = false;
    Texture menuBarPlay = LoadTexture("resources/menu-bar-play.png");
    Texture menuBarPause = LoadTexture("resources/menu-bar-pause.png");
    Rectangle menuBarPlayPauseSource = {
        0,
        0,
        (float)menuBarPlay.width,
        (float)menuBarPlay.height
    };
    Rectangle menuBarPlayPauseBounds = {
        14.0,
        601.9,
        (float)menuBarPlay.width,
        (float)menuBarPlay.height
    };


    Camera2D camera;
    camera.target = (Vector2){grid[0].size() / 2.0f, grid.size() / 2.0f};
    camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 10.0f;

    Color gridLineColor = DEEPOCEANBLUE;
    gridLineColor.a = (int)((camera.zoom - 1.0f) / (MAX_ZOOM - 1.0f) * 255.0f);

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), menuButtonBounds)) {
                menuUp ? menuUp = false : menuUp = true;
                std::cout << menuUp << '\n';
            } else if (CheckCollisionPointRec(
                GetMousePosition(),
                menuBarPlayPauseBounds
            )) {
                switch (play) {
                    case false: play = true; break;
                    case true: play = false; break;
                }
            } else {
                Vector2 clickPos = GetScreenToWorld2D(
                    GetMousePosition(),
                    camera
                );
                clickPos.x = floor(clickPos.x);
                clickPos.y = floor(clickPos.y);
                if (
                    (0 <= clickPos.x && clickPos.x <= grid[0].size()) &&
                    (0 <= clickPos.y && clickPos.y <= grid.size())
                ) {
                    switch (grid[clickPos.y][clickPos.x].currentState) {
                        case false:
                            grid[clickPos.y][clickPos.x].currentState = true;
                            break;
                        case true:
                            grid[clickPos.y][clickPos.x].currentState = false;
                            break;
                    }
                }
            };
        };

        if (IsKeyPressed(KEY_F)) {
            drawFPS ? drawFPS = false : drawFPS = true;
        }


        if (IsKeyPressed(KEY_R)) {
            camera.target = (Vector2){
                grid[0].size() / 2.0f,
                grid.size() / 2.0f
            };
            camera.offset = (Vector2){
                GetScreenWidth() / 2.0f,
                GetScreenHeight() / 2.0f
            };
            camera.rotation = 0.0f;
            camera.zoom = 10.0f;

            gridLineColor.a = (int)(
                (camera.zoom - 1.0f)
                / (MAX_ZOOM - 1.0f)
                * 255.0f
            );
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
            } else if (camera.zoom > MAX_ZOOM) {
                camera.zoom = MAX_ZOOM;
            };
            gridLineColor.a = (int)(
                (camera.zoom - 1.0f)
                / (MAX_ZOOM - 1.0f)
                * 255.0f
            );
        };

        Vector2 worldTopLeft = GetScreenToWorld2D(screenTopLeft, camera);
        Vector2 worldBottomRight = GetScreenToWorld2D(screenBottomRight, camera);

        BeginDrawing();
            ClearBackground(MIDNIGHTBLACK);

            BeginMode2D(camera);
                // Draw grid line
                for (int y = 0; y <= grid.size(); y++) {
                    DrawLine(0, y, grid[0].size(), y, gridLineColor);
                };
                for (int x = 0; x <= grid[0].size(); x++) {
                    DrawLine(x, 0, x, grid.size(), gridLineColor);
                };

                // Draw cell grid
                for (int y = 0; y < grid.size(); y++) {
                    if (
                        y + 1 < worldTopLeft.y ||
                        y - 1 > worldBottomRight.y
                    ) {
                        continue;
                    };
                    for (int x = 0; x < grid[y].size(); x++) {
                        if (
                            x + 1 < worldTopLeft.x ||
                            x - 1 > worldBottomRight.x ||
                            !grid[y][x].currentState
                        ) {
                            continue;
                        };
                        DrawRectangle(
                            x,
                            y,
                            1,
                            1,
                            PALEJADE
                        );
                    };
                };
            EndMode2D();

            DrawTextureRec(
                menuButton,
                menuButtonSource,
                (Vector2){menuButtonBounds.x, menuButtonBounds.y},
                WHITE
            );

            DrawTextureRec(
                menuBar,
                menuBarSource,
                (Vector2){menuBarBounds.x, menuBarBounds.y},
                WHITE
            );
            Texture currentTexture = {};
            switch (play) {
                case false: currentTexture = menuBarPlay; break;
                case true: currentTexture = menuBarPause; break;
            }
            DrawTextureRec(
                currentTexture,
                menuBarPlayPauseSource,
                (Vector2){menuBarPlayPauseBounds.x, menuBarPlayPauseBounds.y},
                WHITE
            );
            DrawTextEx(
                jetBrainsMono,
                TextFormat(
                    "x: %.2f",
                    GetScreenToWorld2D(GetMousePosition(), camera).x
                ),
                (Vector2){92.0f, 600.1f},
                26,
                0,
                MIDNIGHTBLACK
            );
            DrawTextEx(
                jetBrainsMono,
                TextFormat(
                    "y: %.2f",
                    GetScreenToWorld2D(GetMousePosition(), camera).y
                ),
                (Vector2){92.0f, 645.8f},
                26,
                0,
                MIDNIGHTBLACK
            );
            DrawTextEx(
                jetBrainsMono,
                TextFormat(
                    "zoom: %.2f",
                    camera.zoom 
                ),
                (Vector2){255.9f, 600.1f},
                26,
                0,
                MIDNIGHTBLACK
            );
            DrawTextEx(
                jetBrainsMono,
                TextFormat(
                    "delta-time: %d",
                    1 
                ),
                (Vector2){255.9f, 648.8f},
                26,
                0,
                MIDNIGHTBLACK
            );

            if (drawFPS) DrawFPS(900, 0);
        EndDrawing();
    };

    CloseWindow();

    return 0;
}