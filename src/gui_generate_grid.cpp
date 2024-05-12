#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"


void typingInWidthEntry(int& widthDigits, int& currentWidth) {
    int minKey;
    widthDigits == 0 ? minKey = 49 : minKey = 48;
    int pressedKey = GetKeyPressed();
    if (
        minKey <= pressedKey &&
        pressedKey <= 57 &&
        widthDigits < 6
    ) {
        int pressedDigit = pressedKey - 48;
        currentWidth = (int) (
            currentWidth * 10 + pressedDigit
        );
        widthDigits++;
    } else if (pressedKey == KEY_BACKSPACE) {
        int lastDigit = currentWidth % 10;
        if (currentWidth == 1) {
            currentWidth = 0;
            widthDigits--;
        } else if (currentWidth > 1) {
            currentWidth /= 10;
            widthDigits--;
        }
    };
}

void typingInHeightEntry(int& heightDigits, int& currentHeight) {
    int minKey;
    heightDigits == 0 ? minKey = 49 : minKey = 48;
    int pressedKey = GetKeyPressed();
    if (
        minKey <= pressedKey &&
        pressedKey <= 57 &&
        heightDigits < 6
    ) {
        int pressedDigit = pressedKey - 48;
        currentHeight = (int) (
            currentHeight * 10 + pressedDigit
        );
        heightDigits++;
    } else if (pressedKey == KEY_BACKSPACE) {
        int lastDigit = currentHeight % 10;
        if (currentHeight == 1) {
            currentHeight = 0;
            heightDigits--;
        } else if (currentHeight > 1) {
            currentHeight /= 10;
            heightDigits--;
        }
    };
}

void typingInDensityEntry(int& currentDensity) {
    int minKey;
    currentDensity == 0 ? minKey = 49 : minKey = 48;
    int pressedKey = GetKeyPressed();
    if (
        minKey <= pressedKey &&
        pressedKey <= 57
    ) {
        int pressedDigit = pressedKey - 48;
        int newDensity = (int) (
            currentDensity * 10 + pressedDigit
        );
        if (newDensity <= 100) {
            currentDensity = newDensity;
        }
    } else if (pressedKey == KEY_BACKSPACE) {
        int lastDigit = currentDensity % 10;
        if (currentDensity == 1) {
            currentDensity = 0;
        } else if (currentDensity > 1) {
            currentDensity /= 10;
        }
    };
}

void clickGenerateGridButton(
    bool& play,
    int& currentMenu,
    int& currentWidth,
    int& currentHeight,
    int& currentDensity,
    float MAX_ZOOM,
    std::function<std::vector<std::vector<unsigned char>> (int, int, double)>
    generateGrid,
    std::vector<std::vector<unsigned char>>& currentGrid,
    std::vector<std::vector<unsigned char>>& nextGrid,
    Camera2D& camera,
    Color& gridLineColor
) {
    play = false;

    currentGrid = generateGrid(
        currentHeight,
        currentWidth,
        (double) currentDensity / 100
    );
    nextGrid = currentGrid;
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
    currentMenu = -1;
}

void displayGenerateGridMenu(
    Rectangle& generateNewGridBounds,
    Rectangle& widthEntryBounds,
    Rectangle& heightEntryBounds,
    Rectangle& densityEntryBounds,
    Rectangle& createNewGridBounds,
    int& currentWidth,
    int& currentHeight,
    int& currentDensity,
    Font& jetBrainsMono
) {
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
    if (currentWidth == 0) {
        DrawTextEx(
            jetBrainsMono,
            "...",
            Vector2{496, 217.8},
            26,
            0,
            PALEJADE
        );
    } else {
        DrawTextEx(
            jetBrainsMono,
            TextFormat("%d", currentWidth),
            Vector2{474, 214},
            26,
            0,
            MIDNIGHTBLACK
        );
    };
    DrawTextEx(
        jetBrainsMono,
        "Height",
        Vector2{480, 265.9},
        26,
        0,
        MINTYTEAL
    );
    DrawRectangleRounded(heightEntryBounds, 33, 10, MINTYTEAL);
    if (currentHeight == 0) {
        DrawTextEx(
            jetBrainsMono,
            "...",
            Vector2{496, 303.4},
            26,
            0,
            PALEJADE
        );
    } else {
        DrawTextEx(
            jetBrainsMono,
            TextFormat("%d", currentHeight),
            Vector2{474, 299.6},
            26,
            0,
            MIDNIGHTBLACK
        );
    };
    DrawTextEx(
        jetBrainsMono,
        "Density",
        Vector2{476, 352.7},
        26,
        0,
        MINTYTEAL
    );
    DrawRectangleRounded(densityEntryBounds, 33, 10, MINTYTEAL);
    if (currentDensity == 0) {
        DrawTextEx(
            jetBrainsMono,
            "...",
            Vector2{496, 389},
            26,
            0,
            PALEJADE
        );
    } else {
        DrawTextEx(
            jetBrainsMono,
            TextFormat("%d%%", currentDensity),
            Vector2{493.3, 389.9},
            26,
            0,
            MIDNIGHTBLACK
        );
    };
    DrawRectangleRounded(createNewGridBounds, 33, 10, MINTYTEAL);
    DrawTextEx(
        jetBrainsMono,
        "Create new grid",
        Vector2{429, 473},
        26,
        0,
        MIDNIGHTBLACK
    );
}