//
// Created by Anthony Thibodeaux on 5/30/23.
//

#include <curses.h>
#include <csignal>
#include <termios.h>
#include <map>
#include <string>
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

static void creationMenuHelper(vector<WINDOW *> &wins);

void selectMenu(int selection) {
    clear();
    refresh();
    switch (selection) {
        case 1: {
            auto create{"- Create a task"};
            auto all{"- View all task"};
            auto edit{"- Edit a task"};
            auto ctrl{"[ Esc - Exit ] [ c - CreateTask] [ a - see all ] [ e - edit task ]"};
            vector<const char *> mainMenuInfo{create, all, edit, ctrl};
            vector<WINDOW *> currMenu{mainMenu()};

            makeMenu(currMenu, mainMenuInfo);
            return mainMenuHelper();
        }
        case 2: {
            vector<WINDOW *> currentMenu{creationMenu()};
            auto blank{""};
            auto ctrlCreate{" [ tab -> - next ] [ Esc - main menu ]"};
            vector<const char *> createMenuInfo{blank, blank, blank, ctrlCreate};

            makeMenu(currentMenu, createMenuInfo);
            return creationMenuHelper(currentMenu);
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
            return selectMenu(2);
        }
//                presses e
        case 101: {
            break;
        }
        default:
            mvprintw(yMax / 5 + 2, 0, "%i", c);
            move(y, x);
            return mainMenuHelper();
    }

};

static void creationMenuHelper(vector<WINDOW *> &wins) {
    int c = getch();
    switch (c) {
        case 27: {
            return selectMenu(1);
        }
        case 9: {
            string name = getDetail(wins[0], 50);
            string details = getDetail(wins[1], 250);
            string completionDate = getDetail(wins[2], 10);
            
            move(0, 0);
            getch();
            break;
        }
        default: {
            printw("%i", c);
            return creationMenuHelper(wins);
        }

    }
}

#endif //TASKMANAGERTUI_MENU_H
