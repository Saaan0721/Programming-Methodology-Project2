#ifndef ENEMY_3S_H
#define ENEMY_3S_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"

using std::vector;

class Enemy_3s: public Enemy {
    public:
    Enemy_3s(int _create_frame, int _y, int _x): Enemy(_create_frame, _y, _x, 4, 3), cell_speed(9) { set_symbol('s'); };
    int get_cell_speed() { return cell_speed; }

    private:
    int cell_speed;
    vector<Bullet> bullet;
};

#endif