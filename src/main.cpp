#include <iostream>
#include <vector>
#include <fstream> // TEMPORARY !!!!
#include "gol_algorithm.hpp"


int main() {
    /*
    std::vector<std::vector<Cell>> matrix({
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}
    });
    std::string textFileContent = "!default.cells\n";
    for (int y = 0; y < matrix.size(); y++) {
        for (int x = 0; x < matrix.size(); x++) {
            switch (matrix[y][x].currentState) {
                case 0: textFileContent += '.'; break;
                case 1: textFileContent += 'O'; break;
            };
        };
        textFileContent += '\n';
    };
    std::cout << textFileContent << std::endl;

    std::ofstream file("default.cells");
    file << textFileContent;
    file.close();
    */
    std::string line;
    std::ifstream file("default.cells");
    while (getline (file, line)) {
        if (line[0] == '!') {
            continue;
        }
        std::cout << line << ' ' << line.length() << '\n';
    };
    file.close();
    return 0;
}