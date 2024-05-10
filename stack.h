#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include "action.h"
#define MAX_SIZE 100

//Position of each value in the 2D ARRAY
typedef struct 
{
    int x;
    int y;
    bool pheremone;
} pos;

//Stack structure for Michael
typedef struct 
{
    pos items[MAX_SIZE];
    int top;
} memStack;

//All methods created for the stack and position structures
void initialize(memStack *s);
bool isEmpty(memStack *s);
bool isFull(memStack *s);
void push(memStack *s,pos pos);
pos pop(memStack *s);
pos peek(memStack *s);
void markedPos(pos pos);
void clear(memStack *s);

#endif