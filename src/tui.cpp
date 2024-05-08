#include <iostream>
#include <string>
#include "gol_elements.hpp"


void displayMainMenu() {
    std::cout
        << "GAME OF LIFE:\n"
        << "1) Generate random grid\n"
        << "2) Load grid\n"
        << "3) Quit\n"
        << ">> ";
}

void displayGenerateGridPrompt() {
    std::cout
        << "First, input the grid's height as an integer\n"
        << "Then, input the grid's width as an integer\n"
        << "Lastly, input the density of the generated grid as fraction "
           "between 0 and 1\n";
}

void displayGrid(std::vector<std::vector<struct Cell>> grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            std::cout << grid[y][x].currentState << ' ';
        };
        std::cout << '\n';
    };
};