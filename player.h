#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
  public:
    Player(WINDOW * win, int y, int x, char c);

    void mvup();
    void mvdown();
    void mvleft();
    void mvright();

    int getmv();
    void display();

  private:
    char step;
    int yLoc, xLoc, yMax, xMax;
    char carecter;
    WINDOW * playerwin;

};
/*
Player::Player(WINDOW * win, int y, int x, char c)
{
    playerwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(playerwin, yMax, xMax);
    keypad(playerwin, true);

    carecter = c;
    display();
}
void Player::mvdown(){
    mvwaddch(playerwin, yLoc, xLoc, '.');
    yLoc++;
    if (yLoc > yMax-2)
        yLoc = yMax-2;
}

void Player::mvup(){
    mvwaddch(playerwin, yLoc, xLoc, '.');
    yLoc--;
    if (yLoc < 1)
        yLoc = 1;
}

void Player::mvleft(){
    mvwaddch(playerwin, yLoc, xLoc, '.');
    xLoc--;
    if (xLoc < 1)
        xLoc = 1;
}

void Player::mvright(){
    mvwaddch(playerwin, yLoc, xLoc, '.');
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
        default:
            break;
    }
    return key;
}

void Player::display()
{
    mvwaddch(playerwin, yLoc, xLoc, carecter);
    wrefresh(playerwin);
}
*/
#endif // _PLAYER_H_
