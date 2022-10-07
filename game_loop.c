#include "game_loop.h"

void free_game(Grid *g, gameRules *gr, Player **p_list){
  free_players(p_list, gr->nbPlayer);
  free_grid(g);
  free(gr);

}

int game_loop(Grid *g, gameRules * gr, Player **p_list, int lenP_list){
    printf("DÉBUT DU JEU\n");
  for(int i = 0; i < lenP_list; i++){
    printf("joueur : %s\n, symbole : %c\n", p_list[i]->name, p_list[i]->symbol);
  }
  while(1){
    for(int i = 0; i < lenP_list; i++){
        int coord;
        int max_try = 5;
        char buf[50];
        display_grid(g);
        do {
            printf("\na %s de jouer : \n", p_list[i]->name);
            printf("choisis une coordonnee entre 0 et %d :\n", g->rows);
            coord = atoi(fgets(buf, 50, stdin));
            
            //scanf("%d", &coord);
            printf("\ny : %d\n", coord);
            if (coord < 0 || coord >= g->columns){
                printf("erreur, mauvaise coordonnée plus que %d essai avant de perdre ton tour\n", max_try);
                max_try--;
            }
            else{
              int res = play(p_list[i], g, coord, gr);
              if (res == 0){
                  printf("placement invalide recommence \n");
                  continue;
              } else if (res == 1){
                  max_try = -1;
              } else if (res == 3) {
                printf("MATCH NUL!");
                  free_game(g, gr, p_list);
                  return 3;
              }
              else if (res == 2) {
                  display_grid(g);
                  printf("\nFELICITATION POUR TA VICTOIRE %s \n", p_list[i]->name);
                 free_game(g, gr, p_list);
                  return 2;
                }
              
            }
        //
        } while(max_try >= 0);
        
    }
  }
     free_game(g, gr, p_list);
    return -1;
}
