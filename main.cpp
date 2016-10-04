#include"Tilt to Pass.h"
#define NDEBUG
using namespace std;


int main()
{

    mode modetest;
    init();
    curs_set(0);
    set_color();
    //opening();

    erase();

    curs_set(1);
    //GameStart();
    curs_set(0);

    menu(modetest);

    erase();
    refresh();
    endwin();
    return 0;

}
