#include <ncurses.h>
#include "player.h"


Player::Player(WINDOW * win, int y, int x, char c)
{
    playerwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(playerwin, yMax, xMax);
    keypad(playerwin, true);

    carecter = '#';
    step = '.';
    display();
}
void Player::mvdown(){
    mvwaddch(playerwin, yLoc, xLoc, step);
    yLoc++;
    if (yLoc > yMax-2)
        yLoc = yMax-2;
}

void Player::mvup(){
    mvwaddch(playerwin, yLoc, xLoc, step);
    yLoc--;
    if (yLoc < 1)
        yLoc = 1;
}

void Player::mvleft(){
    mvwaddch(playerwin, yLoc, xLoc, step);
    xLoc--;
    if (xLoc < 1)
        xLoc = 1;
}

void Player::mvright(){
    mvwaddch(playerwin, yLoc, xLoc, step);
    xLoc++;
    if (xLoc > xMax-2)
        xLoc = xMax-2;
}

int Player::getmv()
{
    int key = wgetch(playerwin);
    switch(key)
    {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case ' ':
            if (carecter == '#'){
                carecter = '*';
                step = ' ';
            }
            else if (carecter == '*'){
                carecter = '#';
                step = '.';
            }
            break;
        default:
            break;
    }
    if (mvwinch(playerwin, yLoc, xLoc) == '.')
        carecter = '=';
    return key;
}

void Player::display()
{
    mvwaddch(playerwin, yLoc, xLoc, carecter);
    wrefresh(playerwin);
}

