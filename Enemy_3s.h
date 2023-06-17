#ifndef ENEMY_3S_H
#define ENEMY_3S_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include "Enemy_bullet.h"

using std::vector;

class Enemy_3s: public Enemy {
    public:
    Enemy_3s(int _create_frame, int _y, int _x): \
        Enemy(_create_frame, _y, _x, 4, 3, 's'), cell_speed(9) {};
    int get_cell_speed();
    bool act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy);

    private:
    int cell_speed;
    int bullet_check_frame=0;
    vector<Enemy_bullet*> enemy_bullet;
};

#endif