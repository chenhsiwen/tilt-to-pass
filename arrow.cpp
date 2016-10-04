#include"Tilt to Pass.h"
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
void Arrow::print_arrow(int a)
{
    if (a==1)
    {
        switch (direction)
        {
            case 1: mvaddch(position_y,position_x,'^'|COLOR_PAIR(1));break;
            case 2: mvaddch(position_y,position_x,'v'|COLOR_PAIR(1));break;
            case 3: mvaddch(position_y,position_x,'<'|COLOR_PAIR(1));break;
            case 4: mvaddch(position_y,position_x,'>'|COLOR_PAIR(1));break;
        }
    }
    if (a==2)
    {
        switch (direction)
        {
            case 1: mvaddch(position_y,position_x,'^'|COLOR_PAIR(2));break;
            case 2: mvaddch(position_y,position_x,'v'|COLOR_PAIR(2));break;
            case 3: mvaddch(position_y,position_x,'<'|COLOR_PAIR(2));break;
            case 4: mvaddch(position_y,position_x,'>'|COLOR_PAIR(2));break;
        }
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
void Arrow::renew(int x,int y, int d)
{
    position_x=x;
    position_y=y;
    direction=d;
}
