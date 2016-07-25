#include "ai.h"
#include <cstdlib>
#include "sprite.h"
#include "spritetype.h"

using namespace std;

void AI::move(vector <pair <int, int>> &enemyLocations, vector <vector <Cell>> &grid) {
    for (unsigned int i = 0; i < enemyLocations.size(); i++) {
        
        Cell c = grid[enemyLocations[i].first][enemyLocations[i].second];
        if(c.sprite->getType() == SpriteType::Dragon)
            continue;
        
        int x = enemyLocations[i].first;
        int y = enemyLocations[i].second;
        
        while(true) {
            int rand1 = 1 - (rand() % 3);
            int rand2 = 1 - (rand() % 3);
            
            if(rand1 == 0 && rand2 == 0)
                continue;
            
            unsigned int x_coord = x + rand1;
            unsigned int y_coord = y + rand2;

            if((x_coord >= 0) && (y_coord >= 0) && (x_coord <= grid.size()) && (y_coord <= grid.at(0).size())) {
                if(grid[x_coord][y_coord].getType() == CellType::Floor && grid[x_coord][y_coord].isEmpty() && !grid[x][y].isEmpty()) {
                    grid[x_coord][y_coord].sprite = grid[x][y].sprite;
                    grid[x][y].sprite = nullptr;
		    enemyLocations[i].first = x_coord;
		    enemyLocations[i].second = y_coord;
                    break;
                }
            }
        }
    }
}


