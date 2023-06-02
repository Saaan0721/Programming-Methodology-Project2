#ifndef ENEMY_1N_H
#define ENEMY_1N_H

#include "Enemy.h"

class Enemy_1n: public Enemy {
    public:
    Enemy_1n(int _create_frame, int _y, int _x): Enemy(_create_frame, _y, _x, 10, 1) { set_symbol('n'); };
};

#endif