#include <vector>
#include "gol_elements.hpp"


void setCellAlive(unsigned char& cell) {
    cell |= 0x01;
}
void setCellDead(unsigned char& cell) {
    cell &= 0xFE;
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
    std::vector<std::vector<unsigned char>>& nextGrid,
    unsigned int originY,
    unsigned int originX
) {
    for (int y = -1; y <= 1; y++) {
        if (originY + y < 0 || originY + y >= nextGrid.size()) continue;
        for (int x = -1; x <= 1; x++) {
            if (originX + x < 0 || originX +x >= nextGrid[originY + y].size()) {
                continue;
            };
            if (y == 0 && x == 0) continue;
            addNeighborCount(nextGrid[originY + y][originX + x]);
        };
    };
}

void subNeighborCountToNeighbors(
    std::vector<std::vector<unsigned char>>& nextGrid,
    unsigned int originY,
    unsigned int originX
) {
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

void iterateOverGrid(
    std::vector<std::vector<unsigned char>>& currentGrid,
    std::vector<std::vector<unsigned char>>& nextGrid
) {
    for (int y = 0; y < currentGrid.size(); y++) {
        for (int x = 0; x < currentGrid[y].size(); x++) {
            if (currentGrid[y][x] == 0) continue;

            unsigned char cellState = getCellState(currentGrid[y][x]);
            unsigned char neighborCount ;
            neighborCount = getNeighborCount(currentGrid[y][x]);

            if (
                (neighborCount < 2 || neighborCount > 3) && cellState == 1
            ) {
                setCellDead(nextGrid[y][x]);
                subNeighborCountToNeighbors(nextGrid, y, x);
            } else if (neighborCount == 3 && cellState == 0) {
                setCellAlive(nextGrid[y][x]);
                addNeighborCountToNeighbors(nextGrid, y, x);
            };
        };
    };
    currentGrid = nextGrid;
}