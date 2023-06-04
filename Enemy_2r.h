#ifndef ENEMY_2R_H
#define ENEMY_2R_H

#include "Enemy.h"

class Enemy_2r: public Enemy {
    public:
    Enemy_2r(int _create_frame, int _y, int _x): \
        Enemy(_create_frame, _y, _x, 5, 2, 'r'), cell_speed(3) {};
    int get_cell_speed() { return cell_speed; }
    virtual bool act(int curr_frame, char board[][WIDTH]);

    private:
    int cell_speed;
};

#endif