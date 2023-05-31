//
// Created by Anthony Thibodeaux on 5/30/23.
//

#include <curses.h>
#include <csignal>
#include <termios.h>
#include <map>

#ifndef TASKMANAGERTUI_MENU_H
#define TASKMANAGERTUI_MENU_H

using namespace std;


namespace MenuBar {
    map<string, WINDOW *> MakeMenu() {
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);
        int oneThird = xMax/3;
        int oneTenth = yMax/10;
        WINDOW *createTask = newwin(oneTenth, oneThird, 0, 0);
        WINDOW *viewAllTask = newwin(oneTenth, oneThird, 0, oneThird + 1);
        WINDOW *viewDayTask = newwin(oneTenth, oneThird, 0, (oneThird + 1) * 2);

        box(createTask, 0, 0);
        box(viewAllTask, 0, 0);
        box(viewDayTask, 0, 0);
        wgetch(createTask);
        wgetch(viewAllTask);
        wgetch(viewDayTask);
        wprintw(createTask, "+ create task");
        wprintw(viewAllTask, "- see all tasks");
        wprintw(viewDayTask, "- Today's task");
        wrefresh(createTask);
        wrefresh(viewAllTask);
        wrefresh(viewDayTask);
        return {{"create", createTask}, {"all",viewAllTask}, {"day",viewDayTask}};
    }
}

#endif //TASKMANAGERTUI_MENU_H
