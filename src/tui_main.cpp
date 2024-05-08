#include <iostream>
#include <string>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"
#include "gol_grid_generation.hpp"
#include "tui.hpp"


void gridMenu(std::vector<std::vector<struct Cell>>& grid) {
    int userGridMenuInput;
    do {
        displayGrid(grid);
        displayGridPrompt();
        std::cin >> userGridMenuInput;
        switch (userGridMenuInput) {
            case 1:
                setNextStates(grid);
                setCurrentStates(grid);
                break;
            case 2:
                break;
        };
    } while (userGridMenuInput != 3);
}

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
                gridMenu(grid);
                break;
            case 2:
                displayLoadGridPrompt();

                std::string fileName;
                std::cin >> fileName;

                if (!doesFileExist(fileName)) {
                    std::cout << "File does not exist\n";
                    break;
                };

                std::string fileContent = readGridFile(fileName);
                grid = loadGrid(fileContent);
                gridMenu(grid);
                break;
        };
    } while (userMainMenuInput != 3);

    return 0;
}