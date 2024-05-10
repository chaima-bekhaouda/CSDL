#include <vector>
#include "abrash_elements.hpp"


void setCellAlive(unsigned char& cell);
void setCellDead(unsigned char& cell);
bool getCellState(unsigned char& cell);

void addNeighborCount(unsigned char& cell);
void subNeighborCount(unsigned char& cell);
unsigned char getNeighborCount(unsigned char cell);

void addNeighborCountToNeighbors(
    struct Grid& grid,
    unsigned int originY,
    unsigned int originX
);
void subNeighborCountToNeighbors(
    struct Grid& grid,
    unsigned int originY,
    unsigned int originX
);

void iterateOverGrid(struct Grid& grid);