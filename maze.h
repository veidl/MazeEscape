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
    NORTH, EAST, SOUTH, WEST
}; // 0...3 optional

// PROTOTYPEN
void print(void);

int escape(int row, int col);

void init(char begin[ROWS][COLS]);
//... weitere Hilfsfunktionen


#endif /* maze_h */
