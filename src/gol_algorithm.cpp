#include <vector>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"


int getNeighborsCount(int y, int x, std::vector<std::vector<struct Cell>> grid) {
    int neighborsCount = 0;
    for (int _y = -1; _y <= 1; _y++) {
        for (int _x = -1; _x <= 1; _x++) {
            // Skip if origin cell
            if (_y == 0 && _x == 0) {
                continue;
            };
            // Check if out of bounds
            if (
                (y + _y < 0 || y + _y >= grid.size()) ||
                (x + _x < 0 || x + _x >= grid.size()) 
            ) {
                continue;
            };
            // If cell is alive
            if (grid[y + _y][x + _x].currentState == 1) {
                neighborsCount += 1;
            }
        };
    };

    return neighborsCount;
}

bool willBeBorn(bool cellCurrentState, int neighborsCount) {
    return (cellCurrentState == 0 && neighborsCount == 3);
}

bool willDie(int neighborsCount) {
    return !(2 <= neighborsCount && neighborsCount <= 3);
}

void setNextStates(std::vector<std::vector<struct Cell>>& grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            int neighborsCount = getNeighborsCount(y, x, grid);
            if (willBeBorn(grid[y][x].currentState, neighborsCount)) {
                grid[y][x].nextState = 1;
            } else if (
                !(willDie(neighborsCount))
            ) {
                grid[y][x].nextState = 0;
            } else {
                grid[y][x].nextState = grid[y][x].currentState;
            };
        };
    };
}


void setCurrentStates(std::vector<std::vector<struct Cell>>& grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            grid[y][x].currentState = grid[y][x].nextState;
        };
    };
}