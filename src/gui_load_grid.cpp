#include <string>
#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"
#include <iostream>

#define MAX_GRID_NAME_SIZE 24


Rectangle loadGridBounds = {344, 229.8, 336, 258.4};
Rectangle loadGridNameEntryBounds = {365.6, 302.4, 292.3, 44.1};
Rectangle loadGridButtonBounds = {404.2, 387.8, 216, 44.1};


void typeIntoLoadGridNameEntry(std::string& currentGridName) {
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

void clickLoadGridButton(
    std::function<bool (std::string)> doesFileExist,
    std::function<bool (std::string)> areLinesEven,
    std::function<bool (std::string)> areCharactersValid,
    std::function<std::string (std::string)> readGridFile,
    std::function<std::vector<std::vector<unsigned char>> (std::string)> loadGrid,
    std::string& currentGridName,
    std::vector<std::vector<unsigned char>>& currentGrid,
    std::vector<std::vector<unsigned char>>& nextGrid,
    int& currentMenu,
    Camera2D& camera,
    Color& gridLineColor,
    float MAX_ZOOM
) {
    if (currentGridName.size() == 0) {
        return;
    } else if (!doesFileExist(currentGridName)) {
        return;
    } else if (!areLinesEven(currentGridName)) {
        return;
    } else if (!areCharactersValid(currentGridName)) {
        return;
    };

    std::string gridFile = readGridFile(currentGridName);
    currentGrid = loadGrid(gridFile);
    nextGrid = currentGrid;

    currentGridName = "";
    currentMenu = -1;

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
}

void displayLoadGrid(Font& jetBrainsMono, std::string& currentGridName) {
    DrawRectangleRec(loadGridBounds, MIDNIGHTBLACK);
    DrawRectangleLinesEx(loadGridBounds, 4, DEEPOCEANBLUE);
    DrawTextEx(
        jetBrainsMono, "Grid name", Vector2 {465.4, 266.6}, 26, 0, MINTYTEAL
    );
    DrawRectangleRounded(loadGridNameEntryBounds, 33, 10, MINTYTEAL);
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
    DrawRectangleRounded(loadGridButtonBounds, 33, 10, MINTYTEAL);
    DrawTextEx(
        jetBrainsMono,
        "Load current game",
        Vector2 {420, 397}, 
        26,
        0,
        MIDNIGHTBLACK
    );
}