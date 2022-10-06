#ifndef DISPLAY_GRID_H
#define DISPLAY_GRID_H

#include "grid.h"

void display_grid(Grid *grid) {

  for (int i = 0; i < grid->rows; i++) {
    for (int j = 0; j <= grid->columns; j++) {

      printf("| %c",grid->Grid[i][j]);
    }
    printf("\n");
  }
  return;
}

#endif