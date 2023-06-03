#ifndef OBJECT_H
#define OBJECT_H

class Object {
    public:
    Object(int _create_frame, int _y, int _x): create_frame(_create_frame) \
        , y(_y), x(_x) {};
    int get_create_frame() { return create_frame; }
    int get_y() { return y; }
    int get_x() { return x; }
    char get_symbol() { return symbol; }
    void set_symbol(char _symbol) { symbol = _symbol; }


    private:
    int create_frame;
    int y, x;
    char symbol;    
};

#endif