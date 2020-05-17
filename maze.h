//
//  maze.h
//  MazeG
//
//  Created by Michael Strommer on 05.05.20.
//  Copyright © 2020 Michael Strommer. All rights reserved.
//

#ifndef _MAZE_H
#define _MAZE_H

// STRUKTUREN

// DEFINES
#define ROWS 10
#define COLS 10

enum {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
}; // 0...3 optional
enum {
    WALL = '#', DEAD_END = 'X', WAY = '.', EXIT = 'T', START = 'S'
};

// PROTOTYPEN
void print(void);

int escape(int row, int col);

int isAllowed(int row, int col);

void init(char begin[ROWS][COLS]);
//... weitere Hilfsfunktionen


#endif /* maze_h */
