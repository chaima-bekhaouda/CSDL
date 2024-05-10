#include <vector>
#include "abrash_elements.hpp"


void setCellAlive(unsigned char& cell) {
    cell += 0x01;
}
void setCellDead(unsigned char& cell) {
    cell -= 0x01;
}
bool getCellState(unsigned char& cell) {
    return cell & 1;
}

void addNeighborCount(unsigned char& cell) {
    cell += 0x02;
}
void subNeighborCount(unsigned char& cell) {
    cell -= 0x02;
}
unsigned char getNeighborCount(unsigned char& cell) {
    return cell >> 1;
}

void addNeighborCountToNeighbors(
    struct Grid& grid,
    unsigned int originY,
    unsigned int originX
) {
    for (int y = -1; y <= 1; y++) {
        if (originY + y < 0 || originY + y >= grid.currentGrid.size()) continue;
        for (int x = -1; x <= 1; x++) {
            if (originX + x < 0 || originX +x >= grid.currentGrid[y].size()) {
                continue;
            };
            if (y == 0 && x == 0) continue;
            addNeighborCount(grid.nextGrid[y][x]);
        };
    };
}

void subNeighborCountToNeighbors(
    struct Grid& grid,
    unsigned int originY,
    unsigned int originX
) {
    for (int y = -1; y <= 1; y++) {
        if (originY + y < 0 || originY + y >= grid.currentGrid.size()) continue;
        for (int x = -1; x <= 1; x++) {
            if (originX + x < 0 || originX +x >= grid.currentGrid[y].size()) {
                continue;
            };
            if (y == 0 && x == 0) continue;
            subNeighborCount(grid.nextGrid[y][x]);
        };
    };
}

void iterateOverGrid(struct Grid& grid) {
    for (int y = 0; y < grid.currentGrid.size(); y++) {
        for (int x = 0; x < grid.currentGrid[y].size(); x++) {
            if (grid.currentGrid[y][x] == 0) continue;

            unsigned char cellState = getCellState(grid.currentGrid[y][x]);
            unsigned char neighborCount ;
            neighborCount = getNeighborCount(grid.currentGrid[y][x]);

            if (
                (neighborCount > 2 || neighborCount < 3) && cellState == 1
            ) {
                setCellDead(grid.nextGrid[y][x]);
                subNeighborCountToNeighbors(grid, y, x);
            } else if (
                (2 <= neighborCount && neighborCount <= 3) && cellState == 0
            ) {
                setCellAlive(grid.nextGrid[y][x]);
                addNeighborCountToNeighbors(grid, y, x);
            };
        };
    };
}