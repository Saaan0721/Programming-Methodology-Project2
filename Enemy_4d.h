#ifndef ENEMY_4D_H
#define ENEMY_4D_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"

using std::vector;

class Enemy_4d: public Enemy {
    public:
    Enemy_4d(int _create_frame, int _y, int _x): Enemy(_create_frame, _y, _x, 5, 4), cell_speed(3) { set_symbol('d'); };
    int get_cell_speed() { return cell_speed; }

    private:
    int cell_speed;
    vector<Bullet> bullet;
};

#endif