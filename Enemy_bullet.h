#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

#include "Bullet.h"

class Enemy_bullet: public Bullet {
    public:
    Enemy_bullet(int y_value, int x_value, int frame_value, int _level): \
        Bullet(y_value, x_value, frame_value, _level) {};

    char get_symbol() { return '*'; }
    
};

#endif