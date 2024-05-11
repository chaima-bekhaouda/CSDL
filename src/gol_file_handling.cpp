#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>
#include "gol_elements.hpp"


/*
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
    std::string fileName, std::vector<std::vector<struct Cell>> grid
) {
    std::string textFileContent = "!" + fileName + "\n";
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid.size(); x++) {
            switch (grid[y][x].currentState) {
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

std::vector<std::vector<struct Cell>> loadGrid(std::string gridString) {
    std::vector<std::vector<struct Cell>> grid;
    grid.emplace_back();

    int y = 0;
    for (int i = 0; i < gridString.size(); i++) {
        switch (gridString[i]) {
            case '.': grid[y].emplace_back(Cell{0, 0}); break;
            case 'O': grid[y].emplace_back(Cell{1, 0}); break;
            case '\n': y++; grid.emplace_back(); break;
        };
    };
    if (grid[grid.size() - 1].size() == 0) {
        grid.pop_back();
    };

    return grid;
}
*/