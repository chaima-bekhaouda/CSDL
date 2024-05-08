#include <string>
#include <vector>
#include "gol_elements.hpp"


bool doesFileExist(std::string fileName);

void saveGrid(
    std::string fileName, std::vector<std::vector<struct Cell>> grid
);

std::string readGridFile(std::string fileName);

std::vector<std::vector<struct Cell>> loadGrid(std::string gridString);