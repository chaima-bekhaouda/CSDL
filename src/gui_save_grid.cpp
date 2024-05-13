#include <string>
#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"

#define MAX_GRID_NAME_SIZE 24


Rectangle saveGridBounds = {344, 229.8, 336, 258.4};
Rectangle gridNameEntryBounds = {365.6, 302.4, 292.3, 44.1};
Rectangle saveCurrentGameBounds = {404.2, 387.8, 216, 44.1};


void typeIntoGridNameEntry(std::string& currentGridName) {
    if (IsKeyPressed(KEY_BACKSPACE) && currentGridName.size() != 0) {
        currentGridName.pop_back();
        return;
    };

    if (currentGridName.size() >= MAX_GRID_NAME_SIZE) {
        return;
    };

    char pressedChar = GetCharPressed();
    if (pressedChar == 0) {
        return;
    };

    currentGridName.push_back(pressedChar);
}

void clickSaveGridButton(
    std::function<void (std::string, std::vector<std::vector<unsigned char>>)>
    saveGrid,
    std::string& currentGridName,
    std::vector<std::vector<unsigned char>>& currentGrid,
    int& currentMenu
) {
    saveGrid(currentGridName, currentGrid);
    currentMenu = -1;
    currentGridName = "";
}

void displaySaveGrid(Font& jetBrainsMono, std::string& currentGridName) {
    DrawRectangleRec(saveGridBounds, MIDNIGHTBLACK);
    DrawRectangleLinesEx(saveGridBounds, 4, DEEPOCEANBLUE);
    DrawTextEx(
        jetBrainsMono, "Grid name", Vector2 {465.4, 266.6}, 26, 0, MINTYTEAL
    );
    DrawRectangleRounded(gridNameEntryBounds, 33, 10, MINTYTEAL);
    if (currentGridName.size() == 0) {
        DrawTextEx(
            jetBrainsMono,
            "...",
            Vector2 {495.6, 315.5},
            26,
            0,
            PALEJADE
        );
    } else {
        DrawTextEx(
            jetBrainsMono,
            currentGridName.c_str(),
            Vector2 {380, 312},
            26,
            0,
            MIDNIGHTBLACK
        );
    }
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