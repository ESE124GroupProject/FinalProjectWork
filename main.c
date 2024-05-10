#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void readIntel(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("ERROR: OPENING FILE ~ %s ~\n", filename);
        return;
    }

    char line[100]; // Assuming max line length is 100 characters
    char lines[100][100]; // Array to store lines, assuming max 100 lines each with 100 characters

    int count = 0; // Counter for the number of lines read

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Copy the line to the array of strings
        strcpy(lines[count], line);
      
        count++;
        
        // Check if the array is full (max 100 lines)
        if (count >= 100)
        {
            printf("WARNING: MAXIMUM NUMBER OF LINES REACHED\n");
            break;
        }
    }

    // Test print lines to see if the code is reading the lines
    // for (int i = 0; i < count; i++)
    // {
    //     printf("Line %d: %s", i+1, lines[i]);
    // }

    fclose(file); // Close the file after reading
}

int main()
{
    int maze[ROWS][COLS];
    readMaze(maze, "maze.txt");
    printMazeBinary(maze);

    readIntel("intelligence.txt");
    
}