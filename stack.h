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

typedef struct
{
    char commands[MAX_SIZE];
    int actTop;

} intStack;

//All methods created for the stack and position structures
void initialize(struct memStack *s);
void initialInt(intStack *i);

bool isEmpty(struct memStack *s);
bool isEmptyInt(intStack *i);
bool isFull(struct memStack *s);
bool isFullInt(intStack *i);

void push(struct memStack *s, struct pos pos);
void pushInt(intStack *i, char *str);
char* popInt(intStack *i);
char* peekInt(intStack *i);
struct pos pop(struct memStack *s);
struct pos peek(struct memStack *s);

void markedPos(struct pos pos);

void clear(struct memStack *s);
void clearInt(intStack *i);

#endif