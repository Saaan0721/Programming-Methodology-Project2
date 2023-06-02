#ifndef ENEMY_4D_H
#define ENEMY_4D_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"

using std::vector;

class Enemy_4d: Enemy {
    public:
    Enemy_4d(): Enemy(5, 4), cell_speed(3) {};
    int get_cell_speed();

    private:
    int cell_speed;
    vector<Bullet> bullet;
};

#endif