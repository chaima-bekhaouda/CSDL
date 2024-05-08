#include <random>
#include <ctime>
#include <vector>
#include "gol_elements.hpp"


std::vector<std::vector<struct Cell>> generateGrid(
    int gridY, int gridX, double densityFraction
) {
    srand(time(0));

    int numberOfCells = gridY * gridX;
    int maxFilledCells = numberOfCells * densityFraction;

    std::vector<std::vector<struct Cell>> grid (
        gridY, std::vector<struct Cell> (gridX, {0, 0})
    );

    int i = 0;
    while (i != maxFilledCells) {
        int randomY = rand() % gridY;
        int randomX = rand() % gridX;

        if (grid[randomY][randomX].currentState == 1) {
            continue;
        }

        grid[randomY][randomX].currentState = 1;
        i++;
    };

    return grid;
}