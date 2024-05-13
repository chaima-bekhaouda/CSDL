#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_grid_generation.hpp"
#include "gol_file_handling.hpp"

#include "raylib.h"
#include "gui_colors.hpp"
#include "gui_main_menu.hpp"
#include "gui_generate_grid.hpp"
#include "gui_load_grid.hpp"
#include "gui_save_grid.hpp"
#include <iostream>

#define MAX_ZOOM 60.0f // Define the maximum zoom level


int main() {
    // Load the default grid
    std::vector<std::vector<unsigned char>> currentGrid ({
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 4, 6, 4, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 5, 9, 5, 4, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 7, 14, 7, 6, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 3, 8, 3, 4, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 2, 4, 2, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    });
    std::vector<std::vector<unsigned char>> nextGrid = currentGrid;

    // Initialize the game window
    InitWindow(1024, 720, "The Game Of Life");
    // Define the screen boundaries
    Vector2 screenTopLeft = {0, 0};
    Vector2 screenBottomRight = {1024, 720};

    // Define the game parameters
    int maxTicks = 100;
    int ticks = 0;
    bool drawFPS = false;

    // Load the font
    Font jetBrainsMono = LoadFontEx(
        "resources/JetBrainsMono-Regular.ttf",
        26,
        NULL,
        0
    );

    // Initialize the menu
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

    // Load the menu bar texture
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

    // Initialize the play state and load the play/pause button textures
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


    // Initialize the grid parameters
    int currentWidth = 0;
    int widthDigits = 0;
    int currentHeight = 0;
    int heightDigits = 0;
    int currentDensity = 0;


    // Initialize the grid name
    std::string currentGridName = "";


    // Initialize the camera with the target set to the center of the current grid
    Camera2D camera;
    camera.target = (Vector2){
        currentGrid[0].size() / 2.0f,
        currentGrid.size() / 2.0f
    };
    camera.offset = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 10.0f;

    Color gridLineColor = DEEPOCEANBLUE;
    gridLineColor.a = (int)((camera.zoom) / (MAX_ZOOM) * 255.0f);

    // Main game loop
    while (!WindowShouldClose()) {
        if (play) {
            if (ticks == 0) {
                iterateOverGrid(currentGrid, nextGrid);
                currentGrid = nextGrid;
            }
            ticks = (ticks + 1 + maxTicks) % maxTicks;
        };

        // If the left mouse button is pressed
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
                            clickMainMenuGenerateNewGrid(
                                currentWidth,
                                widthDigits,
                                currentHeight,
                                heightDigits,
                                currentDensity,
                                currentMenu
                            );
                        } else if (CheckCollisionPointRec(
                            GetMousePosition(),
                            mainMenuLoadGridBounds
                        )) {
                            clickMainMenuLoadGrid(currentMenu);
                        } else if (CheckCollisionPointRec(
                            GetMousePosition(),
                            mainMenuSaveGridBounds
                        )) {
                            clickMainMenuSaveGrid(currentMenu);
                        };
                        break;
                    case 1:
                        if (CheckCollisionPointRec(
                            GetMousePosition(),
                            createNewGridBounds
                            ) &&
                            currentWidth != 0 &&
                            currentHeight != 0
                        ) {
                            clickGenerateGridButton(
                                play,
                                currentMenu,
                                currentWidth,
                                currentHeight,
                                currentDensity,
                                MAX_ZOOM,
                                generateGrid,
                                currentGrid,
                                nextGrid,
                                camera,
                                gridLineColor
                            );
                        };
                        break;
                    case 2:
                        if (CheckCollisionPointRec(
                            GetMousePosition(),
                            loadGridButtonBounds
                        )
                        ) {
                            clickLoadGridButton(
                                doesFileExist,
                                areLinesEven,
                                areCharactersValid,
                                readGridFile,
                                loadGrid,
                                currentGridName,
                                currentGrid,
                                nextGrid,
                                currentMenu,
                                camera,
                                gridLineColor,
                                MAX_ZOOM
                            );
                        };
                        break;
                    case 3:
                        if (CheckCollisionPointRec(
                            GetMousePosition(),
                            saveCurrentGameBounds
                            )
                        ) {
                            clickSaveGridButton(
                                saveGrid,
                                currentGridName,
                                currentGrid,
                                currentMenu
                            );
                            break;
                        };
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

        if (currentMenu == 1) {
            if (CheckCollisionPointRec(GetMousePosition(), widthEntryBounds)) {
                typingInWidthEntry(widthDigits, currentWidth);
            } else if (CheckCollisionPointRec(
                GetMousePosition(), heightEntryBounds)
            ) {
                typingInHeightEntry(heightDigits, currentHeight);
            } else if (CheckCollisionPointRec(
                GetMousePosition(),
                densityEntryBounds
                )
            ) {
                typingInDensityEntry(currentDensity);
            };
        } else if (currentMenu == 2) {
            if (CheckCollisionPointRec(
                GetMousePosition(),
                loadGridNameEntryBounds
                )
            ) {
                typeIntoLoadGridNameEntry(currentGridName);
            };
        } else if (currentMenu == 3) {
            if (CheckCollisionPointRec(
                GetMousePosition(),
                gridNameEntryBounds
                )
            ) {
                typeIntoGridNameEntry(currentGridName);
            };
        };

        if (IsKeyPressed(KEY_F) && currentMenu != 3 && currentMenu != 2) {
            drawFPS ? drawFPS = false : drawFPS = true;
        }
        if (IsKeyPressed(KEY_R) && currentMenu != 3 && currentMenu != 2) {
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
        if (IsKeyPressed(KEY_SPACE) && currentMenu != 3) {
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
                (camera.zoom)
                / (MAX_ZOOM)
                * 255.0f
            );
        } else {
            maxTicks += mouseWheelMove * 10;
            if (maxTicks % 10 == 1) maxTicks -= 1;
            if (maxTicks < 1) maxTicks = 1;
        };

// Convert the top left and bottom right screen coordinates to world coordinates
        Vector2 worldTopLeft = GetScreenToWorld2D(screenTopLeft, camera);
        Vector2 worldBottomRight = GetScreenToWorld2D(screenBottomRight, camera);

// Begin drawing to the screen
        BeginDrawing();
        // Clear the screen with a black background
        ClearBackground(MIDNIGHTBLACK);

        // Begin 2D mode with the camera
        BeginMode2D(camera);
        // Draw grid lines
        for (int y = 0; y <= currentGrid.size(); y++) {
            DrawLine(0, y, currentGrid[0].size(), y, gridLineColor);
        };
        for (int x = 0; x <= currentGrid[0].size(); x++) {
            DrawLine(x, 0, x, currentGrid.size(), gridLineColor);
        };

        // Draw cell grid
        for (int y = 0; y < currentGrid.size(); y++) {
            // Skip drawing cells that are outside the visible area
            if (
                    y + 1 < worldTopLeft.y ||
                    y - 1 > worldBottomRight.y
                    ) {
                continue;
            };
            for (int x = 0; x < currentGrid[y].size(); x++) {
                // Skip drawing cells that are outside the visible area or are dead
                if (
                        x + 1 < worldTopLeft.x ||
                        x - 1 > worldBottomRight.x ||
                        getCellState(currentGrid[y][x]) == 0
                        ) {
                    continue;
                };
                // Draw the cell
                DrawPixel(x, y, PALEJADE);
            };
        };
        // End 2D mode
        EndMode2D();

        // Draw the menu button
        DrawTextureRec(
                menuButton,
                menuButtonSource,
                (Vector2){menuButtonBounds.x, menuButtonBounds.y},
                WHITE
        );

        // Draw the menu bar
        DrawTextureRec(
                menuBar,
                menuBarSource,
                (Vector2){menuBarBounds.x, menuBarBounds.y},
                WHITE
        );

        // Determine the texture to use for the play/pause button
        Texture currentTexture = {};
        switch (play) {
            case false: currentTexture = menuBarPlay; break;
            case true: currentTexture = menuBarPause; break;
        }

        // Draw the play/pause button
        DrawTextureRec(
                currentTexture,
                menuBarPlayPauseSource,
                (Vector2){menuBarPlayPauseBounds.x, menuBarPlayPauseBounds.y},
                WHITE
        );

        // Draw the current mouse position and zoom level
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

        // Render the current menu
        switch (currentMenu) {
            case 0:
                renderMainMenu(
                        jetBrainsMono
                );
                break;
            case 1:
                displayGenerateGridMenu(
                        generateNewGridBounds,
                        widthEntryBounds,
                        heightEntryBounds,
                        densityEntryBounds,
                        createNewGridBounds,
                        currentWidth,
                        currentHeight,
                        currentDensity,
                        jetBrainsMono
                );
                break;
            case 2:
                displayLoadGrid(jetBrainsMono, currentGridName);
                break;
            case 3:
                displaySaveGrid(jetBrainsMono, currentGridName);
                break;
        };

        // Draw the FPS counter if enabled
        if (drawFPS) DrawFPS(900, 0);
// End drawing to the screen
        EndDrawing();
    };

// Close the window and end the program
        CloseWindow();

        return 0;
}