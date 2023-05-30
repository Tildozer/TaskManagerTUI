#include <iostream>
#include <curses.h>
#include <csignal>
#include <termios.h>
#include <cmath>


using namespace std;
//using namespace ;

static void finish(int sig);

int main(int args, char *argv[]) {
    int num = 0;

    /* initialize your non-curses data structures here */

    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) noecho();         /* echo input - in color */
    (void) keypad(stdscr, TRUE);

    if (has_colors())
    {
        start_color();

        /*
         * Simple color assignment, often all we need.  Color pair 0 cannot
         * be redefined.  This example uses the same value for the color
         * pair as for the foreground color, though of course that is not
         * necessary:
         */
        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    }

    bool saved {false};
    int x {0}, y {5};
    move(y, x);
    while (!saved) {
        int c = getch();
        attrset(COLOR_PAIR(num % 8));
        num++;
        if(c != 410 && c != -1) {
            switch (c) {
                case 13:
                    saved = true;
                    break;
                case 127:
                    printw("\b ");
                    x = max(0,--x);
                    break;
                case 27:
                    clrtoeol();
//                    y--;
                    break;
                default:
                    printw("%c", char(c));
                    x++;
                    move(y, x);
            }
            move(0, 0);
            printw("%i", x);
            move(y, x);
        }
//        refresh();
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
