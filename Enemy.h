#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    public:
    Enemy(int _hp, int _score): hp(_hp), score(_score) {};
    int get_hp();
    int get_score();
    void set_hp(int _hp);
    void set_score(int _score);

    private:
    int hp;
    int score;
};

#endif