#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 100

//Position of each value in the 2D ARRAY
struct pos 
{
    int x;
    int y;
    bool pheremone;
};

//Stack structure for Michael
struct memStack 
{
    struct pos items[MAX_SIZE];
    int top;
};

//All methods created for the stack and position structures
void initialize(struct memStack *s);
bool isEmpty(struct memStack *s);
bool isFull(struct memStack *s);
void push(struct memStack *s, struct pos pos);
struct pos pop(struct memStack *s);
struct pos peek(struct memStack *s);
void markedPos(struct pos pos);
void clear(struct memStack *s);

#endif