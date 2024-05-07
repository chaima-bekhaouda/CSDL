#include <vector>


#ifndef CSDL_INCLUDE_GOL_ELEMENTS_H_
#define CSDL_INCLUDE_GOL_ELEMENTS_H_
struct Cell {
    bool currentState;
    bool nextState;
};
#endif  // CSDL_INCLUDE_GOL_ELEMENTS_H_

extern std::vector<std::vector<struct Cell>> matrix;