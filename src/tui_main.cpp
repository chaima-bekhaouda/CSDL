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
        switch (userMainMenuInput) {
            case 1:
                break;
            case 2:
                break;
        }
        std::cin >> userMainMenuInput;
    } while (userMainMenuInput != 3);

    return 0;
}