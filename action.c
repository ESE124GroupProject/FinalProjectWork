#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define ROWS 24
#define COLS 10

// R, F, L, B
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void markPos(pos *pos) 
{
    pos->pheremone = true;
}

pos move(pos position, int direction)
{
    pos new_pos;

    new_pos.x = position.x + dx[direction];
    new_pos.y = position.y + dy[direction];

    return new_pos;
}

// Use direction variable to control next position.
int CW(pos *pos, int maze[ROWS][COLS], int pheromone[ROWS][COLS], int direction)
{
    int len = 0;
    int x = pos->x;
    int y = pos->y;

    while (maze[x][y] != 1)
    {
        x += dx[direction];
        y += dy[direction];

        if (pheromone[x][y] == 1 || maze[x][y] == 1) {
            return len;
        }
        len ++ ;
    }

    return len;
}

pos BJPI(pos posi, int x, int direction) {
   pos new_pos;

   new_pos.x = posi.x + x * dx[direction];
   new_pos.y = posi.y + x * dy[direction];

   return new_pos;
}

pos CJPI(pos pos, int direction) {
    return BJPI(pos, 1, direction);
}

pos backtrack(struct memStack *stack) {
    pos last_pos = pop(stack);

    return last_pos;
}

void record_action(const char action[]) {
    const char filename[] = "output.txt"; // Removed hardcoded path

    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending\n");
        return;
    }

    fprintf(fp, "%s\n", action);
    printf("Record the action %s to the output file.\n", action);

    fclose(fp); // Close file after writing
}

void clear_action_file() {
    const char filename[] = "output.txt"; // Removed hardcoded path
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for clearing\n");
        return;
    }

    fprintf(fp, "%s", "");
    printf("Cleared all previous commands!\n");

    fclose(fp); // Close file after writing
}

int comming_direction(pos lastPos, pos curPos) {
    if (lastPos.x - curPos.x < 0) {
        return 2;
    } else if (lastPos.x - curPos.x > 0) {
        return 0;
    } else if (lastPos.y - curPos.y > 0) {
        return 3;
    } else if (lastPos.y - curPos.y < 0) {
        return 1;
    }

    return -1;
}


//Stack storage for intelligence