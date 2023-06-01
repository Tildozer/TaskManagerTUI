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
//I created functions to make each menu, so I could switch between menus with just one function call.
    vector<WINDOW *> mainMenu(int yMax, int xMax) {
        int oneThird = xMax / 3;
        int oneFifth = yMax / 5;

        WINDOW *createTask = newwin(oneFifth, oneThird - 1, 0, 0);
        WINDOW *viewAllTask = newwin(oneFifth, oneThird - 1, 0, oneThird + 1);
        WINDOW *editTask = newwin(oneFifth, oneThird - 1, 0, (oneThird) * 2 + 1);
        WINDOW *controls = newwin(3, xMax, yMax - 3, 0);
        vector<WINDOW *> mainMenu{createTask, viewAllTask, editTask, controls};

        return mainMenu;
    }

namespace MenuBar {

    void makeMenu(const vector<WINDOW *> &wins, vector<const char *> &menuInfo) {
        for (int i = 0; i < wins.size(); ++i) {
            box(wins[i], 0, 0);
            refresh();
            mvwprintw(wins[i], 1, 2, menuInfo[i]);
            wrefresh(wins[i]);
            refresh();
        }
    }

    void selectMenu(int selection, int yMax, int xMax) {
        clear();
        refresh();
        switch (selection) {
            case 1: {
                auto create{"- Create a task"},
                        all{"- View all task"},
                        edit{"- Edit a task"},
                        ctrl{"[ Esc - Exit ] [ c - CreateTask] [ a - see all ] [ e - edit task ]"};

                vector<const char *> mainMenuInfo{create, all, edit, ctrl};
                vector<WINDOW *> currMenu {mainMenu(yMax, xMax)};
                makeMenu(currMenu, mainMenuInfo);
                break;
            }
            case 2: {
                auto ctrlCreate{" [ tab -> - next ]"};

                vector<const char *> createMenuInfo{ctrlCreate};
            }
            default : {
                break;
            }
        }
    }
}

#endif //TASKMANAGERTUI_MENU_H
