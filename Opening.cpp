#include"Tilt to Pass.h"

void set_color()
{
    start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_YELLOW);
    init_pair(4, COLOR_MAGENTA, COLOR_YELLOW+8);
    init_pair(5, COLOR_MAGENTA, COLOR_GREEN);
    init_pair(6, COLOR_MAGENTA, COLOR_GREEN+8);
    init_pair(7, COLOR_MAGENTA, COLOR_CYAN);
    init_pair(8, COLOR_MAGENTA, COLOR_CYAN+8);
    init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(10, COLOR_MAGENTA, COLOR_MAGENTA+8);
    init_pair(11, COLOR_MAGENTA, COLOR_RED);
    init_pair(12, COLOR_MAGENTA, COLOR_RED+8);
    init_pair(13, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(14, COLOR_MAGENTA, COLOR_BLUE+8);
    /*init_pair(15, COLOR_MAGENTA, COLOR_BLACK);*/
    init_pair(17, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(18, COLOR_MAGENTA, COLOR_WHITE+8);
    init_pair(20,COLOR_WHITE, COLOR_BLACK);
    /*init_pair(31, COLOR_CYAN, COLOR_WHITE);
    init_pair(32, COLOR_CYAN, COLOR_WHITE+8);
    init_pair(33, COLOR_CYAN, COLOR_YELLOW);*/
    init_pair(34, COLOR_CYAN, COLOR_YELLOW+8);
    /*init_pair(35, COLOR_CYAN, COLOR_GREEN);
    init_pair(36, COLOR_CYAN, COLOR_GREEN+8);*/
    init_pair(37, COLOR_CYAN, COLOR_CYAN);
    /*init_pair(38, COLOR_CYAN, COLOR_CYAN+8);*/
    init_pair(39, COLOR_CYAN, COLOR_MAGENTA);
    /*init_pair(40, COLOR_CYAN, COLOR_MAGENTA+8);*/
    init_pair(41, COLOR_CYAN, COLOR_RED);
    /*init_pair(42, COLOR_CYAN, COLOR_RED+8);
    init_pair(43, COLOR_CYAN, COLOR_BLUE);*/
    init_pair(44, COLOR_CYAN, COLOR_BLUE+8);
    /*init_pair(45, COLOR_CYAN, COLOR_BLACK);
    init_pair(51, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(52, COLOR_CYAN, COLOR_BLACK);
    init_pair(53, COLOR_YELLOW, COLOR_BLACK);*/
}

void opening(){

    int w[100][100]={COLOR_PAIR(20)};

    w[3][0]=w[3][1]=w[3][2]=w[3][3]=w[3][4]=w[3][5]=
    w[4][0]=w[4][1]=w[4][2]=w[4][3]=w[4][4]=w[4][5]=
    w[0][2]=w[1][2]=w[2][2]=w[3][2]=w[4][2]=w[5][2]=w[6][2]=
    w[7][2]=w[8][2]=w[9][2]=w[10][2]=w[11][2]=
    w[12][2]=w[13][2]=
    w[11][3]=w[14][3]=w[12][3]=w[13][3]=
    w[10][4]=w[11][4]=w[12][4]=w[13][4]=
    w[8][5]=w[9][5]=w[10][5]=w[11][5]=w[12][5]=COLOR_PAIR(17);

    w[3][7]=w[4][7]=w[5][7]=w[2][7]=
    w[3][8]=w[4][8]=w[5][8]=w[2][8]=
    w[7][7]=w[8][7]=w[9][7]=w[10][7]=
    w[11][7]=w[12][7]=w[13][7]=w[14][7]=w[15][7]=
    w[9][6]=w[10][6]=w[11][6]=w[12][6]=w[13][6]=w[14][6]=
    w[13][8]=w[14][8]=w[15][8]=w[7][8]=COLOR_PAIR(18);

    w[0][11]=w[1][11]=w[2][11]=w[3][11]=w[4][11]=w[5][11]=
    w[6][11]=w[7][11]=w[8][11]=w[9][11]=w[10][11]=w[11][11]=
    w[12][11]=w[13][11]=w[14][11]=
    w[13][9]=w[14][9]=w[13][10]=w[14][10]=w[13][12]=w[14][12]=w[13][13]=w[14][13]=
    w[2][9]=w[2][10]=w[1][10]=COLOR_PAIR(17);

    w[0][14]=w[1][14]=w[2][14]=w[3][14]=w[4][14]=w[5][14]=
    w[6][14]=w[7][14]=w[8][14]=w[9][14]=w[10][14]=w[11][14]=
    w[3][12]=w[4][12]=
    w[3][13]=w[4][13]=w[3][15]=w[4][15]=w[3][16]=w[4][16]=w[2][16]=
    w[7][16]=w[8][16]=w[9][16]=w[10][16]=w[11][16]=
    w[9][15]=w[10][15]=w[11][15]=w[12][15]=COLOR_PAIR(18);

    w[15][12]=w[16][12]=w[17][12]=w[18][12]=w[19][12]=w[20][12]=w[21][12]=
    w[16][10]=w[17][10]=w[16][11]=w[17][11]=w[16][13]=w[17][13]=w[16][14]=w[17][14]=
    w[21][13]=w[22][13]=w[20][14]=w[21][14]=COLOR_PAIR(18);

    w[15][15]=w[16][15]=w[17][15]=w[18][15]=w[19][15]=w[20][15]=
    w[15][17]=w[16][17]=w[17][17]=w[18][17]=w[19][17]=w[20][17]=
    w[14][16]=w[15][16]=w[20][16]=w[21][16]=COLOR_PAIR(17);

    w[18][18]=w[19][18]=w[20][18]=w[21][18]=w[22][18]=
    w[23][18]=w[24][18]=w[25][18]=w[26][18]=w[27][18]=w[28][18]=
    w[29][18]=w[30][18]=w[31][18]=w[32][18]=
    w[21][17]=w[22][17]=w[23][17]=w[24][17]=w[25][17]=w[26][17]=
    w[27][17]=w[28][17]=w[29][17]=w[30][17]=w[31][17]=w[32][17]=
    w[18][19]=w[19][19]=w[25][19]=w[26][19]=
    w[18][20]=w[19][20]=w[25][20]=w[26][20]=
    w[19][21]=w[20][21]=w[21][21]=w[22][21]=w[23][21]=w[24][21]=w[25][21]=
    w[20][22]=w[21][22]=w[22][22]=w[23][22]=w[24][22]=COLOR_PAIR(18);

    w[25][22]=w[26][22]=w[27][22]=w[28][22]=w[29][22]=
    w[30][22]=w[31][22]=w[32][22]=
    w[23][23]=w[24][23]=w[25][23]=w[25][23]=w[26][23]=
    w[27][23]=w[28][23]=w[29][23]=w[30][23]=w[31][23]=w[32][23]=
    w[22][24]=w[23][24]=w[27][24]=w[28][24]=w[29][24]=
    w[22][25]=w[23][25]=w[27][25]=w[28][25]=w[29][25]=
    w[22][26]=w[23][26]=w[27][26]=w[28][26]=w[29][26]=
    w[23][27]=w[24][27]=w[25][27]=w[25][27]=w[26][27]=
    w[27][27]=w[28][27]=w[29][27]=w[30][27]=w[31][27]=w[32][27]=
    w[25][28]=w[26][28]=w[27][28]=w[28][28]=w[29][28]=
    w[30][28]=w[31][28]=w[32][28]=COLOR_PAIR(17);

    w[23][29]=w[24][29]=w[25][29]=w[26][29]=w[29][29]=w[30][29]=w[31][29]=
    w[22][30]=w[23][30]=w[26][30]=w[27][30]=w[31][30]=w[32][30]=
    w[23][31]=w[24][31]=w[27][31]=w[28][31]=w[29][31]=w[30][31]=w[31][31]=COLOR_PAIR(18);

    w[18][32]=w[19][32]=w[20][32]=w[21][32]=w[22][32]=
    w[26][32]=w[27][32]=w[28][32]=w[29][32]=
    w[17][33]=w[18][33]=w[19][33]=w[22][33]=w[22][33]=
    w[28][33]=w[29][33]=w[30][33]=
    w[16][34]=w[17][34]=w[18][34]=w[23][34]=w[24][34]=
    w[30][34]=w[31][34]=
    w[16][35]=w[17][35]=w[18][35]=w[25][35]=w[24][35]=
    w[30][35]=w[31][35]=
    w[17][36]=w[18][36]=w[19][36]=w[25][36]=w[26][36]=
    w[29][36]=w[30][36]=
    w[18][37]=w[19][37]=w[20][37]=w[21][37]=
    w[26][37]=w[27][37]=w[28][37]=w[29][37]=COLOR_PAIR(17);

    w[6][21]=w[7][21]=w[8][21]=w[9][21]=w[10][21]=w[11][21]=w[12][21]=
    w[13][21]=w[14][21]=
    w[8][22]=w[9][22]=w[10][22]=w[11][22]=w[12][22]=
    w[13][22]=w[14][22]=
    w[10][23]=w[11][23]=w[12][23]=
    w[13][23]=w[14][23]=
    w[9][24]=w[10][24]=w[11][24]=w[12][24]=
    w[13][24]=w[14][24]=
    w[7][25]=w[8][25]=w[9][25]=w[10][25]=w[11][25]=
    w[13][25]=w[14][25]=
    w[6][26]=w[7][26]=w[8][26]=w[9][26]=w[10][26]=w[14][26]=
    w[5][27]=w[6][27]=w[6][27]=w[7][27]=w[8][27]=
    w[4][28]=w[5][28]=w[6][28]=w[7][28]=
    w[5][29]=w[6][29]=COLOR_PAIR(37);

    w[22][4]=w[23][4]=w[24][4]=w[25][4]=w[26][4]=
    w[27][4]=w[28][4]=w[29][4]=w[30][4]=
    w[22][5]=w[23][5]=w[22][6]=w[23][6]=
    w[26][5]=w[27][5]=w[26][6]=w[27][6]=COLOR_PAIR(41);

    w[23][9]=w[26][9]=w[27][9]=w[29][9]=
    w[24][8]=w[24][10]=w[25][10]=COLOR_PAIR(34);

    char loading[]="Loading...";
    char emptyload[]="          ";
    char p2;
    for (int i=0;i<10;i++)
    {
        curs_set(0);
        if (i%2==0)
        {
            for(int j=0;j<strlen(loading);j++)
                mvaddch(14,32+j,loading[j]);
            refresh();
        }
        else if (i%2==1)
        {
            for(int j=0;j<strlen(emptyload);j++)
                mvaddch(14,32+j,emptyload[j]);
            refresh();
        }
        napms(600);

        /*p2=getch();
        if (p2!=ERR) break;*/

    }

    for(int i=1;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            int m, n;
            m=i-1;
            n=(j-2)/2;
            mvaddch(i, j,' '|w[m][n]);
            refresh();
        }
    }
    napms(2000);

    for (int r=85;r>=7;r--)
    {
        for (int t=0;t<36;t++)
        {
            mvaddch(t,r,' '|COLOR_PAIR(20));
        }
        refresh();
        napms(30);
    }

    /*int b=0;
    while(b<33*37)
    {
        int shuffley=rand()%33;
        int shufflex=rand()%37;
        if(w[shuffley][shufflex]==' '|COLOR_PAIR(20))
        {
            w[shuffley][shufflex]==COLOR_PAIR(20);
            mvaddch(shuffley+3, shufflex*2+7,' '|w[shuffley][shufflex]);
            refresh();
            napms(100);
            b++;
        }
    }*/
}

