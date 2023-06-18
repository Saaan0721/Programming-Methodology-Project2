#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include <vector>
#include <cctype>
#include <unordered_map>
#include "Screen_manager.h"

using namespace std;

#define ENEMY_TYPE 5

//move cursor
void cursorYX(int y, int x)
{
    COORD pos;
    pos.X = x;        
    pos.Y = y;            
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Screen_manager::render(){
    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){
            cursorYX(j, i);
            printf("%c", board[j][i]);
        }
    }
}

//print sharing things.
void Screen_manager::print_share(){
    //wall
    for(int i=0; i<width; i++){board[height-1][i]='w';}
    for(int j=0; j<height; j++){board[j][0]='w'; board[j][width-1]='w';}

    int shot_frame, create_frame, check_frame;

    //Bullet part starts
    shot_frame = this->my_plane.shot_frame_my_plane;
    create_frame = this->my_plane.create_frame_my_plane;
    check_frame = this->my_plane.check_frame_my_plane;
    while ((curr_frame-create_frame)/shot_frame - check_frame > 0){ //bullet create
        int y = this->my_plane.y;
        int x = this->my_plane.x;
        Bullet bullet = Bullet(y-1+shot_frame, x, check_frame, my_plane.level);
        this->my_plane.bullet.push_back(bullet);

        if(my_plane.is_powered) {
            if(x > 0) {
                Bullet bullet = Bullet(y-1+shot_frame, x-1, check_frame, my_plane.level);
                this->my_plane.bullet.push_back(bullet);
            }
            if(my_plane.x < width-1) {
                Bullet bullet = Bullet(y-1+shot_frame, x+1, check_frame, my_plane.level);
                this->my_plane.bullet.push_back(bullet);
            }
        }

        for(auto iter=this->my_plane.bullet.begin(); iter<this->my_plane.bullet.end(); ){
            if(iter->y<=0){
                board[iter->y][iter->x]=' ';
                this->my_plane.bullet.erase(iter);
            }
            else{
                if(iter!=(this->my_plane.bullet.end()-1) && curr_frame!=1){
                    board[iter->y][iter->x]=' ';
                }
                iter->y -= shot_frame;
                board[iter->y][iter->x]=iter->get_symbol();
                iter++;
            }
        }
        this->my_plane.check_frame_my_plane+=1;
        check_frame++;
    }
    //Bullet part ends

    //Unit creation part starts
    for(int i = 0; i < num_event; i++) {
        if(frame_event[i] == curr_frame) {
            switch(type_event[i]) {
                case 'P': 
                    item.push_back(new Powerup_bullet(frame_event[i], y_event[i], x_event[i]));
                    break;
                
                case 'L':
                    item.push_back(new Levelup_bullet(frame_event[i], y_event[i], x_event[i]));
                    break;

                case 'n':
                    enemy.push_back(new Enemy_1n(frame_event[i], y_event[i], x_event[i]));
                    break;
                
                case 'r':
                    enemy.push_back(new Enemy_2r(frame_event[i], y_event[i], x_event[i]));
                    break;
                
                case 's':
                    enemy.push_back(new Enemy_3s(frame_event[i], y_event[i], x_event[i]));
                    break;
                
                case 'd':
                    enemy.push_back(new Enemy_4d(frame_event[i], y_event[i], x_event[i]));
                    break;

                case 'a':
                    enemy.push_back(new Enemy_5a(frame_event[i], y_event[i], x_event[i]));
                    break;
            }
            type_event[i] = ' ';
        }
    }
    //Unit creation part ends

    //Interaction part starts
    
    //Interaction with enemy starts
    for(auto iter = enemy.begin(); iter < enemy.end(); iter++) {
        char curr_char = board[(*iter)->get_y()][(*iter)->get_x()];

        if(curr_frame > damage_frame) {
            if(curr_char == 'M') { // if my_plane overlaps enemy, get damaged
                my_plane.hp--;
                cout << my_plane.hp;
                damage_frame = curr_frame;
            }
        }
        

        // calculate damage of bullet
        int damage = 1*(curr_char == '\'') + 2*(curr_char == '^') + 3*(curr_char == '!');
        if(damage > 0) { // if bullet exists, damage enemy
            (*iter)->decrease_hp(damage);
        }

        if((*iter)->act(curr_frame, board, enemy)) { // enemy do its own action
            killed_enemy.push_back(*iter);
            enemy.erase(iter);
            iter--;
            continue;
        }

        if(curr_char != 'M' && (*iter)->get_hp() > 0) {
            board[(*iter)->get_y()][(*iter)->get_x()] = (*iter)->get_symbol();
        }

        if(my_plane.hp <= 0) {
            gameover();
        }
    }
    //Interaction with enemy ends

    //Interaction with item starts
    for(auto iter = item.begin(); iter < item.end(); iter++) {
        char curr_char = board[(*iter)->get_y()][(*iter)->get_x()];
        if(curr_char == 'M') {
            if((*iter)->get_symbol() == 'P') {
                my_plane.is_powered = true;
                item.erase(iter);
                iter--;
            }
            else if((*iter)->get_symbol() == 'L') {
                if(my_plane.level < 3) {
                    my_plane.level++;
                    item.erase(iter);
                    iter--;
                }
            }
            continue;
        }
        board[(*iter)->get_y()][(*iter)->get_x()] = (*iter)->get_symbol();
    }
    //Interaction with item ends

    //Interaction part ends
}

