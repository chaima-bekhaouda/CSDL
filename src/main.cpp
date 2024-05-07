#include <iostream>
#include <vector>
#include "gol_algorithm.hpp"


int main() {
    matrix = std::vector<std::vector<Cell>> {
        {{0, 0}, {0, 0}, {1, 0}},
        {{1, 0}, {0, 0}, {1, 0}},
        {{0, 0}, {1, 0}, {1, 0}}
    };
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix.size(); x++) {
            std::cout << matrix[y][x].currentState << " ";
        };
        std::cout << std::endl;
    };
    return 0;
}