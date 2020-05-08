cmake_minimum_required(VERSION 3.16)
project(MazeEscape C)

set(CMAKE_C_STANDARD 99)

add_executable(MazeEscape main.c maze.c maze.h)