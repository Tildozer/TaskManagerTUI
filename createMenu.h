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

    auto name {"Name of task:"};
    mvwprintw(stdscr, 1, 0, name);
    WINDOW *nameBox {newwin(3, xMax - 14, 0, 13)};

    auto details {"Details of task:"};
    mvwprintw(stdscr, 4, 0, details);
    WINDOW *taskDetails {newwin(5, xMax - 17, 3, 16)};

    auto completionDate {"Goal day to complete:"};
    mvwprintw(stdscr, 9, 0, completionDate);
    WINDOW *goalCompletionDate {newwin(5, xMax - 21, 8, 21)};

    WINDOW *ctrlMenu{newwin(3, xMax, yMax - 3, 0)};
    move(yMax - 4, 0);
    return {nameBox, taskDetails, goalCompletionDate, ctrlMenu};
}

#endif //TASKMANAGERTUI_CREATEMENU_H
