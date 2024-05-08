#include <iostream>
#include <string>
#include "gol_elements.hpp"


void displayGrid(std::vector<std::vector<Cell>> grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            std::cout << grid[y][x].currentState << ' ';
        };
        std::cout << '\n';
    };
};