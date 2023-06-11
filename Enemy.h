#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include "Object.h"

#define WIDTH 60

using namespace std;

class Enemy: public Object {
    public:
    Enemy(int _create_frame, int _y, int _x, int _hp, int _score, char _symbol): \
        Object(_create_frame, _y, _x), hp(_hp), score(_score) { symbol = _symbol; }
    int get_hp() { return hp; }
    int get_score() { return score; }
    char get_symbol() { return symbol; }
    void set_hp(int _hp) { hp = _hp; }
    void set_score(int _score) { score = _score; }
    void decrease_hp(int damage) { hp -= damage; }
    void set_buffed();
    bool get_is_buffed() { return is_buffed; }
    virtual bool act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy)=0; //act that each enemy has

    protected:
    int check_frame = 0;

    private:
    int hp;
    int score;
    bool is_buffed = false;
};

#endif