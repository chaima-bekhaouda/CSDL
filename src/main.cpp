#include <iostream>
#include <string>
#include "gol_elements.hpp"
#include "gol_algorithm.hpp"
#include "gol_file_handling.hpp"


int main() {
    std::cout << readGridFile("default") << std::endl;

    return 0;
}