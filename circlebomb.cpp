#include"Tilt to Pass.h"

bool bomb::explore(Arrow player)
{
    if ((player.getX()==position_x&&player.getY()==position_y)||open==1)
    {
        open=1;
        return true;
    }
    else
    {
        open=0;
        return false;
    }
}
void bomb::print_bomb(const Arrow player,int shine)
{
    if (explore(player)==true)
    {
        if (type==1)
           bomb_type1(shine);
        else if (type==2)
           bomb_type2(shine);
        else if (type==3)
           bomb_type3(shine);
        else if (type==4)
           bomb_type4(shine);
        else if (type==5)
           bomb_type5(player,shine);
        else if (type==6)
           bomb_type6(shine);
        else if (type==7)
           bomb_type7(player,shine);
    }
    else if (explore(player)==false)
    {
        if (type==1)
           mvaddch(position_y,position_x,'*');
        else if (type==2)
           mvaddch(position_y,position_x,'-');
        else if (type==3)
           mvaddch(position_y,position_x,'|');
        else if (type==4)
           mvaddch(position_y,position_x,'+');
        else if (type==5)
           mvaddch(position_y,position_x,'!');
        else if (type==6)
           mvaddch(position_y,position_x,'X');
        else if (type==7)
           mvaddch(position_y,position_x,'O');
    }
}

void  bomb::new_bomb()
{
    position_x = rand()%(mapWidth-13)+6;
    position_y = rand()%(mapHeight-13)+6;
    open=0;
    judge_type();
}

void  bomb::judge_type()
{

    int temp = rand();
    if (temp%100<37)
        type=1;
    else if (temp%100<55)
        type=2;
    else if (temp%100<73)
        type=3;
    else if (temp%100<85)
        type=7;
    else if (temp%100<94)
        type=4;
    else if (temp%100<97)
        type=5;
    else if (temp%100<99)
        type=6;
}
void bomb::bomb_type1(int shine)
{
    for (int u=-5;u<=5;u++)
    {
        for (int j=-3;j<=3;j++)
        {
            if ( (u*u/25+j*j/9)<=1 )
            {
                    if (shine==0)
                        mvaddch(position_y+j,position_x+u,' '|COLOR_PAIR(6));
                    else
                        mvaddch(position_y+j,position_x+u,' '|COLOR_PAIR(5));
            }
        }
    }
}

void bomb::bomb_type2(int shine)
{
    for (int u=1;u<mapWidth-1;u++)
    {
        for (int j=-1;j<=1;j++)
        {
            if (shine==0)
                mvaddch(position_y+j,u,' '|COLOR_PAIR(3));
            else
                mvaddch(position_y+j,u,' '|COLOR_PAIR(4));

        }
    }
}

void bomb::bomb_type3(int shine)
{
    for (int u=-2;u<+2;u++)
    {
        for (int j=1;j<mapHeight-1;j++)
        {
            if (shine==0)
                mvaddch(j,position_x+u,' '|COLOR_PAIR(10));
            else
                mvaddch(j,position_x+u,' '|COLOR_PAIR(9));
        }
    }
}

void bomb::bomb_type4(int shine)
{
    for (int u=1;u<mapWidth-1;u++)
    {
        for (int j=-1;j<=1;j++)
        {
            if (shine==0)
                mvaddch(position_y+j,u,' '|COLOR_PAIR(11));
            else
                mvaddch(position_y+j,u,' '|COLOR_PAIR(12));
        }
    }
    for (int u=-2;u<+2;u++)
    {
        for (int j=1;j<mapHeight-1;j++)
        {
            if (shine==0)
                mvaddch(j,position_x+u,' '|COLOR_PAIR(11));
            else
                mvaddch(j,position_x+u,' '|COLOR_PAIR(12));
        }
    }
}

void bomb::bomb_type5(Arrow player,int shine)
{
    if (player.getD()==1)
    {
        for (int u=1;u<mapWidth-1;u++)
        {
            for (int j=1;j<=player.getY();j++)
            {
                if (shine==0)
                    mvaddch(j,u,' '|COLOR_PAIR(13));
                else
                    mvaddch(j,u,' '|COLOR_PAIR(14));
            }
        }
    }
    else if (player.getD()==2)
    {
        for (int u=1;u<mapWidth-1;u++)
        {
            for (int j=player.getY();j<mapHeight-1;j++)
            {
                if (shine==0)
                    mvaddch(j,u,' '|COLOR_PAIR(13));
                else
                    mvaddch(j,u,' '|COLOR_PAIR(14));
            }
        }
    }
    else if (player.getD()==3)
    {
        for (int u=1;u<player.getX();u++)
        {
            for (int j=1;j<mapHeight-1;j++)
            {
                if (shine==0)
                    mvaddch(j,u,' '|COLOR_PAIR(13));
                else
                    mvaddch(j,u,' '|COLOR_PAIR(14));
            }
        }
    }
    else if (player.getD()==4)
    {
        for (int u=player.getX();u<mapWidth-1;u++)
        {
            for (int j=1;j<mapHeight-1;j++)
            {
                if (shine==0)
                    mvaddch(j,u,' '|COLOR_PAIR(13));
                else
                    mvaddch(j,u,' '|COLOR_PAIR(14));
            }
        }
    }
}
void bomb::bomb_type6(int shine)
{
    for (int u=1;u<mapWidth-1;u++)
    {
        for (int j=1;j<mapHeight-1;j++)
        {
            if (shine==0)
                mvaddch(j,u,' '|COLOR_PAIR(17));
            else
                mvaddch(j,u,' '|COLOR_PAIR(18));
        }
    }
}

void bomb::bomb_type7(Arrow player,int shine)
{
    for (int u=player.getX()-1;u<=player.getX()+1;u++)
    {
        for (int j=player.getY()-1;j<=player.getY()+1;j++)
        {
            if (shine==0)
                mvaddch(j,u,' '|COLOR_PAIR(7));
            else
                mvaddch(j,u,' '|COLOR_PAIR(8));
        }
    }

}
bool bomb::mine (Arrow player)
{
    if ((player.getX()==position_x&&player.getY()==position_y))
        return true;
    else
        return false;
}

