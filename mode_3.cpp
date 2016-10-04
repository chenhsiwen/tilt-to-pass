#include"Tilt to Pass.h"

void mode::mode_3()
{
    mvprintw(29,52,"TILT TO PASS");
    mvprintw(31,47,"--Double Deathmatch Mode--");
    curs_set(0);
    int c,i=0,point1=0,point2=0;
    time_t t_move,t_system,t_new;
    bool death1=false,death2=false,win1=false, win2=false;
    char pnt1=48, pnt2=48;

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
    enemy enemy[100];
    int whose_enemy[100];



    player1.print_arrow(1);
    player2.print_arrow(2);

    refresh();

    t_move=clock();
    t_system=clock();
    t_new=clock()+3000;

    for (int j=0;j<100;j++)
    {
        whose_enemy[j]=0;
    }


    while (win1==false && win2 == false)
    {
        curs_set(0);
        for (int k=0;k<i;k++)
                enemy[k].reconstruct();
        if (point1!=0||point2!=0)
        {
            player1.renew(50,12,3);
            player2.renew(25,12,4);
            for (int j=0;j<100;j++) whose_enemy[j]=0;
            i=0;
            t_move=clock();
            t_new=clock()+5000;
            death1=false;death2=false;
        }


        while (death1==false&&death2==false)
        {

            t_move+=300;

            mvaddch(29,28,pnt1|COLOR_PAIR(1));
            mvaddch(29,20,pnt2|COLOR_PAIR(2));
            //mvaddch(8,77,pnt1|COLOR_PAIR(1));
            //mvaddch(11,77,pnt2|COLOR_PAIR(2));

            while (t_system<t_move)
            {
                c=getch();
                t_system=clock();

                if (c==KEY_UP) player1.move_up();
                else if (c==KEY_DOWN) player1.move_down();
                else if (c==KEY_LEFT) player1.move_left();
                else if (c==KEY_RIGHT) player1.move_right();
                else if (c==119) player2.move_up();
                else if (c==115) player2.move_down();
                else if (c==97) player2.move_left();
                else if (c==100) player2.move_right();

                partial_erase();
                player1.print_arrow(1);
                player2.print_arrow(2);

                refresh();
                for (int k=0;k<i;k++)
                {
                    if (enemy[k].trigger(player1.getX(),player1.getY())==true) {if (whose_enemy[k]!=2) whose_enemy[k]=1;}
                    if (enemy[k].trigger(player2.getX(),player2.getY())==true) {if (whose_enemy[k]!=1) whose_enemy[k]=2;}
                    if (whose_enemy[k]==1) enemy[k].print_enemy(1);
                    else if (whose_enemy[k]==2) enemy[k].print_enemy(2);
                    else enemy[k].print_enemy();
                }

                if (t_system>t_new)
                {
                    i++;
                    t_new+=1500;
                }
                refresh();
                napms(50);
                }

                for (int k=0;k<i;k++)
                {
                    if (whose_enemy[k]==1)
                        death2=enemy[k].judgedirection(player2);
                    if (death2==true) break;
                    if (whose_enemy[k]==2)
                        death1=enemy[k].judgedirection(player1);
                    if (death1==true) break;
                }

        }
        partial_erase();

        if (death1==true)
        {
            for (int j=0;j<strlen(player2_get);j++)
            {
                mvaddch(10,15+j,player2_get[j]);
                if (player2_get[j]!=' ') napms(200);
                refresh();
                c=getch();
            }
            point2++;
        }

        if (death2==true)
        {
            for (int j=0;j<strlen(player1_get);j++)
            {
                mvaddch(10,15+j,player1_get[j]);
                if (player1_get[j]!=' ') napms(200);
                refresh();
                c=getch();
            }
            point1++;
        }

        pnt1=point1+48;
        pnt2=point2+48;

        mvaddch(18,50,pnt1|COLOR_PAIR(1));
        mvaddch(18,25,pnt2|COLOR_PAIR(2));
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
            c=getch();
        }
    }

    if (win2==true)
    {
        for (int j=0;j<strlen(player2_win);j++)
        {
            mvaddch(7,28+j,player2_win[j]);
            if (player2_win[j]!=' ') napms(200);
            refresh();
            c=getch();
        }
    }

    for (int j=0;j<strlen(inquirement);j++)
    {
        mvaddch(15,18+j,inquirement[j]);
    }

    refresh();

    int c2;
    while(true)
    {
        c2=getch();
        if (c2==109) break;
    }
    endwin();
}
