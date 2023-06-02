#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"

class Enemy: public Object {
    public:
    Enemy(int _create_frame, int _y, int _x, int _hp, int _score): \
        Object(_create_frame, _y, _x), hp(_hp), score(_score) {};
    int get_hp() { return hp; }
    int get_score() { return score; }
    void set_hp(int _hp) { hp = _hp; }
    void set_score(int _score) { score = _score; }

    private:
    int hp;
    int score;
};

#endif