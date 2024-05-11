#include <vector>
#include "gol_elements.hpp"


void setCellAlive(unsigned char& cell);
void setCellDead(unsigned char& cell);
bool getCellState(unsigned char& cell);

void addNeighborCount(unsigned char& cell);
void subNeighborCount(unsigned char& cell);
unsigned char getNeighborCount(unsigned char cell);

void addNeighborCountToNeighbors(
    std::vector<std::vector<unsigned char>>& nextGrid,
    unsigned int originY,
    unsigned int originX
);
void subNeighborCountToNeighbors(
    std::vector<std::vector<unsigned char>>& nextGrid,
    unsigned int originY,
    unsigned int originX
);

void iterateOverGrid(
    std::vector<std::vector<unsigned char>>& currentGrid,
    std::vector<std::vector<unsigned char>>& nextGrid
);