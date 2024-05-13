#include <string>
#include "raylib.h"
#include "gui_colors.hpp"


extern Rectangle saveGridBounds;
extern Rectangle gridNameEntryBounds;
extern Rectangle saveCurrentGameBounds;


void typeIntoGridNameEntry(std::string& currentGridName);

void displaySaveGrid(Font& jetBrainsMono, std::string& currentGridName);