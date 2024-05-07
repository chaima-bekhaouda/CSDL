#include <iostream>
#include <string>
#include <vector>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"


int main() {
    /*
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
    */
    std::vector<std::vector<struct Cell>> matrix({
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {1, 0}, {0, 0}, {1, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}
    });
    saveGrid((std::string) "default", matrix);

    return 0;
}