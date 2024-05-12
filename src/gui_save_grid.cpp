#include "raylib.h"
#include "gui_colors.hpp"


Rectangle saveGridBounds = {344, 229.8, 336, 258.4};
Rectangle gridNameEntryBounds = {365.6, 302.4, 292.3, 44.1};
Rectangle saveCurrentGameBounds = {404.2, 387.8, 216, 44.1};


void displaySaveGrid(Font& jetBrainsMono) {
    DrawRectangleRec(saveGridBounds, MIDNIGHTBLACK);
    DrawRectangleLinesEx(saveGridBounds, 4, DEEPOCEANBLUE);
    DrawTextEx(
        jetBrainsMono, "Grid name", Vector2 {465.4, 266.6}, 26, 0, MINTYTEAL
    );
    DrawRectangleRounded(gridNameEntryBounds, 33, 10, MINTYTEAL);
    DrawRectangleRounded(saveCurrentGameBounds, 33, 10, MINTYTEAL);
    DrawTextEx(
        jetBrainsMono,
        "Save current game",
        Vector2 {420, 397}, 
        26,
        0,
        MIDNIGHTBLACK
    );
}