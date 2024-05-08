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
            switch (grid[y][x].currentState) {
                case 0:
                    std::cout << ". ";
                    break;
                case 1:
                    std::cout << "O ";
                    break;
            };
        };
        std::cout << '\n';
    };
}

void displayGridPrompt() {
    std::cout
        << "1) Forwards   2) Save   3) Quit\n"
        << ">> ";
}