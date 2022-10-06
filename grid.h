#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include "game_rules.h"

typedef struct {
    char **grid;
    int rows;
    int columns;
    int filled;
} Grid;

Grid *create_grid(gameRules *gr);
void free_grid(Grid *g);
int update_grid(Grid *g, int x, int y, char c);
char *get_value(Grid *g, int x, int y);

#endif