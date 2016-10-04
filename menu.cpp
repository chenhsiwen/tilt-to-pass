#include "Tilt to Pass.h"
void Game_Instruction()
{
    erase();
    char str1[]={"Welcome to the instruction of TILT TO PASS."};

    char str2[]={"There are three modes of the game:"};
    char str3[]={"Single Classic Mode, Double Weapon Mode and Double Deathmatch Mode."};

    char str4[]={"In Single Classic Mode,"};
    char str5[]={"You need to dodge the 'F's and eliminate them with the weapons."};

    char str6[]={"In Double Weapon Mode,"};
    char str7[]={"You can kill both the 'F's and the other player"};
    char str7_2[]={"with the weapons so as to gain points."};
    char str8[]={"The player who first wins 3 innings wins."};

    char str9[]={"In Double Deathmatch Mode,"};
    char str10[]={"You need to recruit the originally neutral 'F's,"};
    char str10_2[]={"making them chase the other player."};
    char str11[]={"The player who first wins 3 innings wins."};

    char next[]={"Next>>>"};
    char empstr[]={"        "};
    char nextpage, jump;
    bool patience=true;

    for(int i=0;i<strlen(str1);i++)
    {
        mvaddch(14,18+i,str1[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    napms(300);

    for (int i=0;;i++)
    {
        if (i%2==0)
        {
            for(int j=0;j<strlen(next);j++)
                mvaddch(20,60+j,next[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(empstr);j++)
                mvaddch(20,60+j,empstr[j]);
            refresh();
        }
        napms(300);
        nextpage=getch();
        if (nextpage!=ERR) break;
    }
    erase();
    patience=true;

    for(int i=0;i<strlen(str2);i++)
    {
        mvaddch(10,22+i,str2[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }

    for(int i=0;i<strlen(str3);i++)
    {
        mvaddch(12,5+i,str3[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    napms(300);

    for (int i=0;;i++)
    {
        if (i%2==0)
        {
            for(int j=0;j<strlen(next);j++)
                mvaddch(20,60+j,next[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(empstr);j++)
                mvaddch(20,60+j,empstr[j]);
            refresh();
        }
        napms(300);
        nextpage=getch();
        if (nextpage!=ERR) break;
    }
    erase();
    patience=true;

    for(int i=0;i<strlen(str4);i++)
    {
        mvaddch(8,4+i,str4[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }

    for(int i=0;i<strlen(str5);i++)
    {
        mvaddch(10,4+i,str5[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    napms(300);

    for (int i=0;;i++)
    {
        if (i%2==0)
        {
            for(int j=0;j<strlen(next);j++)
                mvaddch(20,60+j,next[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(empstr);j++)
                mvaddch(20,60+j,empstr[j]);
            refresh();
        }
        napms(300);
        nextpage=getch();
        if (nextpage!=ERR) break;
    }
    erase();
    patience=true;

    for(int i=0;i<strlen(str6);i++)
    {
        mvaddch(8,4+i,str6[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    for(int i=0;i<strlen(str7);i++)
    {
        mvaddch(10,4+i,str7[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    for(int i=0;i<strlen(str7_2);i++)
    {
        mvaddch(12,6+i,str7_2[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    for(int i=0;i<strlen(str8);i++)
    {
        mvaddch(14,4+i,str8[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    napms(300);

    for (int i=0;;i++)
    {
        if (i%2==0)
        {
            for(int j=0;j<strlen(next);j++)
                mvaddch(20,60+j,next[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(empstr);j++)
                mvaddch(20,60+j,empstr[j]);
            refresh();
        }
        napms(300);
        nextpage=getch();
        if (nextpage!=ERR) break;
    }
    erase();
    patience=true;

    for(int i=0;i<strlen(str9);i++)
    {
        mvaddch(8,4+i,str9[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    for(int i=0;i<strlen(str10);i++)
    {
        mvaddch(10,4+i,str10[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    for(int i=0;i<strlen(str10_2);i++)
    {
        mvaddch(12,6+i,str10_2[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    for(int i=0;i<strlen(str11);i++)
    {
        mvaddch(14,4+i,str11[i]);
        refresh();
        if (patience==TRUE) napms(50);
        jump=getch();
        if (jump!=ERR) patience=false;
    }
    napms(300);

    for (int i=0;;i++)
    {
        if (i%2==0)
        {
            for(int j=0;j<strlen(next);j++)
                mvaddch(20,60+j,next[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(empstr);j++)
                mvaddch(20,60+j,empstr[j]);
            refresh();
        }
        napms(300);
        nextpage=getch();
        if (nextpage!=ERR) break;
    }
    erase();
    patience=true;

    curs_set(1);
    char p;
    mvprintw(10,23,"Intrigued ?");
    mvprintw(15,23,"Press M to go to menu and have fun.");

    while(1)
    {
        p=getch();
        if (p=='m'||p=='M')
        {
            erase();
            curs_set(0);
            break;
        }
    }
}


void GameStart()
{
    char p,clean_buffer;
    char welcome[]={"Welcome to  TILT TO PASS"};
    char welcome2[]={"Press Any Key to Start"};
    char emptystr[]={"                      "};

    for(int i=0;i<strlen(welcome);i++)
    {
        mvaddch(12,25+i,welcome[i]);
        refresh();
        napms(190);
        clean_buffer=getch();
    }
    napms(700);
    for(int i=0;i<strlen(welcome2);i++)
    {
        mvaddch(16,26+i,welcome2[i]);
        refresh();
        napms(175);
        clean_buffer=getch();
    }

    for (int i=0;;i++)
    {
        curs_set(0);
        if (i%2==0)
        {
            for(int j=0;j<strlen(welcome2);j++)
                mvaddch(16,26+j,welcome2[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(emptystr);j++)
                mvaddch(16,26+j,emptystr[j]);
            refresh();
        }
        napms(600);

        p=getch();
        if (p!=ERR) break;

    }

    erase();
}

char Exit_Game()
{
    char c;
    erase();
    mvprintw(14,19,"Are you sure to quit this fantastic game? (y/n)");
    refresh();
    while(true)
    {
        c=getch();
        if (c!=ERR) break;
    }
    return c;
}

void menu(mode modetest)
{
    int c;
    int x=10,y=18;

    curs_set(0);
    while(1)
    {
        c=getch();
        if (c==ERR)
        {
            mvaddch(x,y,'>');
        }
        else if (c==KEY_DOWN)
        {
            erase();
            if(x!=26)
            {
                x+=4;
                mvaddch(x,y,'>');
            }
        }
        else if (c==KEY_UP)
        {
            erase();
            if(x!=10)
            {
                x-=4;
                mvaddch(x,y,'>');
            }
        }
        else if (c=='\n')
        {
            if(x==10)
            {
                erase();
                modetest.mode_1();//Single_Classic_Mode();
            }
            else if(x==14)
            {
                erase();
                modetest.mode_2();//Double_Weapon_Mode();
            }
            else if(x==18)
            {
                erase();
                modetest.mode_3();// Double_Deathmatch_Mode();
            }
            else if(x==22)
            {
                erase();
                Game_Instruction();
            }
            else if(x==26)
            {
                erase();
                char exit = Exit_Game();
                if (exit=='Y'||exit=='y') noplay=1;
                erase();
                refresh();
            }
            else
            {
                continue;
            }
        }

        mvprintw(10,40,"Single Classic Mode");
        mvprintw(14,40,"Double Weapon Mode");
        mvprintw(18,40,"Double Deathmatch Mode");
        mvprintw(22,40,"How To Play");
        mvprintw(26,40,"Exit Game");
        refresh();
        if (noplay==1) {erase();break;}
    }
}



