#include <iostream>
#include <string>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"
#include "gol_grid_generation.hpp"


int main() {
    std::vector<std::vector<struct Cell>> matrix = generateGrid(10, 10, 0.5);

    int totalEmpty = 0;
    int totalFilled = 0;
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix[y].size(); x++) {
            std::cout << matrix[y][x].currentState << ' ';
            switch (matrix[y][x].currentState) {
                case 0: totalEmpty++; break;
                case 1: totalFilled++; break;
            };
        };
        std::cout << '\n';
    };

    std::cout << totalEmpty << ' ' << totalFilled << std::endl;

    return 0;
}