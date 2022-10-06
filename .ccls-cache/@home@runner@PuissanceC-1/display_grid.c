#include "display_grid.h"
#include <stdio.h>

void display_grid(char **Grid,int row,int column) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= column; j++) {

      printf("|  ");
    }
    printf("\n");
  }
  return;
}