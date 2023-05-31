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

    map<string, WINDOW *> MakeMenu(int yMax, int xMax) {
        int oneThird = xMax / 3;
        int oneFifth = yMax / 5;
        WINDOW *createTask = newwin(oneFifth, oneThird, 0, 0);
        WINDOW *viewAllTask = newwin(oneFifth, oneThird, 0, oneThird + 1);
        WINDOW *viewDayTask = newwin(oneFifth, oneThird, 0, (oneThird + 1) * 2);
        WINDOW *controls = newwin(3, xMax, yMax - 3, 0);
        box(createTask, 0, 0);
        box(viewAllTask, 0, 0);
        box(viewDayTask, 0, 0);
        box(controls, 0, 0);
        refresh();
        mvwprintw(createTask, 1, 2, "+ create task");
        mvwprintw(viewAllTask, 1, 2, "- see all tasks");
        mvwprintw(viewDayTask, 1, 2, "- Today's task");
        mvwprintw(controls, 1, 1, "[ Esc - Exit ]");
        wrefresh(createTask);
        wrefresh(viewAllTask);
        wrefresh(viewDayTask);
        wrefresh(controls);
        refresh();
        return {{"create",   createTask},
                {"all",      viewAllTask},
                {"day",      viewDayTask},
                {"controls", controls}};
    }
}

#endif //TASKMANAGERTUI_MENU_H
