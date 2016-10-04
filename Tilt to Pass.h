#include<iostream>
#include<curses.h>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<vector>
using namespace std;
static const int mapWidth = 75;
static const int mapHeight = 25;
static int noplay=0;

class mode{

private:
    char modetime[128]="Y o u  s u r v i v e d  f o r       s e c o n d ";
    char modekill[128]="Y o u  k i l l e d        e n e m i e s ";
    char player1_get[128]="P l a y e r  1   g e t s   o n e   p o i n t \0";
    char player2_get[128]="P l a y e r  2   g e t s   o n e   p o i n t \0";
    char player1_win[128]="P l a y e r  1   w i n s\0";
    char player2_win[128]="P l a y e r  2   w i n s\0";
    char inquirement[128]="Press M to go back to main menu\0";

public:
    void mode_1();
    void mode_2();
    void mode_3();

};

class Arrow{

friend class enemy;
private:
    int position_x, position_y, direction;
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
    void print_arrow(int);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void renew(int,int,int);
    int getX() {return position_x;}
    int getY() {return position_y;}
    int getD() {return direction; }
};

class bomb {

friend class mode;
friend class enemy;
private:
    int position_x, position_y,open,type;
public:

    bomb()
    {
        new_bomb();
    }
    bomb(int x,int y)
    {
        position_x=x;
        position_y=y;
        open=open;
        type=type;
    }
    bool explore(Arrow);
    void print_bomb(const Arrow,int);
    void judge_type();
    void new_bomb();
    void bomb_type1(int);
    void bomb_type2(int);
    void bomb_type3(int);
    void bomb_type4(int);
    void bomb_type5(Arrow,int);
    void bomb_type6(int);
    void bomb_type7(Arrow,int);
    bool mine(Arrow);
    int getX() {return position_x;}
    int getY() {return position_y;}
    int getT() {return type;}
    int getO() {return open;}
};


class enemy{

private:
    int position_x,position_y;
public:
    enemy()
    {
        position_x=rand()%(mapWidth-2)+1;
        position_y=rand()%(mapHeight-2)+1;
    }
    enemy(int x,int y)
    {
        position_x=x;
        position_y=y;
    }
    bool clean_enemy(bomb,Arrow);
    bool same_position(int,int);
    void reconstruct();
    void print_enemy();
    void print_enemy(int);
    bool judgedirection(Arrow);
    bool trigger(int,int);
    int judgefollowarrow(Arrow player1,Arrow player2);
};



void init();
void set_color();
void opening();
void GameStart();
void menu(mode modetest);
void Game_Instruction();
void partial_erase();
void clean_enemy(bomb bomb,int& numofenemy, int *enemy);

int rand_enemy();
void print_enemy(const int &enemy);
void erase_enemy(bomb bomb, vector<int> &enemy);
bool kill_player(bomb bomb1, Arrow prey,Arrow killer);






