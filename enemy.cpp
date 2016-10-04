#include"Tilt to Pass.h"
void enemy::reconstruct()
{
    position_x=rand()%(mapWidth-2)+1;
    position_y=rand()%(mapHeight-2)+1;
}
void enemy::print_enemy()
{
    mvaddch(position_y,position_x,'F');
}
bool enemy::same_position(int bomb_position_x,int bomb_position_y)
{
    if (position_x==bomb_position_x&&position_y==bomb_position_y)
        return true;
    else
        return false;
}
bool enemy::clean_enemy(bomb bomb,Arrow player)
{
    if(bomb.getO()==1)
    {
        if (bomb.getT()==1)
        {
                for (int u=-5;u<=5;u++)
                {
                    for (int j=-3;j<=3;j++)
                    {
                        if (same_position(bomb.getX()+u,bomb.getY()+j)&&(j*j/25+u*u/9)<=1)
                            return true;
                    }
                }
        }
        else if (bomb.getT()==2)
        {

            for (int u=0;u<=mapWidth;u++)
            {
                for (int j=-1;j<=1;j++)
                {
                    if (same_position(u,bomb.getY()+j))
                        return true;
                }
            }
        }
        else if (bomb.getT()==3)
        {

            for (int u=-2;u<=2;u++)
            {
                for (int j=0;j<=mapHeight;j++)
                {
                    if (same_position(bomb.getX()+u,j))
                        return true;
                }
            }
        }

        else if (bomb.getT()==4)
        {
            for (int u=0;u<=mapWidth;u++)
            {
                for (int j=-1;j<=1;j++)
                {
                    if (same_position(u,bomb.getY()+j))
                        return true;
                }
            }
            for (int u=-2;u<=2;u++)
            {
                for (int j=0;j<=mapHeight;j++)
                {
                    if (same_position(bomb.getX()+u,bomb.getY()+j))
                        return true;
                }
            }
        }
        else if (bomb.getT()==5)
        {

            if (player.getD()==1)
            {   for (int u=1;u<mapWidth-1;u++)
                {
                    for (int j=1;j<=player.getY();j++)
                    {
                         if (same_position(u,j))
                            return true;
                    }
                }
            }
            else if (player.getD()==2)
            {
                for (int u=1;u<mapWidth-1;u++)
                {
                    for (int j=player.getY();j<mapHeight-1;j++)
                    {
                        if (same_position(u,j))
                            return true;
                    }
                }
            }
            else if (player.getD()==3)
            {
                for (int u=1;u<player.getX();u++)
                {
                    for (int j=1;j<mapHeight-1;j++)
                    {
                         if (same_position(u,j))
                            return true;
                    }
                }
            }
            else if (player.getD()==4)
            {
                for (int u=player.getX();u<mapWidth-1;u++)
                {
                    for (int j=1;j<mapHeight-1;j++)
                         if (same_position(u,j))
                            return true;
                }
            }
        }
        else if (bomb.getT()==6)
        {

            for (int u=0;u<=mapWidth;u++)
            {
                for (int j=0;j<=mapHeight;j++)
                {
                    if (same_position(u,j))
                        return true;
                }
            }
            return true;
        }
        else if (bomb.getT()==7)
        {
            for (int u=player.getX()-1;u<=player.getX()+1;u++)
            {
                for (int j=player.getY()-1;j<=player.getY()+1;j++)
                {
                     if (same_position(u,j))
                        return true;
                }
            }

        }
    }
    else
        return false;
}
void enemy::print_enemy(int a)
{
     if (a==1)  mvaddch(position_y,position_x,'F'|COLOR_PAIR(1));
     if (a==2)  mvaddch(position_y,position_x,'F'|COLOR_PAIR(2));

}
 int enemy::judgefollowarrow(Arrow player1,Arrow player2)
{
    int length1=abs(player1.getX()-position_x)+abs(player1.getY()-position_y);
    int length2=abs(player2.getX()-position_x)+abs(player2.getY()-position_y);
    if (length1>length2)
        return 1;
    else if (length1<length2)
        return 0;
    else
        return rand()%2;
}
bool enemy::judgedirection(Arrow player)
{
    int ran =rand()%2;
    if (position_x>player.position_x&&position_y>player.position_y)
    {
        if (ran==0)
        {
            position_x--;
        }
        else if (ran==1)
        {
            position_y--;
        }
    }
    else if (position_x>player.position_x&&position_y<player.position_y)
    {
        if (ran==0)
        {
            position_x--;
        }
        else if (ran==1)
        {
            position_y++;
        }
    }
    else if (position_x<player.position_x&&position_y>player.position_y)
    {
        if (ran==0)
        {
            position_x++;
        }
        else if (ran==1)
        {
            position_y--;
        }
    }
    else if (position_x<player.position_x&&position_y<player.position_y)
    {
        if (ran==0)
        {
            position_x++;
        }
        else if (ran==1)
        {
            position_y++;
        }
    }
    else if  (position_x==player.position_x&&position_y!=player.position_y)
    {
        if (position_y>player.position_y)
        {
            position_y--;
        }
        else if (position_y<player.position_y)
        {
            position_y++;
        }
    }
    else if  (position_x!=player.position_x&&position_y==player.position_y)
    {
        if (position_x>player.position_x)
        {
            position_x--;
        }
        else if (position_x<player.position_x)
        {
            position_x++;
        }
    }
    else return true;

    return false;

}

bool enemy::trigger(int x, int y)
{
    for (int j=position_x-1;j<=position_x+1;j++)
    {
        for (int k=position_y-1;k<=position_y+1;k++)
            if (j==x&&k==y) return true;
    }
    return false;
}
