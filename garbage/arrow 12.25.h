#include<iostream>
#include<curses.h>
using namespace std;
static const int mapWidth = 75;
static const int mapHeight = 25;

class Arrow {
private:
    int position_x,position_y,direction;
public:
    Arrow()
    {
        position_x=38;
        position_y=12;
        direction=1;
    }
    Arrow(int x,int y, int d)
    {
        position_x=x;
        position_y=y;
        direction=d;
    }
    void print_arrow();
    void move_up();
    void move_down();
    void move_left();
    void move_right();


};

void Arrow::print_arrow()
{
    switch (direction)
    {
        case 1: mvaddch(position_y,position_x,'^');break;
        case 2: mvaddch(position_y,position_x,'v');break;
        case 3: mvaddch(position_y,position_x,'<');break;
        case 4: mvaddch(position_y,position_x,'>');break;
    }
}
void Arrow::move_up()
{
    if (position_y!=1) position_y--;
    direction=1;
}
void Arrow::move_down()
{
    if (position_y!=mapHeight-2) position_y++;
    direction=2;
}
void Arrow::move_left()
{
    if (position_x!=1) position_x--;
    direction=3;
}
void Arrow::move_right()
{
    if(position_x!=mapWidth-2) position_x++;
    direction=4;
}
