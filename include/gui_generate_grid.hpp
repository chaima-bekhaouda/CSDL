#include <vector>
#include <functional>
#include "raylib.h"
#include "gui_colors.hpp"


extern Rectangle generateNewGridBounds;
extern Rectangle widthEntryBounds;
extern Rectangle heightEntryBounds;
extern Rectangle densityEntryBounds;
extern Rectangle createNewGridBounds;


void typingInWidthEntry(int& widthDigits, int& currentWidth);

void typingInHeightEntry(int& heightDigits, int& currentHeight);

void typingInDensityEntry(int& currentDensity);

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