#include "abrash_elements.hpp"


void setCellAlive(unsigned char& cell);
void setCellDead(unsigned char& cell);
bool getCellState(unsigned char& cell);

void addNeighborCount(unsigned char& cell);
void subNeighborCount(unsigned char& cell);
unsigned char getNeighborCount(unsigned char cell);