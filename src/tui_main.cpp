#include <iostream>
#include <string>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"
#include "gol_grid_generation.hpp"
#include "tui.hpp"


int main() {
    std::vector<std::vector<struct Cell>> grid = generateGrid(10, 10, 0.5);

    displayGrid(grid);

    return 0;
}