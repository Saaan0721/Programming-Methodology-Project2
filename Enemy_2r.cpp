#include <iostream>
#include "Enemy_2r.h"
#include "Screen_manager.h"

using namespace std;

int Enemy_2r::get_cell_speed() { return cell_speed; }

bool Enemy_2r::act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy) {
    if((curr_frame-create_frame)/cell_speed - check_frame > 0) { // move and create enemy bullet 
        if(board[y][x] == get_symbol()) {
            board[y][x] = ' ';
        }

        y++;
        
        if(board[y][x] == 'w'){
            set_hp(0);
        }
        else {
            check_frame++;
        }
    }

    return (get_hp() <= 0);
}