#include <iostream>
#include "Enemy_2r.h"
#include "Screen_manager.h"

using namespace std;

bool Enemy_2r::act(int curr_frame, char board[][WIDTH]) {
    if((curr_frame-create_frame)/cell_speed - check_frame > 0) {
        board[y][x] = ' ';
        y++;
        if(board[y][x] == 'w'){
            return true;   
        }
        board[y][x] = this->get_symbol();
        check_frame++;
    }
    return false;
}