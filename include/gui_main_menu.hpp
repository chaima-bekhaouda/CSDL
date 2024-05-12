#include <iostream>
#include <cmath>
#include "raylib.h"
#include "gui_colors.hpp"


extern Rectangle mainMenuBounds;
extern Rectangle mainMenuGenerateNewGridBounds;
extern Rectangle mainMenuLoadGridBounds;
extern Rectangle mainMenuSaveGridBounds;


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
    Font& jetBrainsMono
);