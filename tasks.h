//
// Created by Anthony Thibodeaux on 6/8/23.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef TASKMANAGERTUI_TASKS_H
#define TASKMANAGERTUI_TASKS_H

class Task {
    string name;
    string details;
    string completionDate;
};

void saveTasks(const vector<Task> &data) {
    ofstream outputFile("tasks.bin" ,ios::binary);

    if(outputFile.is_open()){

    } else {
        cout << "Failed to open the tasks file";
    }

}

#endif //TASKMANAGERTUI_TASKS_H
