//
// Created by Anthony Thibodeaux on 5/30/23.
//

#include <curses.h>
#include <csignal>
#include <termios.h>
#include <map>
#include "mainMenu.h"
#include "createMenu.h"

#ifndef TASKMANAGERTUI_MENU_H
#define TASKMANAGERTUI_MENU_H

using namespace std;

void makeMenu(const vector<WINDOW *> &wins, vector<const char *> &menuInfo) {

    for (int i = 0; i < wins.size(); ++i) {
        wattrset(wins[i], COLOR_PAIR(1));
        box(wins[i], 0, 0);
        wattrset(wins[i], COLOR_PAIR(1));
        refresh();
        mvwprintw(wins[i], 1, 2, menuInfo[i]);
        wrefresh(wins[i]);
        refresh();
    }
}

static void mainMenuHelper();

void selectMenu(int selection) {
    clear();
    refresh();
    switch (selection) {
        case 1: {
            auto create{"- Create a task"},
                    all{"- View all task"},
                    edit{"- Edit a task"},
                    ctrl{"[ Esc - Exit ] [ c - CreateTask] [ a - see all ] [ e - edit task ]"};
            vector<const char *> mainMenuInfo{create, all, edit, ctrl};
            vector<WINDOW *> currMenu{mainMenu()};

            makeMenu(currMenu, mainMenuInfo);
            mainMenuHelper();
            break;
        }
        case 2: {
            vector<WINDOW *> currMenu{creationMenu()};
            auto ctrlCreate{" [ tab -> - next ]"};
            vector<const char *> createMenuInfo{ctrlCreate};

            makeMenu(currMenu, createMenuInfo);
            getch();
            break;
        }
        default : {
            break;
        }
    }
}
//}

static void mainMenuHelper() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int x{0}, y{yMax - 4};

    move(y, x);
        int c = getch();
        switch (c) {
//                Esc || Enter
            case 27:
            case 13:
                break;
//                presses a
            case 97: {
                break;
            }
//                presses c
            case 99: {
                selectMenu(2);
                break;
            }
//                presses e
            case 101: {
                break;
            }
            default:
                mainMenuHelper();
                break;
        }
        mvprintw(yMax / 5 + 2, 0, "%i", c);
        move(y, x);
};

#endif //TASKMANAGERTUI_MENU_H
