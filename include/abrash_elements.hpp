#include <vector>

// an unsigned char is 8 bits long
// 1 bit is for the cell's state (boolean, alive or dead)
// 4 bits are for the number of live neighbors (maximum is 0b1000, 8 neighbors)
// 3 bits are unused
extern std::vector<std::vector<unsigned char>> currentGrid;
extern std::vector<std::vector<unsigned char>> nextGrid;