//print when key didn't pressed
void Screen_manager::print(){
    board[this->my_plane.y][this->my_plane.x]='M';

    print_share();
}

//print when key pressed
void Screen_manager::print(int ch){ //ascii
    int dir;
    if(ch=='d'){ //right
        if(this->my_plane.y >=0 && this->my_plane.y <(height-1) && this->my_plane.x >0 && this->my_plane.x < (width-2)){
            dir = RIGHT;
            // board[this->my_plane.y][this->my_plane.x]=' ';
            // this->my_plane.x +=1;
            // board[this->my_plane.y][this->my_plane.x]='M';
        }
        else {
            return;
        }
    }
    else if(ch=='a'){ //left
        if(this->my_plane.y >=0 && this->my_plane.y <(height-1) && this->my_plane.x >1 && this->my_plane.x < (width-1)){
            dir = LEFT;
            // board[this->my_plane.y][this->my_plane.x]=' ';
            // this->my_plane.x -=1;
            // board[this->my_plane.y][this->my_plane.x]='M';
        }
        else {
            return;
        }
    }
    else if(ch=='w'){ //up
        if(this->my_plane.y >0 && this->my_plane.y <(height-1) && this->my_plane.x >0 && this->my_plane.x < (width-1)){
            dir = UP;
            // board[this->my_plane.y][this->my_plane.x]=' ';
            // this->my_plane.y -=1;
            // board[this->my_plane.y][this->my_plane.x]='M';
        }
        else {
            return;
        }
    }
    else if(ch=='s'){ //down
        if(this->my_plane.y >=0 && this->my_plane.y <(height-2) && this->my_plane.x >0 && this->my_plane.x < (width-1)){
            dir = DOWN;
            // board[this->my_plane.y][this->my_plane.x]=' ';
            // this->my_plane.y +=1;
            // board[this->my_plane.y][this->my_plane.x]='M';
        }
        else {
            return;
        }    
    }
    else { // if input is other key, return.
        return;
    }

    board[this->my_plane.y][this->my_plane.x]=' ';
    this->my_plane.x += direction[dir].get_x();
    this->my_plane.y += direction[dir].get_y();
    board[this->my_plane.y][this->my_plane.x]='M';


    print_share();
}

class Score {
    public:
    void insert(char s) {
        s = tolower(s);
        for(int i = 0; i < ENEMY_TYPE; i++) {
            if(symbol[i] == s) {
                count[i]++;
            }
        }
    }
    const char get_symbol(int i) { return symbol[i]; }
    const int get_count(int i) { return count[i]; }

    private:
    char symbol[ENEMY_TYPE] = {'n', 'r', 's', 'd', 'a'};
    int count[ENEMY_TYPE] = {0,};
};

void Screen_manager::gameover() {
    int score = 0;
    Score score_class;

    for(auto iter: killed_enemy) {
        score_class.insert(iter->get_symbol());
        score += iter->get_score();
    }

    system("cls");
    cout << "Your score is " << score << " (";

    for(int i = 0; i < ENEMY_TYPE; i++) {
        cout << score_class.get_symbol(i) << " : " << score_class.get_count(i);
        if(i < ENEMY_TYPE-1) {
            cout << " , ";
        }
    }
    cout << ")";
    
    exit(EXIT_SUCCESS);
}