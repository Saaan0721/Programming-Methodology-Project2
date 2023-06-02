#ifndef ENEMY_5A_H
#define ENEMY_5A_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"

using std::vector;

class Enemy_5a: public Enemy {
    public:
    Enemy_5a(int _create_frame, int _y, int _x): Enemy(_create_frame, _y, _x, 8, 5), buff_speed(6) { set_symbol('a'); };
    int get_buff_speed() { return buff_speed; }

    private:
    int buff_speed;
    vector<Bullet> bullet;
};

#endif