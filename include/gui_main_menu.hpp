#include <iostream>
#include <cmath>
#include "raylib.h"
#include "gui_colors.hpp"


void clickMainMenuGenerateNewGrid(
    int& currentWidth,
    int& widthDigits,
    int& currentHeight,
    int& heightDigits,
    int& currentDensity,
    int& currentMenu
);

void clickMainMenuLoadGrid();

void clickMainMenuSaveGrid();

void renderMainMenu(
    Rectangle& mainMenuBounds,
    Rectangle& mainMenuGenerateNewGridBounds,
    Rectangle& mainMenuLoadGridBounds,
    Rectangle& mainMenuSaveGridBounds,
    Font& jetBrainsMono
);