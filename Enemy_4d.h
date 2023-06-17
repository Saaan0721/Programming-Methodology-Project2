#ifndef ENEMY_4D_H
#define ENEMY_4D_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include "Enemy_bullet.h"

using std::vector;

class Enemy_4d: public Enemy {
    public:
    Enemy_4d(int _create_frame, int _y, int _x): \
        Enemy(_create_frame, _y, _x, 5, 4, 'd'), cell_speed(3) {};
    int get_cell_speed();
    bool act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy);

    private:
    int cell_speed;
    int bullet_check_frame=0;
    vector<Enemy_bullet*> enemy_bullet;
};

#endif