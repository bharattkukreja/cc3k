#ifndef __AI_H__
#define __AI_H__

#include "cell.h"
#include "commands.h"
#include <vector>

class AI {
//    std::vector <std::vector <Cell>> grid;

public:
    void move(std::vector <std::pair <unsigned int, unsigned int>> &enemyLocations, std::vector <std::vector <Cell>> &grid);
    //explicit AI(std::vector <std::vector <Cell>> &grid);
};


#endif
