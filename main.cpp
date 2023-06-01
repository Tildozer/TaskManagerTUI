#include <iostream>
#include <curses.h>
#include <csignal>
//#include <termios.h>
#include <cmath>
//#include <future>
#include "menu.h"

using namespace std;
using namespace MenuBar;

static void finish(int sig);

int main() {
    /* initialize your non-curses data structures here */
    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();
    start_color();/* initialize the curses library */
    use_default_colors();
    init_pair(1, COLOR_MAGENTA, -1);
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) noecho();         /* echo input - in color */
    (void) keypad(stdscr, TRUE);
    scrollok(stdscr, FALSE);
    int mainMenu = 1;
    selectMenu(mainMenu);

    bool exit{false};
    int x{0}, y{yMax - 4};

    move(y, x);
    while (!exit) {
        int c = getch();
        if (c != 410 && c != -1) {
            switch (c) {
//                Esc || Enter
                case 27:
                case 13:
                    exit = true;
                    break;
//                    backspace
//                    probably not needed here.
                case 127: {
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
                }
//                presses c
                case 99: {
                    selectMenu(2);
                    break;
                }
                case 97: {
                    break;
                }
                case 101: {
                    break;
                }
                default:
                    break;
            }
            mvprintw(yMax / 5 + 2, 0, "%i", c);
            move(y, x);
        }
    }

    finish(0);               /* we are done */
    return 0;
}

static void finish(int sig) {
    endwin();

    /* do your non-curses wrap up here */
    exit(0);
}
