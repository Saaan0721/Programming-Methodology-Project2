#ifndef ENEMY_5A_H
#define ENEMY_5A_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"

using std::vector;

class Enemy_5a: Enemy {
    public:
    Enemy_5a(): Enemy(8, 5), buff_speed(6) {};
    int get_buff_speed();

    private:
    int buff_speed;
    vector<Bullet> bullet;
};

#endif