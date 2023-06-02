#ifndef POWERUP_BULLET_H
#define POWERUP_BULLET_H

#include "Object.h"

class Powerup_bullet: public Object {
    public:
    Powerup_bullet(int _create_frame, int _y, int _x): \
        Object(_create_frame, _y, _x) { set_symbol('P'); }
};

#endif