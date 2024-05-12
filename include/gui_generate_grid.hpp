#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"


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
);

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
);