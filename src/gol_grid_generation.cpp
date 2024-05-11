#include <random>
#include <ctime>
#include <vector>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"


std::vector<std::vector<unsigned char>> generateGrid(
    int gridY, int gridX, double densityFraction
) {
    srand(time(0));

    int numberOfCells = gridY * gridX;
    int maxFilledCells = numberOfCells * densityFraction;


    int i = 0;
    if (densityFraction < 50) {
        std::vector<std::vector<unsigned char>> grid (
            gridY, std::vector<unsigned char> (gridX, 0)
        );
        while (i != maxFilledCells) {
            int randomY = rand() % gridY;
            int randomX = rand() % gridX;

            if (getCellState(grid[randomY][randomX]) == 1) {
                continue;
            };

            setCellAlive(grid[randomY][randomX]);
            addNeighborCountToNeighbors(grid, randomY, randomX);
            i++;
        };

        return grid;
    } else {
        std::vector<std::vector<unsigned char>> grid (
            gridY, std::vector<unsigned char> (gridX, 1)
        );

        while (i != maxFilledCells) {
            int randomY = rand() % gridY;
            int randomX = rand() % gridX;

            if (getCellState(grid[randomY][randomX]) == 0) {
                continue;
            };

            setCellDead(grid[randomY][randomX]);
            subNeighborCountToNeighbors(grid, randomY, randomX);
            i++;
        };
    };
}