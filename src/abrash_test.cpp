#include <iostream>
#include <bitset>
#include "abrash_elements.hpp"
#include "abrash_algorithm.hpp"

void display(std::vector<std::vector<unsigned char>> grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            switch (getCellState(grid[y][x])) {
                case 0: std::cout << ". "; break;
                case 1: std::cout << "O "; break;
            };
        };
        std::cout << '\n';
    };
};

void displayBits(std::vector<std::vector<unsigned char>> grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            std::bitset<8> binary(grid[y][x]);
            switch (getCellState(grid[y][x])) {
                case 0:
                    std::cout << binary << ' ';
                    break;
                case 1:
                    std::cout << binary << ' ';
                    break;
            };
        };
        std::cout << '\n';
    };
};


int main() {
    std::vector<std::vector<unsigned char>> currentGrid (
        16, std::vector<unsigned char> (16, 0)
    );
    std::vector<std::vector<unsigned char>> nextGrid (
        16, std::vector<unsigned char> (16, 0)
    );
    setCellAlive(nextGrid[0][2]);
    addNeighborCountToNeighbors(nextGrid, 0, 2);
    setCellAlive(nextGrid[1][0]);
    addNeighborCountToNeighbors(nextGrid, 1, 0);
    setCellAlive(nextGrid[1][2]);
    addNeighborCountToNeighbors(nextGrid, 1, 2);
    setCellAlive(nextGrid[2][1]);
    addNeighborCountToNeighbors(nextGrid, 2, 1);
    setCellAlive(nextGrid[2][2]);
    addNeighborCountToNeighbors(nextGrid, 2, 2);
    currentGrid = nextGrid;

    for (int i = 0; i < 8; i++) {
        iterateOverGrid(currentGrid, nextGrid);
        displayBits(currentGrid);
        std::cout << '\n';
    };

    return 0;
}