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
        for (int j = 0; j < COLS; j++) // goes through each element of the maze
        {
            char c = ' ';
            fscanf(file, " %c", &c);

            maze[i][j] = (c == '*') ? 1 : (c == '_') ? 0 : (c == ' ') ? 0 : (isdigit(c)) ? (c - '0') : -1; // assigns values to elements based on what they are

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

// Function to read commands from file and perform actions
void readCommandsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char commands[MAX_SIZE];

    while (fscanf(file, "%s", commands) != EOF)
        //Push Commands into intelligence stack
    

    fclose(file);
}

int main()
{
    int maze[ROWS][COLS];
    readMaze(maze, "maze.txt");
    printMazeBinary(maze);

    readCommandsFromFile("commands.txt");

}