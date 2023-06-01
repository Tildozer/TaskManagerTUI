//
// Created by Anthony Thibodeaux on 5/31/23.
//
#include <curses.h>
#include <csignal>
#include <termios.h>
#include <map>

using namespace std;
#ifndef TASKMANAGERTUI_CREATEMENU_H
#define TASKMANAGERTUI_CREATEMENU_H

vector<WINDOW *> creationMenu() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *ctrlMenu = newwin(5, xMax, yMax - 5, 0);

    return {ctrlMenu};
}

#endif //TASKMANAGERTUI_CREATEMENU_H
