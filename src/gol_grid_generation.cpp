=// Including the necessary libraries and headers
#include <random> // For generating random numbers
#include <ctime> // For getting the current time
#include <vector> // For using vector data structure
#include "gol_elements.hpp" // Game of Life elements header
#include "gol_algorithm.hpp" // Game of Life algorithm header

// Function to generate a grid for the Game of Life
std::vector<std::vector<unsigned char>> generateGrid(
        int gridY, int gridX, double densityFraction
) {
    srand(time(0)); // Seed the random number generator with the current time

    int numberOfCells = gridY * gridX; // Total number of cells in the grid
    int maxFilledCells = numberOfCells * densityFraction; // Maximum number of filled cells based on the density fraction

    int i = 0;
    if (densityFraction < 50) {
        // Initialize the grid with all cells dead if the density fraction is less than 50
        std::vector<std::vector<unsigned char>> grid (
                gridY, std::vector<unsigned char> (gridX, 0)
        );
        while (i != maxFilledCells) {
            int randomY = rand() % gridY; // Generate a random Y coordinate
            int randomX = rand() % gridX; // Generate a random X coordinate

            // If the cell is already alive, skip to the next iteration
            if (getCellState(grid[randomY][randomX]) == 1) {
                continue;
            };

            // Set the cell to alive and increment the neighbor count of its neighbors
            setCellAlive(grid[randomY][randomX]);
            addNeighborCountToNeighbors(grid, randomY, randomX);
            i++;
        };

        return grid;
    } else {
        // Initialize the grid with all cells alive if the density fraction is 50 or more
        std::vector<std::vector<unsigned char>> grid (
                gridY, std::vector<unsigned char> (gridX, 1)
        );

        while (i != maxFilledCells) {
            int randomY = rand() % gridY; // Generate a random Y coordinate
            int randomX = rand() % gridX; // Generate a random X coordinate

            // If the cell is already dead, skip to the next iteration
            if (getCellState(grid[randomY][randomX]) == 0) {
                continue;
            };

            // Set the cell to dead and decrement the neighbor count of its neighbors
            setCellDead(grid[randomY][randomX]);
            subNeighborCountToNeighbors(grid, randomY, randomX);
            i++;
        };
    };
}