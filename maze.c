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

// recursive escape algorithm using backtracking
int escape(int row, int col) {
    print();
    // Abbruchbedingung
    if (maze[row][col] == 'T') {
        printf("found it brah");
        return 1;
    } else {
        maze[row][col] = (char) ".";
        return escape(row + 1, col + 1);
    }
    // Allgemeine Rekursionsvorschrift
    // Versuche nach Norden zu gehen
    // --war der Weg nach Norden erfolgreich? "Rote Faden" zurückgehen
    // Versuche nach Osten zu gehen
    // Versuche nach...

    // Backtracking wenn kein Weg gangbar war...
    // und ich kennzeichne Weg als Sackgasse
    return 0;
}
