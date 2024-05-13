#include <iostream>
#include <cmath>
#include "raylib.h"
#include "gui_colors.hpp"

// Define the bounds for the main menu and its buttons
Rectangle mainMenuBounds = {344, 198.6, 336, 324.1};
Rectangle mainMenuGenerateNewGridBounds = {403.6, 249.4, 216, 44.1};
Rectangle mainMenuLoadGridBounds = {404.2, 335.1, 216, 44.1};
Rectangle mainMenuSaveGridBounds = {404.2, 422.4, 216, 44.1};

// Function to handle clicking the "Generate New Grid" button in the main menu
void clickMainMenuGenerateNewGrid(
        int& currentWidth,
        int& widthDigits,
        int& currentHeight,
        int& heightDigits,
        int& currentDensity,
        int& currentMenu
) {
    // Reset the grid parameters and switch to the generate grid menu
    currentWidth = 0;
    widthDigits = 0;
    currentHeight = 0;
    heightDigits = 0;
    currentDensity = 0;
    currentMenu = 1;
}

// Function to handle clicking the "Load Grid" button in the main menu
void clickMainMenuLoadGrid(int& currentMenu) {
    // Switch to the load grid menu
    currentMenu = 2;
}

// Function to handle clicking the "Save Grid" button in the main menu
void clickMainMenuSaveGrid(int& currentMenu) {
    // Switch to the save grid menu
    currentMenu = 3;
}

// Function to render the main menu
void renderMainMenu(
        Font& jetBrainsMono
) {
    // Draw the main menu background
    DrawRectangleRec(mainMenuBounds, MIDNIGHTBLACK);
    DrawRectangleLinesEx(mainMenuBounds, 4, DEEPOCEANBLUE);

    // Draw the "Generate New Grid" button
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

    // Draw the "Load Grid" button
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

    // Draw the "Save Grid" button
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
}