#include"Tilt to Pass.h"

void mode::mode_1()
{
    char to_menu;
    char clean_buffer;
    mvprintw(29,52,"TILT TO PASS");
    mvprintw(31,47,"--Single Classic Mode--");
    time_t t_move, t_system, t_new, t_bomb,t_shine;
    time_t t_survive_start=clock(),t_survive_gap;
    int shine=0;
    curs_set(0);
    t_move=clock();
    t_new=clock()+5000;
    t_bomb=clock()+750;
    int c1;
    int enemykill;
    bool death=false;
    //print walls
    for (int i=0;i<mapWidth;i++)
    {
        for (int j=0;j<mapHeight;j++)
        {
          if (i==0||j==0||i==mapWidth-1||j==mapHeight-1) mvaddch(j,i,'#');
          else mvaddch(j,i,' ');
        }
    }
    refresh();
    napms(1000);


    Arrow player1;
    enemy enemy1[50];
    int numofenemy=0;
    player1.print_arrow();
    refresh();

    bomb bomb1;
    t_move+=300;

    while (death==false)
    {
        //control the arrow
        c1=getch();
        t_system=clock();
        if (c1==KEY_UP) player1.move_up();
        else if (c1==KEY_DOWN) player1.move_down();
        else if (c1==KEY_LEFT) player1.move_left();
        else if (c1==KEY_RIGHT) player1.move_right();

        //clean the field
        partial_erase();
        if (bomb1.explore(player1)==true)
        {
            if (t_system<t_bomb)
            {
                int numofkill=0;
                for (int k=0;k<numofenemy;k++)
                {
                    if (enemy1[k].clean_enemy(bomb1,player1))
                        numofkill++;
                        enemy1[k]=enemy1[k+numofkill];
                }
                numofenemy-=numofkill;
                if (t_shine<t_system)
                {
                    shine++;
                    bomb1.print_bomb(player1,shine%2);
                    t_shine=clock()+100;
                }
            }
            else
            {
                bomb1.new_bomb();
                t_bomb=clock()+1200;
                t_shine=clock()+100;
            }
        }
        else if (bomb1.explore(player1)==false)
        {
            bomb1.print_bomb(player1,0);
            t_bomb=clock()+1200;
            t_shine=clock()+100;
        }
        player1.print_arrow();
        if (t_system>t_new)
        {
           t_new+=3000;
           enemy1[numofenemy].reconstruct();
           numofenemy++;
        }
         for (int k=0;k<numofenemy;k++)
            enemy1[k].print_enemy();
        if (t_system>t_move)
        {
           t_move+=500;
           for (int k=0;k<numofenemy;k++)
           {
               death=enemy1[k].judgedirection(player1);
               if (death==true)
               break;
           }
        }
        refresh();
        napms(50);

    }

    //end game
    erase();
    t_survive_gap = clock() - t_survive_start;


    //count
    enemykill=t_survive_gap/3000-numofenemy;


    for (int j=0;j<strlen(modetime);j++)
    {
        mvaddch(7,17+j,modetime[j]);
        if (modetime[j]!=' ') napms(200);
        refresh();
        clean_buffer=getch();
    }
     mvaddch(7,48,t_survive_gap/10000+48);
     mvaddch(7,49,t_survive_gap/1000-t_survive_gap/10000*10+48);

    refresh();

    for (int j=0;j<strlen(modekill);j++)
    {
        mvaddch(10,17+j,modekill[j]);
        if (modekill[j]!=' ') napms(200);

        refresh();
        clean_buffer=getch();
    }
    mvaddch(10,39,enemykill%10+48);
    mvaddch(10,38,enemykill/10+48);
    refresh();

    for (int j=0;j<strlen(inquirement);j++)
    {
        mvaddch(25,18+j,inquirement[j]);
    }
    refresh();


    while(true)
    {
        to_menu=getch();
        if (to_menu==109) break;
    }


    erase();
}
