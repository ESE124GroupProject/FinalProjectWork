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
    int *currentPos = &maze[antPOS->x][antPOS->y]; // Pointer to the current position

    while (*currentPos == 1)
    {
        count++;
        currentPos++; // Move the pointer to the right
    }
    
    return count;
}

void move_B(struct pos *pos) {

}