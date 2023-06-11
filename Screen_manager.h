#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

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
#include "My_plane.h"
#include "Object.h"
#include "Powerup_bullet.h"
#include "Levelup_bullet.h"
#include "Enemy.h"
#include "Enemy_1n.h"
#include "Enemy_2r.h"
#include "Enemy_3s.h"
#include "Enemy_4d.h"
#include "Enemy_5a.h"

using namespace std;

//Screen manager.
class Screen_manager{
    public:
        int frame_length=100000; //each frame's length == 0.1sec(10,000 microseconds)
        int curr_frame=0; //1frame=0.1sec

        int y, x;
        int width=60;
        int height=30;
        int num_event;
        int frame_event[300]={0,}, y_event[300]={0,}, x_event[300]={0,};
        char type_event[300] = {' ',};

        void print(int ascii);
        void print();
        void print_share();
        void render();
        char board[30][60]={'a'};
        My_plane my_plane = My_plane(height-2, 1, 0);

        enum Dir {
            RIGHT, LEFT, UP, DOWN,
            
        };
        class Direction {
            public:
            Direction(int _x, int _y): x(_x), y(_y) {};
            int get_x() { return x; }
            int get_y() { return y; }

            private:
            int x;
            int y;
        };

        // right, left, up, down
        Direction direction[4] = {Direction(1, 0), Direction(-1, 0), Direction(0, -1), Direction(0, 1)};
    
    private:
        vector<Enemy*> enemy;
        vector<Enemy*> killed_enemy;
        vector<Object*> item;

};

#endif