#include <vector>


struct Cell {
    bool currentState;
    bool nextState;
}
typedef Cell Cell;

std::vector<std::vector<Cell>> matrix;

int getNeighborsCount(int y, int x, <std::vector<std::vector<Cell>> matrix);
bool willBeBorn(bool cellCurrentState, int neighborsCount);
bool willDie(int neighborsCount);
void setNextStates(std::vector<std::vector<Cell>>& matrix);

void setCurrentStates(std::vector<std::vector<Cell>>& matrix);