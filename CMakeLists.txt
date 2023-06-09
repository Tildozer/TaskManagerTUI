cmake_minimum_required(VERSION 3.25)
project(TaskManagerTUI)

find_package(Curses REQUIRED)

set(CMAKE_CXX_STANDARD 20 "-lncurses")

add_executable(TaskManagerTUI main.cpp menus.h mainMenu.h createMenu.h tasks.h)

target_link_libraries(TaskManagerTUI PRIVATE ${CURSES_LIBRARIES})

target_include_directories(TaskManagerTUI PRIVATE ${CURSES_INCLUDE_DIRS})