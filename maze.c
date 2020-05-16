//
//  maze.c
//  MazeG
//
//  Created by Michael Strommer on 05.05.20.
//  Copyright © 2020 Michael Strommer. All rights reserved.
//

#include "maze.h"
#include <stdio.h>
#include <memory.h>

char maze[ROWS][COLS];
char trail[ROWS][COLS];
int DIRECTION = 0;

// init function
void init(char begin[ROWS][COLS]) {
    memcpy(maze, begin, sizeof(maze));
}

// print maze
void print() {
    int i = 0, j = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c", maze[i][j]);
        }
        printf("\n");
    }
}

int isAllowed(int row, int col) {
    return maze[row][col] != '#'
           && row < ROWS
           && maze[row][col] != '#'
           && col < COLS
           && maze[row][col] != 'T'
           && trail[row][col] != 'X';

}

// recursive escape algorithm using backtracking
int escape(int row, int col) {
    print();
    // Abbruchbedingung
    if (maze[row][col] == 'T') {
        printf("found solution \n");
        return 1;
    }
    // check if valid
    if (isAllowed(row, col) == 1) {
        maze[row][col] = '.';
        trail[row][col] = 'X';

        if (escape(row - 1, col)) {
            return 1;
        }
        if (escape(row, col + 1)) {
            return 1;
        }
        if (escape(row + 1, col)) {
            return 1;
        }
        if (escape(row, col - 1)) {
            return 1;
        }
        maze[row][col] = 'X';
    }
    return 0;
}
