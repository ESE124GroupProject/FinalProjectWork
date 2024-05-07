#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

#define ROWS 24
#define COLS 10

void readMaze(int maze[ROWS][COLS], const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("ERROR: OPENING FILE ~ %s ~\n", filename);
        return;
    }

    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            char c = ' ';
            fscanf(file, " %c", &c);

            maze[i][j] = (c == '*') ? 1 : (c == '_') ? 0 : (isdigit(c)) ? (c - '0') : -1;

        }
    }

    fclose(file);
} 

void printMazeBinary(const int maze[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
            printf("%d ", maze[i][j]);

        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS];
    readMaze(maze, "maze.txt");
    printMazeBinary(maze);

    //struct memStack *s;
    //initialize(s);
}