#include "stack.h"
#include <stdio.h>

//initialize: Creates a stack with the top set to -1 for an empty stack
void initialize(struct memStack *s) 
{
    s->top = -1; // sets the value of variable 'top' from the pointer 's' to -1
}

void initialInt(intStack *i)
{
    i->actTop = -1;
}

//isEmpty: checks if the top of the stack is still equivalent to -1
bool isEmpty(struct memStack *s) 
{
    return s->top == -1;
}

bool isEmptyInt(intStack *i)
{
    return i->actTop == -1;
}

//isFull: checks if the top is equal to the MAX_SIZE, the -1 is for data storage starting at position 0
bool isFull(struct memStack *s)
{
    return s->top == MAX_SIZE - 1;
}

bool isFullInt(intStack *i)
{
    return i->actTop == MAX_SIZE - 1;
}

//push: checks if the stack is full, if not, the position is stored at the top of the stack's array list of elements
void push(struct memStack *s, struct pos pos) 
{
    if (isFull(s)) 
    {
        printf("ERROR: Stack Overflow \n");
        return;
    }
    s->items[++s->top] = pos;
}

void pushInt(intStack *i, char *str)
{
    if (isFullInt(i))
    {
        printf("ERROR: Stack Overflow \n");
        return;
    }
    i->commands[++i->actTop] = str;
}

char* popInt(intStack *i)
{
    if (isEmptyInt(i))
    {
        printf("ERROR: Stack Underflow \n");
        return '\0';
    }
    return i->commands[i->actTop--];
}

char* peekInt(intStack *i)
{
    if (isEmpty(i)) 
    {
        printf("ERROR: Stack is EMPTY \n");
        return '\0';
    }
    return i->commands[i->actTop];
}

//pos_pop: checks if the stack is empty, and if it is not, the top is removed from the array and the top is set to the value before it
struct pos pop(struct memStack *s) 
{
    struct pos nullPos = {0, 0};
    if (isEmpty(s)) 
    {
        printf("ERROR: Stack Underflow \n");
        return nullPos;
    }
    return s->items[s->top--];
}

//pos_peek: checks if the stack is empty, and if not, the top value of the stack is returned
struct pos peek(struct memStack *s) 
{
    struct pos nullPos = {0, 0};
    if (isEmpty(s)) 
    {
        printf("ERROR: Stack is EMPTY \n");
        return nullPos;
    }
    return s->items[s->top];
}

/*markPos: sets the value of the marked position to true
void markPos(struct pos *pos) 
{
    pos->pheremone = true;
}
*/

//clear sets the top to -1, which will represent a cleared stack, after popping all values
void clear(struct memStack *s) 
{
    while (!isEmpty(s)) 
    {
        struct pos pos = pop(s);
        pos.pheremone = false; // Reset the marked flags
    }
    s->top = -1; //Set the top of the stack to -1 to represent empty stack
}

void clearInt(intStack *i)
{
    while (!isEmptyInt(i))
    {
        char* str = popInt(i);
    }
    i->actTop = -1;
}
