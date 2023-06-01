//
// Created by Anthony Thibodeaux on 5/31/23.
//
#include <curses.h>
#include <csignal>
#include <termios.h>
#include <map>

using namespace std;
#ifndef TASKMANAGERTUI_MAINMENU_H
#define TASKMANAGERTUI_MAINMENU_H

vector<WINDOW *> mainMenu() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int oneThird = xMax / 3;
    int oneFifth = yMax / 5;

    WINDOW *createTask = newwin(oneFifth, oneThird - 1, 0, 0);
    WINDOW *viewAllTask = newwin(oneFifth, oneThird - 1, 0, oneThird + 1);
    WINDOW *editTask = newwin(oneFifth, oneThird - 1, 0, (oneThird) * 2 + 1);
    WINDOW *controls = newwin(3, xMax, yMax - 3, 0);

    return {createTask, viewAllTask, editTask, controls};
}


#endif //TASKMANAGERTUI_MAINMENU_H
