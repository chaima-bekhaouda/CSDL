#include <string>
#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"


extern Rectangle loadGridBounds;
extern Rectangle loadGridNameEntryBounds;
extern Rectangle loadGridButtonBounds;


void typeIntoLoadGridNameEntry(std::string& currentGridName);

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
);

void displayLoadGrid(Font& jetBrainsMono, std::string& currentGridName);