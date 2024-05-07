#include <fstream>
#include <string>
#include <vector>
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