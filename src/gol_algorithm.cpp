#include <vector>
#include "gol_elements.hpp"

// Sets the least significant bit of the cell to 1, indicating it's alive
void setCellAlive(unsigned char& cell) {
    cell |= 0x01;
}

// Sets the least significant bit of the cell to 0, indicating it's dead
void setCellDead(unsigned char& cell) {
    cell &= 0xFE;
}

// Returns the state of the cell (alive or dead)
bool getCellState(unsigned char& cell) {
    return cell & 1;
}

// Increases the neighbor count of the cell by 1
void addNeighborCount(unsigned char& cell) {
    cell += 0x02;
}

// Decreases the neighbor count of the cell by 1
void subNeighborCount(unsigned char& cell) {
    cell -= 0x02;
}

// Returns the neighbor count of the cell
unsigned char getNeighborCount(unsigned char& cell) {
    return cell >> 1;
}

// Increases the neighbor count of the cells surrounding the given cell
void addNeighborCountToNeighbors(
        std::vector<std::vector<unsigned char>>& nextGrid,
        unsigned int originY,
        unsigned int originX
) {
    // Iterate over the 3x3 grid centered on the cell
    for (int y = -1; y <= 1; y++) {
        if (originY + y < 0 || originY + y >= nextGrid.size()) continue;
        for (int x = -1; x <= 1; x++) {
            if (originX + x < 0 || originX +x >= nextGrid[originY + y].size()) {
                continue;
            };
            if (y == 0 && x == 0) continue; // Skip the center cell
            addNeighborCount(nextGrid[originY + y][originX + x]);
        };
    };
}

// Decreases the neighbor count of the cells surrounding the given cell
void subNeighborCountToNeighbors(
        std::vector<std::vector<unsigned char>>& nextGrid,
        unsigned int originY,
        unsigned int originX
) {
    // Similar to addNeighborCountToNeighbors, but decreases the count
    for (int y = -1; y <= 1; y++) {
        if (originY + y < 0 || originY + y >= nextGrid.size()) continue;
        for (int x = -1; x <= 1; x++) {
            if (originX + x < 0 || originX +x >= nextGrid[originY + y].size()) {
                continue;
            };
            if (y == 0 && x == 0) continue;
            subNeighborCount(nextGrid[originY + y][originX + x]);
        };
    };
}

// Iterates over the grid to update the state of each cell for the next generation
void iterateOverGrid(
        std::vector<std::vector<unsigned char>>& currentGrid,
        std::vector<std::vector<unsigned char>>& nextGrid
) {
    // Iterate over each cell in the grid
    for (int y = 0; y < currentGrid.size(); y++) {
        for (int x = 0; x < currentGrid[y].size(); x++) {
            if (currentGrid[y][x] == 0) continue;

            unsigned char cellState = getCellState(currentGrid[y][x]);
            unsigned char neighborCount ;
            neighborCount = getNeighborCount(currentGrid[y][x]);

            // If the cell is alive and has less than 2 or more than 3 neighbors, it dies
            if ((neighborCount < 2 || neighborCount > 3) && cellState == 1) {
                setCellDead(nextGrid[y][x]);
                subNeighborCountToNeighbors(nextGrid, y, x);
            }
                // If the cell is dead and has exactly 3 neighbors, it becomes alive
            else if (neighborCount == 3 && cellState == 0) {
                setCellAlive(nextGrid[y][x]);
                addNeighborCountToNeighbors(nextGrid, y, x);
            };
        };
    };
    // The next grid becomes the current grid for the next iteration
    currentGrid = nextGrid;
}