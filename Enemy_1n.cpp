#include "Enemy_1n.h"

bool Enemy_1n::act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy) {
    return get_hp() <= 0;
}