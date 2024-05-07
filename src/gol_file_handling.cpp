#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>
#include "gol_elements.hpp"


void saveGrid(
    std::string fileName, std::vector<std::vector<struct Cell>> matrix
) {
    std::string textFileContent = "!" + fileName + "\n";
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix.size(); x++) {
            switch (matrix[y][x].currentState) {
                case 0: textFileContent += '.'; break;
                case 1: textFileContent += 'O'; break;
            };
        };
        textFileContent += '\n';
    };

    std::ofstream file(fileName + ".cells");
    file << textFileContent;
    file.close();
}

std::string readGridFile(std::string fileName) {
    std::stringstream fileContent;
    std::string line;
    int lastLineLength = -1;

    std::ifstream file(fileName + ".cells");
    /*
    if (!file.is_open()) {
        fileName + ".cells " + "does not exist";
    }
    */

    while (getline (file, line)) {
        if (line[0] == '!') {
            continue;
        }
        /*
        if ((line.length() != lastLineLength) && (lastLineLength != -1)) {
            throw (std::string) "Uneven line lengths";
        }
        for (int i; i < line.size(); i++) {
            if ((line[i] != '.') || (line[i] != 'O')) {
                throw (std::string) "Invalid character";
            }
        }
        */
        fileContent << line << '\n';
        lastLineLength = line.length();
    };

    return fileContent.str();
}