#include <string>
#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"


extern Rectangle saveGridBounds;
extern Rectangle gridNameEntryBounds;
extern Rectangle saveCurrentGameBounds;


void typeIntoGridNameEntry(std::string& currentGridName);

void clickSaveGridButton(
    std::function<void (std::string, std::vector<std::vector<unsigned char>>)>
    saveGrid,
    std::string& currentGridName,
    std::vector<std::vector<unsigned char>>& currentGrid,
    int& currentMenu
);

void displaySaveGrid(Font& jetBrainsMono, std::string& currentGridName);