#ifndef LEVELUP_BULLET_H
#define LEVELUP_BULLET_H

#include "Object.h"

class Levelup_bullet: public Object {
    public:
    Levelup_bullet(int _create_frame, int _y, int _x): \
        Object(_create_frame, _y, _x) { set_symbol('L'); }
};

#endif