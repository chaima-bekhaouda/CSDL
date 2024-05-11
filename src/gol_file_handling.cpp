#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"


bool doesFileExist(std::string fileName) {
    bool fileExists;

    std::ifstream file("cells/" + fileName + ".cells");
    fileExists = file.is_open();
    file.close();

    return fileExists;
}

bool areLinesEven(std::string fileName) {
    int lastLineLength = - 1;
    std::string line;

    std::ifstream file("cells/" + fileName + ".cells");
    while (getline(file, line)) {
        if (line[0] == '!') {
            continue;
        };
        if ((line.length() != lastLineLength) && (lastLineLength != -1)) {
            return false;
        };
        lastLineLength = line.length();
    };
    file.close();

    return true;
}

bool areCharactersValid(std::string fileName) {
    std::string line;

    std::ifstream file("cells/" + fileName + ".cells");
    while (getline(file, line)) {
        if (line[0] == '!') {
            continue;
        };
        for (char character : line) {
            if ((character != '.') && (character != 'O')) {
                return false;
            };
        };
    };
    file.close();

    return true;
}

void saveGrid(
    std::string fileName, std::vector<std::vector<unsigned char>> grid
) {
    std::string textFileContent = "!" + fileName + "\n";
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid.size(); x++) {
            switch (getCellState(grid[y][x])) {
                case 0: textFileContent += '.'; break;
                case 1: textFileContent += 'O'; break;
            };
        };
        textFileContent += '\n';
    };

    std::ofstream file("cells/" + fileName + ".cells");
    file << textFileContent;
    file.close();
}

std::string readGridFile(std::string fileName) {
    std::stringstream fileContent;
    std::string line;
    int lastLineLength = -1;

    std::ifstream file("cells/" + fileName);

    while (getline(file, line)) {
        if (line[0] == '!') {
            continue;
        }
        fileContent << line << '\n';
        lastLineLength = line.length();
    };

    return fileContent.str();
}

std::vector<std::vector<unsigned char>> loadGrid(std::string gridString) {
    std::stringstream dimensionsStringStream (gridString);
    std::string line;

    int gridRows = 1;
    int gridColumns = 0;
    while (std::getline(dimensionsStringStream, line)) {
        if (gridColumns == 0) {
            for (char c : line) {
                gridColumns++;
            }
        }
        gridRows++;
    };

    std::vector<std::vector<unsigned char>> grid (
        gridRows, std::vector<unsigned char> (gridColumns, 0)
    );

    std::stringstream insertStringStream (gridString);
    int y = 0;
    int x;
    while (std::getline(insertStringStream, line)) {
        x = 0;
        for (char c : line) {
            if (c == 'O') {
                setCellAlive(grid[y][x]);
                addNeighborCountToNeighbors(grid, y, x);
            };
            x++;
        };
        y++;
    };

    return grid;
}