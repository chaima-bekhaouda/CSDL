#include "abrash_elements.hpp"


void setCellAlive(unsigned char& cell) {
    cell += 0x01;
}
void setCellDead(unsigned char& cell) {
    cell -= 0x01;
}
bool getCellState(unsigned char cell) {
    return cell & 1;
}

void addNeighborCount(unsigned char& cell) {
    cell += 0x02;
}
void subNeighborCount(unsigned char& cell) {
    cell -= 0x02
}
unsigned char getNeighborCount(unsigned char cell) {
    return cell >> 1;
}