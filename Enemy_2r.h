#ifndef ENEMY_2R_H
#define ENEMY_2R_H

#include "Enemy.h"

class Enemy_2r: public Enemy {
    public:
    Enemy_2r(int _create_frame, int _y, int _x): Enemy(_create_frame, _y, _x, 5, 2), cell_speed(3) { set_symbol('r'); };
    int get_cell_speed() { return cell_speed; }

    private:
    int cell_speed;
};

#endif