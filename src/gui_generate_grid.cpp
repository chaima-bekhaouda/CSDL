#include "raylib.h"
#include "gui_colors.hpp"


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