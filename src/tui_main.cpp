#include <iostream>
#include <string>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"
#include "gol_grid_generation.hpp"
#include "tui.hpp"


int main() {
    std::vector<std::vector<struct Cell>> grid;
    int userMainMenuInput;
    do {
        displayMainMenu();
        std::cin >> userMainMenuInput;
        switch (userMainMenuInput) {
            case 1:
                displayGenerateGridPrompt();
                int gridHeight;
                std::cin >> gridHeight;
                int gridWidth;
                std::cin >> gridWidth;
                double densityFraction;
                std::cin >> densityFraction;
                grid = generateGrid(gridHeight, gridWidth, densityFraction);
                displayGrid(grid);
                break;
            case 2:
                break;
        };
    } while (userMainMenuInput != 3);

    return 0;
}