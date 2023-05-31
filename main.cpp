#include <iostream>
#include <curses.h>
#include <csignal>
#include <termios.h>
#include <cmath>
#include <future>
#include "menu.h"

using namespace std;
using namespace MenuBar;

static void finish(int sig);

int main(int args, char *argv[]) {
    /* initialize your non-curses data structures here */
    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();      /* initialize the curses library */
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) noecho();         /* echo input - in color */
    (void) keypad(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    map<string, WINDOW *> menu = MakeMenu(yMax, xMax);
    bool selected{false};
    bool exit{false};
    int x{0}, y{(yMax / 5) * 2};

    move(y, x);
    while (!selected && !exit) {
        int c = getch();
        if (c != 410 && c != -1) {
            switch (c) {
                case 258:
                case 259:
                    break;
                case 277:
                    exit = true;
                    break;
                case 13:
                    selected = true;
                    break;
                case 127:
                    if (x == 0) {
                        if (y > 5) {
                            x = 20;
                            mvprintw(y, x, "\b");
                        }
                    } else {
                        mvprintw(y, x, "\b ");
                        --x;
                    }
                    break;
                default:
                    if (x == 20) {
                        x = 0;
                        y++;
                    }
                    mvprintw(y, x, "%c", char(c));
                    x++;
            }
            mvprintw(yMax / 5 + 2, 0, "%i", c);
            move(y, x);
        }
        /* process the command keystroke */
    }

    finish(0);               /* we are done */
    return 0;
}

static void finish(int sig) {
    endwin();

    /* do your non-curses wrap up here */

    exit(0);
}
