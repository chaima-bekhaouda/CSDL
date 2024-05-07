#include <vector>
#include "gol_elements.hpp"


int getNeighborsCount(
    int y, int x, std::vector<std::vector<struct Cell>> matrix
);
bool willBeBorn(bool cellCurrentState, int neighborsCount);
bool willDie(int neighborsCount);
void setNextStates(std::vector<std::vector<struct Cell>>& matrix);

void setCurrentStates(std::vector<std::vector<struct Cell>>& matrix);