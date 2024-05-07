#include <string>
#include <vector>
#include "gol_elements.hpp"


void saveGrid(
    std::string fileName, std::vector<std::vector<struct Cell>> matrix
);

std::string readGridFile(std::string fileName);

std::vector<std::vector<struct Cell>> loadGrid(std::string gridString);