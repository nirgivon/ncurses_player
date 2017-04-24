#include <ncurses.h>
#include <string>
#include "player.h"

using namespace std;

int main(int argc, char ** argv)
{
    /* start ncurses */
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // get screen size
    int yMax, xMax;
    int height = 15;
    int width = 40;
    getmaxyx(stdscr, yMax, xMax);

    // create a window for the player
    WINDOW * playwin = newwin(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2));
    box(playwin, '|', '-');
    refresh();
    wrefresh(playwin);

    Player * p = new Player(playwin, 1, 1, '*');\
    while(p->getmv() != 'x'){
        p->display();
    }

    endwin();
    /* end ncurses */

    return 0;
}

