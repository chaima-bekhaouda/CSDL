#include <iostream>
#include <vector>
#include <cmath>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_grid_generation.hpp"
#include "gol_file_handling.hpp"
#include "raylib.h"
#include "gui_colors.hpp"
#define MAX_ZOOM 60.0f


int main() {
    std::vector<std::vector<unsigned char>> currentGrid = loadGrid(
        readGridFile("default.cells")
    );
    std::vector<std::vector<unsigned char>> nextGrid = currentGrid;

    InitWindow(1024, 720, "The Game Of Life");

    Vector2 screenTopLeft = {0, 0};
    Vector2 screenBottomRight = {1024, 720};

    int maxTicks = 100;
    int ticks = 0;
    bool drawFPS = false;

    Font jetBrainsMono = LoadFontEx(
        "resources/JetBrainsMono-Regular.ttf",
        26,
        NULL,
        0
    );

    int currentMenu = -1;
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

    Rectangle mainMenuBounds = {344, 198.6, 336, 324.1};
    Rectangle mainMenuGenerateNewGridBounds = {403.6, 249.4, 216, 44.1};
    Rectangle mainMenuLoadGridBounds = {404.2, 335.1, 216, 44.1};
    Rectangle mainMenuSaveGridBounds = {404.2, 422.4, 216, 44.1};

    Rectangle generateNewGridBounds = {344, 154.3, 336, 412.7};
    Rectangle widthEntryBounds = {442.7, 205.1, 137.8, 44.1};
    Rectangle heightEntryBounds = {442.7, 291.6, 137.8, 44.1};
    Rectangle densityEntryBounds = {442.7, 378.1, 142.2, 44.1};
    Rectangle createNewGridBounds = {428.4, 464.1, 166.5, 44.1};


    Camera2D camera;
    camera.target = (Vector2){
        currentGrid[0].size() / 2.0f,
        currentGrid.size() / 2.0f
    };
    camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 10.0f;

    Color gridLineColor = DEEPOCEANBLUE;
    gridLineColor.a = (int)((camera.zoom - 1.0f) / (MAX_ZOOM - 1.0f) * 255.0f);

    while (!WindowShouldClose()) {
        if (play) {
            if (ticks == 0) {
                iterateOverGrid(currentGrid, nextGrid);
                currentGrid = nextGrid;
            }
            ticks = (ticks + 1 + maxTicks) % maxTicks;
        };


        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), menuButtonBounds)) {
                switch (currentMenu != -1) {
                    case 0: currentMenu = 0; break;
                    case 1: currentMenu = -1; break;
                };
            } else if (CheckCollisionPointRec(
                GetMousePosition(),
                menuBarPlayPauseBounds
            )) {
                switch (play) {
                    case false: play = true; break;
                    case true: play = false; break;
                }
            } else if (currentMenu != -1) {
                switch (currentMenu) {
                    case 0:
                        if (CheckCollisionPointRec(
                            GetMousePosition(),
                            mainMenuGenerateNewGridBounds
                        )) {
                            currentMenu = 1;
                        } else if (CheckCollisionPointRec(
                            GetMousePosition(),
                            mainMenuLoadGridBounds
                        )) {
                            std::cout << "set currentMenu to 2\n";
                        } else if (CheckCollisionPointRec(
                            GetMousePosition(),
                            mainMenuSaveGridBounds
                        )) {
                            std::cout << "set currentMenu to 3\n";
                        };
                        break;
                }
            } else {
                Vector2 clickPos = GetScreenToWorld2D(
                    GetMousePosition(),
                    camera
                );
                clickPos.x = floor(clickPos.x);
                clickPos.y = floor(clickPos.y);
                if (
                    (0 <= clickPos.x && clickPos.x <= currentGrid[0].size()) &&
                    (0 <= clickPos.y && clickPos.y <= currentGrid.size())
                ) {
                    switch (getCellState(currentGrid[clickPos.y][clickPos.x])) {
                        case 0:
                            setCellAlive(nextGrid[clickPos.y][clickPos.x]);
                            addNeighborCountToNeighbors(
                                nextGrid, clickPos.y, clickPos.x
                            );
                            currentGrid = nextGrid;
                            break;
                        case true:
                            setCellDead(nextGrid[clickPos.y][clickPos.x]);
                            subNeighborCountToNeighbors(
                                nextGrid, clickPos.y, clickPos.x
                            );
                            currentGrid = nextGrid;
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
                currentGrid[0].size() / 2.0f,
                currentGrid.size() / 2.0f
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
        if (IsKeyPressed(KEY_SPACE)) {
            switch (play) {
                case false: play = true; break;
                case true: play = false; break;
            };
        };

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            if (!CheckCollisionPointRec(GetMousePosition(), menuButtonBounds)) {
                Vector2 mouseDelta = GetMouseDelta();
                camera.target.x -= mouseDelta.x / camera.zoom;
                camera.target.y -= mouseDelta.y / camera.zoom;
            };
        };

        double mouseWheelMove = GetMouseWheelMove();
        if (IsKeyDown(KEY_LEFT_SHIFT)) {
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
        } else {
            maxTicks += mouseWheelMove * 10;
            if (maxTicks % 10 == 1) maxTicks -= 1;
            if (maxTicks < 1) maxTicks = 1;
        };

        Vector2 worldTopLeft = GetScreenToWorld2D(screenTopLeft, camera);
        Vector2 worldBottomRight = GetScreenToWorld2D(screenBottomRight, camera);

        BeginDrawing();
            ClearBackground(MIDNIGHTBLACK);

            BeginMode2D(camera);
                // Draw grid line
                for (int y = 0; y <= currentGrid.size(); y++) {
                    DrawLine(0, y, currentGrid[0].size(), y, gridLineColor);
                };
                for (int x = 0; x <= currentGrid[0].size(); x++) {
                    DrawLine(x, 0, x, currentGrid.size(), gridLineColor);
                };

                // Draw cell grid
                for (int y = 0; y < currentGrid.size(); y++) {
                    if (
                        y + 1 < worldTopLeft.y ||
                        y - 1 > worldBottomRight.y
                    ) {
                        continue;
                    };
                    for (int x = 0; x < currentGrid[y].size(); x++) {
                        if (
                            x + 1 < worldTopLeft.x ||
                            x - 1 > worldBottomRight.x ||
                            getCellState(currentGrid[y][x]) == 0
                        ) {
                            continue;
                        };
                        DrawPixel(x, y, PALEJADE);
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
                    maxTicks
                ),
                (Vector2){255.9f, 648.8f},
                26,
                0,
                MIDNIGHTBLACK
            );

            switch (currentMenu) {
                case 0:
                    DrawRectangleRec(mainMenuBounds, MIDNIGHTBLACK);
                    DrawRectangleLinesEx(mainMenuBounds, 4, DEEPOCEANBLUE);
                    DrawRectangleRounded(
                        mainMenuGenerateNewGridBounds,
                        33,
                        10,
                        MINTYTEAL
                    );
                    DrawTextEx(
                        jetBrainsMono,
                        "Generate new grid",
                        Vector2{418, 258},
                        26,
                        0,
                        MIDNIGHTBLACK
                    );
                    DrawRectangleRounded(
                        mainMenuLoadGridBounds,
                        33,
                        10,
                        MINTYTEAL
                    );
                    DrawTextEx(
                        jetBrainsMono,
                        "Load current grid",
                        Vector2{419, 344},
                        26,
                        0,
                        MIDNIGHTBLACK
                    );
                    DrawRectangleRounded(
                        mainMenuSaveGridBounds,
                        33,
                        10,
                        MINTYTEAL
                    );
                    DrawTextEx(
                        jetBrainsMono,
                        "Save current grid",
                        Vector2{418, 432},
                        26,
                        0,
                        MIDNIGHTBLACK
                    );
                    break;
                case 1:
                    DrawRectangleRec(generateNewGridBounds, MIDNIGHTBLACK);
                    DrawRectangleLinesEx(
                        generateNewGridBounds, 4, DEEPOCEANBLUE
                    );
                    DrawTextEx(
                        jetBrainsMono,
                        "Width",
                        Vector2{486, 177.6},
                        26,
                        0,
                        MINTYTEAL
                    );
                    DrawRectangleRounded(widthEntryBounds, 33, 10, MINTYTEAL);
                    DrawTextEx(
                        jetBrainsMono,
                        "Height",
                        Vector2{480, 265.9},
                        26,
                        0,
                        MINTYTEAL
                    );
                    DrawRectangleRounded(heightEntryBounds, 33, 10, MINTYTEAL);
                    DrawTextEx(
                        jetBrainsMono,
                        "Density",
                        Vector2{476, 352.7},
                        26,
                        0,
                        MINTYTEAL
                    );
                    DrawRectangleRounded(densityEntryBounds, 33, 10, MINTYTEAL);
                    DrawRectangleRounded(createNewGridBounds, 33, 10, MINTYTEAL);
                    DrawTextEx(
                        jetBrainsMono,
                        "Create new grid",
                        Vector2{429, 473},
                        26,
                        0,
                        MIDNIGHTBLACK
                    );
                    break;
            };

            if (drawFPS) DrawFPS(900, 0);
        EndDrawing();
    };

    CloseWindow();

    return 0;
}