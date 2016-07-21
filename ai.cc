#include "ai.h"
#include <cstdlib>

using namespace std;

void AI::move() {
    for (unsigned int i = 0; i < enemyLocations.size(); i++) {
        int x = enemyLocations[i].first;
        int y = enemyLocations[i].second;
        
        while(true) {
            int rand1 = 1 - (rand() % 2);
            int rand2 = 1 - (rand() % 2);
            
            unsigned int x_coord = x + rand1;
            unsigned int y_coord = y + rand2;

            if((x_coord >= 0) && (y_coord >= 0) && (x_coord <= grid.size()) && (y_coord <= grid.at(0).size())) {
                if(grid[x_coord][y_coord].getType() == CellType::Floor) {
                    grid[x_coord][y_coord].sprite = grid[x][y].sprite;
                    grid[x][y].sprite = nullptr;
                    break;
                }
            }
        }
    }
}

AI::AI(vector <vector <Cell>> grid) : grid {grid} {}

