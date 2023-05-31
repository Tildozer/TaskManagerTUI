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

    void MakeMenu(const vector<WINDOW *> &wins, vector<const char *> &menuInfo) {
        for (int i = 0; i < wins.size(); ++i) {
            box(wins[i], 0, 0);
            refresh();
            mvwprintw(wins[i], 1, 2, menuInfo[i]);
            wrefresh(wins[i]);
            refresh();
        }
    }
}

#endif //TASKMANAGERTUI_MENU_H
