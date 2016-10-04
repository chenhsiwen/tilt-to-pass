#include"Tilt to Pass.h"

void mode::mode_2()
{
    mvprintw(29,52,"TILT TO PASS");
    mvprintw(31,47,"--Double Weapon Mode--");
    char to_menu;
    curs_set(0);
    int c1;
    int shine=0;
    int point1=0,point2=0;
    char pnt1=48, pnt2=48;
    time_t t_move,t_system,t_new,t_bomb,t_shine;

    t_move=clock();
    t_new=clock()+5000;
    bool death1=false,death2=false,win1=false, win2=false;
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

    while (win1==false&&win2==false)
    {

        t_move=clock();
        t_new=clock()+5000;
        death1=false;death2=false;//win1=false, win2=false;


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

        Arrow player1(50,12,3);
        Arrow player2(25,12,4);
        enemy enemy1[50];
        int numofenemy=0;
        player1.print_arrow(1);
        player2.print_arrow(1);
        refresh();
        bomb bomb1;
        t_move+=500;

        while (death1==false&&death2==false)
        {
            curs_set(0);
            mvaddch(29,28,pnt1|COLOR_PAIR(1));
            mvaddch(29,20,pnt2|COLOR_PAIR(2));
            c1=getch();
            t_system=clock();

            if (c1==KEY_UP) player1.move_up();
            else if (c1==KEY_DOWN) player1.move_down();
            else if (c1==KEY_LEFT) player1.move_left();
            else if (c1==KEY_RIGHT) player1.move_right();
            else if (c1==119) player2.move_up();
            else if (c1==115) player2.move_down();
            else if (c1==97) player2.move_left();
            else if (c1==100) player2.move_right();

            partial_erase();
            if (bomb1.explore(player1)==true||bomb1.explore(player2)==true)
            {
                if (t_system<t_bomb)
                {
                    int numofkill=0;
                    if (bomb1.mine(player1)==true)
                    {
                        for (int k=0;k<numofenemy;k++)
                        {
                            if (enemy1[k].clean_enemy(bomb1,player1))
                                numofkill++;
                                enemy1[k]=enemy1[k+numofkill];
                        }
                        if (t_shine<t_system)
                        {
                            shine++;
                            bomb1.print_bomb(player1,shine%2);
                            t_shine=clock()+100;
                        }
                        numofenemy-=numofkill;
                    }
                    if (bomb1.mine(player2)==true)
                    {

                        for (int k=0;k<numofenemy;k++)
                        {
                            if (enemy1[k].clean_enemy(bomb1,player2))
                                numofkill++;
                                enemy1[k]=enemy1[k+numofkill];
                        }
                        if (t_shine<t_system)
                        {
                            shine++;
                            bomb1.print_bomb(player2,shine%2);
                            t_shine=clock()+100;
                        }
                        numofenemy-=numofkill;
                    }

                }
                else
                {
                    bomb1.new_bomb();
                    t_bomb=clock()+1200;
                    t_shine=clock()+100;
                }
            }
            else
            {
                bomb1.print_bomb(player2,0);
                bomb1.print_bomb(player1,0);
                t_bomb=clock()+1200;
                t_shine=clock()+100;
            }
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
                        int temp = enemy1[k].judgefollowarrow(player1,player2);
                        if (temp==0)
                        {
                            death1=enemy1[k].judgedirection(player1);
                        }
                        else
                        {
                            death2=enemy1[k].judgedirection(player2);
                        }
                        if (death1==true||death2==true)
                        break;
                    }
                }

            if (bomb1.mine(player1)==true) death2=kill_player(bomb1,player2,player1);
            if (bomb1.mine(player2)==true) death1=kill_player(bomb1,player1,player2);

            player1.print_arrow(1);
            player2.print_arrow(2);
            refresh();
            napms(50);
        }

        partial_erase();

        if (death1==true)
        {
            for (int j=0;j<strlen(player2_get);j++)
            {
                mvaddch(10,15+j,player2_get[j]);
                if (player2_get[j]!=' ') napms(120);
                refresh();
            }
            point2++;
            napms(3000);
        }

        else if (death2==true)
        {
            for (int j=0;j<strlen(player1_get);j++)
            {
                mvaddch(10,15+j,player1_get[j]);
                if (player1_get[j]!=' ') napms(120);
                refresh();
            }
            point1++;
        }

        pnt1=point1+48;
        pnt2=point2+48;
        {
            mvaddch(18,50,pnt1|COLOR_PAIR(1));
            mvaddch(18,25,pnt2|COLOR_PAIR(2));
            refresh();
            napms(300);
        }

        refresh();

        if (point1==3) win1=true;
        if (point2==3) win2=true;

        napms(3000);
    }
    erase();

    if (win1==true)
    {
        for (int j=0;j<strlen(player1_win);j++)
        {
            mvaddch(7,28+j,player1_win[j]);
            if (player1_win[j]!=' ') napms(200);
            refresh();
        }
        napms(100);
    }

    if (win2==true)
    {
        for (int j=0;j<strlen(player2_win);j++)
        {
            mvaddch(7,28+j,player2_win[j]);
            if (player2_win[j]!=' ') napms(200);
            refresh();
        }
        napms(100);
    }

    for (int j=0;j<strlen(inquirement);j++)
    {
        mvaddch(15,25+j,inquirement[j]);
    }
    refresh();


    while(true)
    {
        to_menu=getch();
        if (to_menu!=ERR) break;
    }


    erase();
}
