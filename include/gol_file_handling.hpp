#include <string>
#include <vector>
#include "gol_elements.hpp"

bool doesFileExist(std::string fileName);
bool areLinesEven(std::string fileName);
bool areCharactersValid(std::string fileName);

void saveGrid(
    std::string fileName, std::vector<std::vector<unsigned char>> grid
);

std::string readGridFile(std::string fileName);

std::vector<std::vector<unsigned char>> loadGrid(std::string gridString);