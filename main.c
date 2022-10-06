#include <stdio.h>
#include "display_grid.h"
#include "game_rules.h"
#include "grid.h"

int main(void) {
  printf("Hello World\n");
    printf("game rules \n");
    gameRules *gr = create_gameRules(2, 6, 7, 3);

    printf("%d \n", gr->rows);
    printf(" create \n");
    Grid *g = create_grid(gr);

    int a = update_grid(g, 0, 0, 'X');
    printf("%d, %d", a, get_value(g, 0, 0));

    
   // display_grid(int row, int column)
  
char piece = "x" ;
  printf("\n %d ",play_piece(g,piece , 5));

    free_grid(g);
  return 0;
}