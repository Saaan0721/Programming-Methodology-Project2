#include <cctype>
#include "Enemy.h"

using std::toupper;

void Enemy::set_buffed() {
    is_buffed = true;
    symbol = toupper(symbol);
}