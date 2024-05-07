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

void MOVE_F(struct pos *antPOS)
{
    while (CWF>0)
        antPOS->x+=1;
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
        y += 1; //Move to the right by going through column values
    }

    return count;
}


void move_B(struct pos *pos) {

}