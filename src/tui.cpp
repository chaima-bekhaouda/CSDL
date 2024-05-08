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

void displayMainMenu() {
    std::cout
        << "GAME OF LIFE:\n"
        << "1) Charger une population\n"
        << "2) Generer une population aleatoirement\n"
        << "3) Quitter\n"
        << "Choix: ";
}