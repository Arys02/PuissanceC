#include "display_grid.h"
#include "file_man.h"
#include "game_loop.h"
#include "game_rules.h"
#include "grid.h"
#include "player.h"
#include <stdio.h>

int main(void) {
  printf("Hello World\n");
  gameRules *gr = getRules("conf.txt");
  if (gr == NULL)
    gr = create_gameRules(2, 6, 7, 3);
  Grid *g = create_grid(gr);
  Player **list_players = create_players(gr->nbPlayer);
  int a = game_loop(g, gr, list_players, gr->nbPlayer);
  //printf("builded\n");

  //printf("%d \n", gr->rows);
  //printf(" create \n");

  // play(p, g, 1, gr);
  // play(p2, g, 2, gr);
  // play(p, g, 1, gr);
  // play(p2, g, 2, gr);
  // play(p, g, 1, gr);
  // play(p2, g, 2, gr);

  // play(p2, g, 2, gr);
  // play(p, g, 4, gr);
  // play(p2, g, 5, gr);
  // play(p, g, 5, gr);
  // play(p2, g, 5, gr);
  // play(p, g, 3, gr);
  // play(p2, g, 5, gr);
  // play(p2, g, 5, gr);
  // play(p, g, 2, gr);

  // play(p2, g, , gr);

  // printf("%d, %s", a, get_value(g, 0, 0));
  // display_grid(g);
  /*
    //   return 0;
    // display_grid(int row, int column)
    // test honrizontale

    // printf("horizontale \n") ;
    // printf("%d on a combien de X : ", check_verticale_bas(g,  2, 2 , "x" ,
  3))
    // ;

  char piece = "x" ;
    printf("\n %d ",play_piece(g,piece , 5));
  */
 
  return 0;
}