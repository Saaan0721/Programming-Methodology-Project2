#ifndef ENEMY_3S_H
#define ENEMY_3S_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"

using std::vector;

class Enemy_3s: Enemy {
    public:
    Enemy_3s(): Enemy(4, 3), cell_speed(9) {};
    int get_cell_speed();

    private:
    int cell_speed;
    vector<Bullet> bullet;
};

#endif