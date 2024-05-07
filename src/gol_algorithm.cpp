#include <vector>
#include "gol_algorithm.hpp"


getNeighborsCount(int y, int x, std::vector<std::vector<Cell>> matrix) {
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
                neighbors += 1;
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