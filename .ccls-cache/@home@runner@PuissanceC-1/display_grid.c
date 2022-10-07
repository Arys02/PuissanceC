#include "display_grid.h"
#include <stdio.h>

void display_grid(Grid *grid) {
printf("\n");
  for (int i = 0; i < grid->rows; i++) {
    for (int j = 0; j <= grid->columns; j++) {

      printf("| %c",grid->grid[i][j]);
    }
    //printf("|");
    printf("\n");
  }
  //printf("----------------------\n ");
  for (int i = 0; i < grid->columns; i++){
    printf("---");
  }
  printf("\n");
  for (int i = 0; i < grid->columns; i++){
    printf(" %d ", i);
  }

}