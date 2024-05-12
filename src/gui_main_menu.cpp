#include <iostream>
#include <cmath>
#include "raylib.h"
#include "gui_colors.hpp"


Rectangle mainMenuBounds = {344, 198.6, 336, 324.1};
Rectangle mainMenuGenerateNewGridBounds = {403.6, 249.4, 216, 44.1};
Rectangle mainMenuLoadGridBounds = {404.2, 335.1, 216, 44.1};
Rectangle mainMenuSaveGridBounds = {404.2, 422.4, 216, 44.1};


void clickMainMenuGenerateNewGrid(
    int& currentWidth,
    int& widthDigits,
    int& currentHeight,
    int& heightDigits,
    int& currentDensity,
    int& currentMenu
) {
    currentWidth = 0;
    widthDigits = 0;
    currentHeight = 0;
    heightDigits = 0;
    currentDensity = 0;
    currentMenu = 1;
}

void clickMainMenuLoadGrid() {
    std::cout << "set currentMenu to 2\n";
}

void clickMainMenuSaveGrid(int& currentMenu) {
    currentMenu = 3;
}

void renderMainMenu(
    Font& jetBrainsMono
) {
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
}