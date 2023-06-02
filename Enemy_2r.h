#ifndef ENEMY_2R_H
#define ENEMY_2R_H

#include "Enemy.h"

class Enemy_2r: Enemy {
    public:
    Enemy_2r(): Enemy(5, 2), cell_speed(3) {};
    int get_cell_speed();

    private:
    int cell_speed;
};

#endif