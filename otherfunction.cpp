#include"Tilt to Pass.h"

void init()
{
    initscr();
    noecho();
    system("CHCP 437");
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    srand(time(0));
}
void partial_erase()
{
    for (int i=0;i<mapWidth;i++)
    {
        for (int j=0;j<mapHeight;j++)
        {
          if (i==0||j==0||i==mapWidth-1||j==mapHeight-1) continue;
          else mvaddch(j,i,' ');
        }
    }
}


bool kill_player(bomb bomb1, Arrow prey,Arrow killer)
{
    if (bomb1.getT()==1)
    {
            for (int u=-5;u<=5;u++)
            {
                for (int j=-3;j<=3;j++)
                {
                    if (prey.getX()==bomb1.getX()+u&&prey.getY()==bomb1.getY()+j&&(u*u/25+j*j/9)<=1)
                        return true;
                }
            }
    }

    else if (bomb1.getT()==2)
    {
            for (int j=bomb1.getY()-1;j<=bomb1.getY()+1;j++)
                if (prey.getY()==j) return true;
    }

    else if (bomb1.getT()==3)
    {
        for (int u=bomb1.getX()-1;u<=bomb1.getX()+1;u++)
                if (prey.getX()==u) return true;
    }

    else if (bomb1.getT()==4)
    {
        for (int u=bomb1.getY()-1;u<=bomb1.getY()+1;u++)
                if (prey.getY()==u) return true;
        for (int u=bomb1.getX()-1;u<=bomb1.getX()+1;u++)
                if (prey.getX()==u) return true;
    }

    else if (bomb1.getT()==5)
    {
        if (killer.getD()==1)
        {   for (int u=1;u<mapWidth-1;u++)
            {
                for (int j=1;j<=killer.getY();j++)
                {
                     if (prey.getX()==u && prey.getY()==j)
                        return true;
                }
            }
        }
        else if (killer.getD()==2)
        {
            for (int u=1;u<mapWidth-1;u++)
            {
                for (int j=killer.getY();j<mapHeight-1;j++)
                {
                     if (prey.getX()==u && prey.getY()==j)
                        return true;
                }
            }
        }
        else if (killer.getD()==3)
        {
            for (int u=1;u<killer.getX();u++)
            {
                for (int j=1;j<mapHeight-1;j++)
                {
                     if (prey.getX()==u && prey.getY()==j)
                        return true;
                }
            }
        }
        else if (killer.getD()==4)
        {
            for (int u=killer.getX();u<mapWidth-1;u++)
            {
                for (int j=1;j<mapHeight-1;j++)
                {
                      if (prey.getX()==u && prey.getY()==j)
                        return true;
                }
            }
        }
    }
    else if (bomb1.getT()==6)
        return true;
    else if (bomb1.getT()==7)
    {
        for (int u=killer.getX()-1;u<=killer.getX()+1;u++)
        {
            for (int j=killer.getY()-1;j<=killer.getY()+1;j++)
            {
                if (prey.getX()==u && prey.getY()==j)
                    return true;
            }
        }
    }
    return false;
}

