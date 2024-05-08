#include <vector>
#include "gol_elements.hpp"


int getNeighborsCount(
    int y, int x, std::vector<std::vector<struct Cell>> grid
);
bool willBeBorn(bool cellCurrentState, int neighborsCount);
bool willDie(int neighborsCount);
void setNextStates(std::vector<std::vector<struct Cell>>& grid);

void setCurrentStates(std::vector<std::vector<struct Cell>>& grid);