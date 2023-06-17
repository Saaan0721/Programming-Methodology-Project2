#include "Enemy_4d.h"

int Enemy_4d::get_cell_speed() { return cell_speed; }

bool Enemy_4d::act(int curr_frame, char board[][WIDTH], vector<Enemy*>& enemy) {
    if(get_hp() > 0) { // if enemy still alive, move and shoot
        if((curr_frame-create_frame)/cell_speed - check_frame > 0) { // move and create enemy bullet 
            if(board[y][x] == get_symbol()) {
                board[y][x] = ' ';
            }

            y++;
            
            if(board[y][x] == 'w'){
                set_hp(0);
            }
            else {
                board[y][x] = this->get_symbol();

                enemy_bullet.push_back(new Enemy_bullet(y, x, check_frame, 1 + this->get_is_buffed()));

                check_frame++;
            }
        }
    }

    if((curr_frame - create_frame) - bullet_check_frame > 0) { // move enemy bullet
        for(auto iter=enemy_bullet.begin(); iter<enemy_bullet.end(); ){
            if(board[(*iter)->y][(*iter)->x] == 'w'){
                board[(*iter)->y][(*iter)->x]=' ';
                enemy_bullet.erase(iter);
            }
            else{
                if(board[(*iter)->y][(*iter)->x] == (*iter)->get_symbol()) {
                    board[(*iter)->y][(*iter)->x]=' ';
                }
                
                if(x < WIDTH/2) {
                    (*iter)->x -= 1;
                }
                else {
                    (*iter)->x += 1;
                }
                (*iter)->y += 1;

                board[(*iter)->y][(*iter)->x]=(*iter)->get_symbol();
                iter++;
            }
        }
        bullet_check_frame++;
    }
    
    return (get_hp() <= 0 && enemy_bullet.empty());
}