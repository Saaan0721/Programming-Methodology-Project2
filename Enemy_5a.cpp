#include <cstdlib>
#include "Enemy_5a.h"
#include "Screen_manager.h"

#define HEIGHT 30

using std::abs;

int Enemy_5a::get_buff_speed() { return buff_speed; }

bool Enemy_5a::act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy) {
    if((curr_frame-create_frame)/buff_speed - check_frame > 0) {
        for(auto iter = enemy.begin(); iter < enemy.end(); iter++) {
            int dis_y = abs((*iter)->get_y()-y);
            int dis_x = abs((*iter)->get_x()-x);
            if(dis_y <= 3 && dis_x <= 3 && (*iter)->get_symbol() != 'a') {
                (*iter)->set_buffed();
            }
        }
    }
    
    return (get_hp() <= 0);
}