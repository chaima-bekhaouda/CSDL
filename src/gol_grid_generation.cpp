#include <random>
#include <ctime>
#include <vector>
#include "gol_elements.hpp"


std::vector<std::vector<Cell>> generateGrid(
    int matrixY, int matrixX, double densityFraction
) {
    srand(time(0));

    int numberOfCells = matrixY * matrixX;
    int maxFilledCells = numberOfCells * densityFraction;

    std::vector<std::vector<Cell>> matrix (
        matrixY, std::vector<Cell> (matrixX, {0, 0})
    );

    int i = 0;
    while (i != maxFilledCells) {
        int randomY = rand() % matrixY;
        int randomX = rand() % matrixX;

        if (matrix[randomY][randomX].currentState == 1) {
            continue;
        }

        matrix[randomY][randomX].currentState = 1;
        i++;
    };

    return matrix;
}