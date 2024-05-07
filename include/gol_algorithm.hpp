#include <vector>


struct Cell {
    bool currentState;
    bool nextState;
}
typedef Cell Cell;

std::vector<std::vector<Cell>> matrix;

getNeighborsCount(int y, int x, <std::vector<std::vector<Cell>> matrix);
willBeBorn(bool cellCurrentState, int neighborsCount);
willDie(int neighborsCount);
setNewStates(std::vector<std::vector<Cell>>& matrix);

setCurrentStates(std::vector<std::vector<Cell>>& matrix);