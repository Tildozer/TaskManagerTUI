#include <iostream>
#include <curses.h>
#include <csignal>
//#include <termios.h>
#include <cmath>
//#include <future>
#include "menus.h"

using namespace std;

static void finish(int sig);

int main() {
    /* initialize your non-curses data structures here */
    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();
    start_color();/* initialize the curses library */
    use_default_colors();
    init_pair(1, COLOR_MAGENTA, -1);

    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) noecho();         /* echo input - in color */
    (void) keypad(stdscr, TRUE);
    scrollok(stdscr, FALSE);
    int mainMenu = 1;
    selectMenu(mainMenu);

    finish(0);               /* we are done */
    return 0;
}

static void finish(int sig) {
    endwin();

    /* do your non-curses wrap up here */
    exit(0);
}
