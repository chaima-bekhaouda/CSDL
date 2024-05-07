#include <iostream>
#include <string>
#include <vector>
#include <fstream> // TEMPORARY !!!!
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"


int main() {
    /*
    std::vector<std::vector<struct Cell>> matrix({
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
    std::string all;
    std::string line;
    std::ifstream file("default.cells");
    int lastLineLength = -1;
    while (getline (file, line)) {
        try {
            if (line[0] == '!') {
                continue;
            }
            if ((line.length() != lastLineLength) && (lastLineLength != -1)) {
                throw (std::string) "Uneven line lengths";
            }
            std::cout << line << ' ' << line.length() << '\n';
            lastLineLength = line.length();
        } catch (std::string e) {
            std::cerr << e << std::endl;
            return 1;
        }
    };
    file.close();
    return 0;
}