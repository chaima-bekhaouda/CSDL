#include <string>
#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"

#define MAX_GRID_NAME_SIZE 24 // Define the maximum size of the grid name

// Define the bounds for the save grid, name entry and button
Rectangle saveGridBounds = {344, 229.8, 336, 258.4};
Rectangle gridNameEntryBounds = {365.6, 302.4, 292.3, 44.1};
Rectangle saveCurrentGameBounds = {404.2, 387.8, 216, 44.1};

// Function to handle typing into the grid name entry
void typeIntoGridNameEntry(std::string& currentGridName) {
    // If the backspace key is pressed and the current grid name is not empty, remove the last character
    if (IsKeyPressed(KEY_BACKSPACE) && currentGridName.size() != 0) {
        currentGridName.pop_back();
        return;
    };

    // If the current grid name is at the maximum size, do nothing
    if (currentGridName.size() >= MAX_GRID_NAME_SIZE) {
        return;
    };

    // Get the character that was pressed
    char pressedChar = GetCharPressed();
    // If no character was pressed, do nothing
    if (pressedChar == 0) {
        return;
    };

    // Add the pressed character to the current grid name
    currentGridName.push_back(pressedChar);
}

// Function to handle clicking the save grid button
void clickSaveGridButton(
        std::function<void (std::string, std::vector<std::vector<unsigned char>>)> saveGrid,
        std::string& currentGridName,
        std::vector<std::vector<unsigned char>>& currentGrid,
        int& currentMenu
) {
    // Save the current grid with the current grid name
    saveGrid(currentGridName, currentGrid);
    // Close the menu
    currentMenu = -1;
    // Clear the current grid name
    currentGridName = "";
}

// Function to display the save grid
void displaySaveGrid(Font& jetBrainsMono, std::string& currentGridName) {
    // Draw the save grid background
    DrawRectangleRec(saveGridBounds, MIDNIGHTBLACK);
    // Draw the save grid border
    DrawRectangleLinesEx(saveGridBounds, 4, DEEPOCEANBLUE);
    // Draw the grid name label
    DrawTextEx(
            jetBrainsMono, "Grid name", Vector2 {465.4, 266.6}, 26, 0, MINTYTEAL
    );
    // Draw the grid name entry box
    DrawRectangleRounded(gridNameEntryBounds, 33, 10, MINTYTEAL);
    // If the current grid name is empty, draw placeholder text
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
        // Otherwise, draw the current grid name
        DrawTextEx(
                jetBrainsMono,
                currentGridName.c_str(),
                Vector2 {380, 312},
                26,
                0,
                MIDNIGHTBLACK
        );
    }
    // Draw the save button
    DrawRectangleRounded(saveCurrentGameBounds, 33, 10, MINTYTEAL);
    // Draw the save button label
    DrawTextEx(
            jetBrainsMono,
            "Save current game",
            Vector2 {420, 397},
            26,
            0,
            MIDNIGHTBLACK
    );
}