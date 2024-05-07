#include <iostream>
#include <string>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"


int main() {
    std::string gridString = readGridFile("default");
    std::vector<std::vector<struct Cell>> matrix = loadGrid(gridString);

    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix[y].size(); x++) {
            std::cout << matrix[y][x].currentState << ' ';
        };
        std::cout << '\n';
    };

    return 0;
}