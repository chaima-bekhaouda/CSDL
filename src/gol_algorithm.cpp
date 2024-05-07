#include <vector>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"


int getNeighborsCount(int y, int x, std::vector<std::vector<struct Cell>> matrix) {
    int neighborsCount = 0;
    for (int _y = -1; _y <= 1; _y++) {
        for (int _x = -1; _x <= 1; _x++) {
            // Skip if origin cell
            if (_y == 0 && _x == 0) {
                continue;
            };
            // Check if out of bounds
            if (
                (y + _y < 0 || y + _y >= matrix.size()) ||
                (x + _x < 0 || x + _x >= matrix.size()) 
            ) {
                continue;
            };
            // If cell is alive
            if (matrix[y + _y][x + _x].currentState == 1) {
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

void setNextStates(std::vector<std::vector<struct Cell>>& matrix) {
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix[y].size(); x++) {
            int neighborsCount = getNeighborsCount(y, x, matrix);
            if (willBeBorn(matrix[y][x].currentState, neighborsCount)) {
                matrix[y][x].nextState = 1;
            } else if (
                !(willDie(neighborsCount))
            ) {
                matrix[y][x].nextState = 0;
            } else {
                matrix[y][x].nextState = matrix[y][x].currentState;
            };
        };
    };
}


void setCurrentStates(std::vector<std::vector<struct Cell>>& matrix) {
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix[y].size(); x++) {
            matrix[y][x].currentState = matrix[y][x].nextState;
        };
    };
}