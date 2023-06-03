#include "Bullet.h"

char Bullet::get_symbol() {
    switch(level) {
        case 1:
            return '\'';
        case 2:
            return '^';
        case 3:
            return '!';
        default:
            return ' ';
    }
}