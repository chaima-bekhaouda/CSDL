#include <cmath>
#include "raylib.h"
#include "gui_colors.hpp"


void renderMainMenu(
    Rectangle& mainMenuBounds,
    Rectangle& mainMenuGenerateNewGridBounds,
    Rectangle& mainMenuLoadGridBounds,
    Rectangle& mainMenuSaveGridBounds,
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
};