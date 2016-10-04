#include<iostream>
#include<curses.h>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"arrow.h"
#define NDEBUG
using namespace std;

void init();
void partial_erase();

int main(){
init();
int c1;
char c2;
time_t t_temp,t_system;
t_temp=time(0);
bool death=false;

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
enemy enemy1;
player1.print_arrow();
player2.print_arrow();
refresh();
while (death==false)
{
    c1=getch();
    //c2=getch();

    if (c1==ERR) continue;
    else if (c1==KEY_UP) player1.move_up();
    else if (c1==KEY_DOWN) player1.move_down();
    else if (c1==KEY_LEFT) player1.move_left();
    else if (c1==KEY_RIGHT) player1.move_right();
    if (c1!=ERR) partial_erase();
    player1.print_arrow();
    t_temp+=1;
     while (t_system!=t_temp)
       {
           t_system=time(0);
           enemy1.judgedirection(player1);
           enemy1.print_enemy();

       }


   ;


    /*if (c2==ERR) continue;
    else if (c2==119) player2.move_up();
    else if (c2==115) player2.move_down();
    else if (c2==97) player2.move_left();
    else if (c2==100) player2.move_right();
    player2.print_arrow();*/
    refresh();
    napms(50);

}
#ifndef NDEBUG
int random;
for (int i=0;i<10000;i++)
{
    partial_erase();
    random=rand()%4;
    switch(random)
    {
        case 0: player1.move_up();break;
        case 1: player1.move_down();break;
        case 2: player1.move_left();break;
        case 3: player1.move_right();break;
    }
    player1.print_arrow();
    refresh();
    napms(10);
}
#endif

endwin();
}
void init(){
    initscr();
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
