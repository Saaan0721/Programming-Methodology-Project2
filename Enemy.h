#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"

class Enemy: public Object {
    public:
    Enemy(int _create_frame, int _y, int _x, int _hp, int _score, char _symbol): \
        Object(_create_frame, _y, _x), hp(_hp), score(_score) { set_symbol(_symbol); }
    int get_hp() { return hp; }
    int get_score() { return score; }
    void set_hp(int _hp) { hp = _hp; }
    void set_score(int _score) { score = _score; }
    virtual void decrease_hp(int damage) { hp -= damage; }

    private:
    int hp;
    int score;
};

#endif