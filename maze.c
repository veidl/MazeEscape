//
//  maze.c
//  MazeG
//
//  Created by Thomas Polzer
//  Copyright © 2020 Thomas Polzer. All rights reserved.
//

#include "maze.h"
#include <stdio.h>
#include <memory.h>
#include <zconf.h>

char maze[ROWS][COLS];
char trail[ROWS][COLS];

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
    return maze[row][col] != WALL
           && trail[row][col] != DEAD_END
           && trail[row][col] != START;
}

// recursive escape algorithm using backtracking
int escape(int row, int col) {
    print();
    sleep(1);
    // Abbruchbedingung
    if (maze[row][col] == EXIT) {
        printf("found a way out \n");
        return 1;
    }

    // go north
    if (isAllowed(row - 1, col) == 1) {
        maze[row][col] = WAY;
        trail[row][col] = DEAD_END;
        if (escape(row - 1, col)) {
            return 1;
        }
    }
    // go east
    if (isAllowed(row, col + 1) == 1) {
        maze[row][col] = WAY;
        trail[row][col] = DEAD_END;

        if (escape(row, col + 1)) {
            return 1;
        }
    }
    // go south
    if (isAllowed(row + 1, col) == 1) {
        maze[row][col] = WAY;
        trail[row][col] = DEAD_END;
        if (escape(row + 1, col)) {
            return 1;
        }
    }
    // go west
    if (isAllowed(row, col - 1) == 1) {
        maze[row][col] = WAY;
        trail[row][col] = DEAD_END;
        if (escape(row, col - 1)) {
            return 1;
        }
    }
    maze[row][col] = DEAD_END;
    trail[row][col] = DEAD_END;

    return 0;
}
