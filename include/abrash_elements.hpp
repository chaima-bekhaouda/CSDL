#include <vector>

#ifndef CSDL_INCLUDE_ABRASH_ELEMENTS_H_
#define CSDL_INCLUDE_ABRASH_ELEMENTS_H_
// an unsigned char is 8 bits long
// 1 bit is for the cell's state (boolean, alive or dead)
// 4 bits are for the number of live neighbors (maximum is 0b1000, 8 neighbors)
// 3 bits are unused
struct Grid {
    std::vector<std::vector<unsigned char>> grid;
    std::vector<std::vector<unsigned char>> temporaryGrid;
}
#endif // CSDL_INCLUDE_ABRASH_ELEMENTS_H_