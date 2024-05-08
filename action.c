#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void markPos(struct pos *pos) 
{
    pos->pheremone = true;
}

void move_F(struct pos *pos) {
    pos->x += 1;
}

void move_B(struct pos *pos) {
    pos->x -= 1;
}

void move_L(struct pos *pos) {
    pos->y -= 1;
}

void move_R(struct pos *pos) {
    pos->y += 1;
}

//I did not add the whole itch thing yet, just a rough outline.
void MOVE_F(struct pos *antPOS, int **maze)
{
    int count = CWF(antPOS, maze);
    while (count>0)
    {
        antPOS->x+=1;
        antPOS->pheremone = true;
        count--;
    }
}


int CWR(struct pos *antPOS, int **maze)
{
    int count = 0;
    int x = antPOS->x;
    int y = antPOS->y;

    // Iterate through the row until a non-wall element is encountered
    while (maze[x][y] != 1)
    {
        count++;
        y += 1; //Move to the right by going through column values
    }

    return count;
}

int CWL(struct pos *antPOS, int **maze)
{
    int count = 0;
    int x = antPOS->x;
    int y = antPOS->y;

    // Iterate through the row until a non-wall element is encountered
    while (maze[x][y] != 1 || y == -1)
    {
        count++;
        y -= 1; //Move to the left by going through column values
    }

    return count;
}

int CWF(struct pos *antPOS, int **maze)
{
    int count = 0;
    int x = antPOS->x;
    int y = antPOS->y;

    // Iterate through the row until a non-wall element is encountered
    while (maze[x][y] != 1)
    {
        count++;
        x += 1; //Move to the up by going through row values
    }

    return count;
}

int CWB(struct pos *antPOS, int **maze)
{
    int count = 0;
    int x = antPOS->x;
    int y = antPOS->y;

    // Iterate through the row until a non-wall element is encountered
    while (maze[x][y] != 1 || x == -1)
    {
        count++;
        x -= 1; //Move to the left by going through column values
    }

    return count;
}