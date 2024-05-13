#include "raylib.h"
#include "gui_colors.hpp"


Rectangle loadGridBounds = {344, 154.3, 336, 412.7};
Rectangle fileListBounds = {365.6, 172, 294.7, 274.7};
Rectangle loadGridButtonBounds = {428.5, 481.1, 166.5, 44.1};


void displayLoadGrid(Font& jetBrainsMono) {
    DrawRectangleRec(loadGridBounds, MIDNIGHTBLACK);
    DrawRectangleLinesEx(loadGridBounds, 4, DEEPOCEANBLUE);

    BeginScissorMode(
        (int)fileListBounds.x,
        (int)fileListBounds.y,
        (int)fileListBounds.width,
        (int)fileListBounds.height
    );
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), MINTYTEAL);
    EndScissorMode();

    DrawRectangleRounded(loadGridButtonBounds, 33, 10, MINTYTEAL);
    DrawTextEx(
        jetBrainsMono,
        "Load grid",
        Vector2 {462, 490},
        26,
        0,
        MIDNIGHTBLACK
    );
}