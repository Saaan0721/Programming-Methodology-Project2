#include "Enemy_3s.h"

bool Enemy_3s::act(int curr_frame, char board[][WIDTH]) {
    if((curr_frame-create_frame)/cell_speed - check_frame > 0) { // move and create enemy bullet 
        board[y][x] = ' ';
        y++;
        if(board[y][x] == 'w'){
            return true;   
        }

        board[y][x] = this->get_symbol();

        enemy_bullet.push_back(new Enemy_bullet(y, x, check_frame, 1 + this->get_is_buffed()));

        check_frame++;
    }

    
    if((curr_frame - create_frame) - bullet_check_frame > 0) { // move enemy bullet
        for(auto iter=enemy_bullet.begin(); iter<enemy_bullet.end(); ){
            if(board[(*iter)->y][(*iter)->x] == 'w'){
                board[(*iter)->y][(*iter)->x]=' ';
                enemy_bullet.erase(iter);
            }
            else{
                board[(*iter)->y][(*iter)->x]=' ';
                (*iter)->y += 1;
                board[(*iter)->y][(*iter)->x]=(*iter)->get_symbol();
                iter++;
            }
        }
        bullet_check_frame++;
    }
    
    return false;
}