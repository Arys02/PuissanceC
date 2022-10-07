  #include "player.h"
#include <string.h>


Player *create_player(char *name, char symbole){
    Player *p = malloc(sizeof(Player));
  p->name = malloc(sizeof(char) * (strlen(name) + 1));
  //printf("%s \n", name);
    strcpy(p->name, name);
    p->symbol = symbole;
    return p;
}

Player **create_players(int n){
    Player **p = malloc(sizeof(Player*) * n);
    for(int i =0; i < n; i++){
        char c[10];
        char name[50];
        printf("choisis un nom : \n");
        fflush( stdin );

        fgets(name, 49, stdin);
        name[strlen(name) - 1] = '\0';
        
        printf("choisis un symbole :\n");
        fflush( stdin );
        fgets(c, 10, stdin);
        c[1] = '\0';

        fflush(stdin);
        printf("\n");
        p[i] = create_player(name, c[0]);
      
        printf("joueur : %s\n, symbole : %c\n", p[i]->name, p[i]->symbol);
    }
    return p;
}


void free_player(Player *p){
    free(p->name);
    free(p);
}

void free_players(Player **p, int n){
    for(int i = 0; i < n; i++){
        free_player(p[i]);
    }
    free(p);
}

int play_piece(Grid *g, char piece, int x, gameRules *gr) {
  printf("PUISSANCE : %d \n", gr->puissance);
  /* x doit etre entre zero et col.
      determiner si g[]*/
  if (x >= 0 && x < g->columns) {
      int i;
      for (i = 0; i < g->rows; i++) {
          if (g->grid[i][x] == ' ') {
            printf("%d %d\n", x, i);
            continue;
          }
          break;
    }
    //printf("%d -> %c \n", i - 1, piece);
    g->grid[i - 1][x] = piece;
    
      if (check_vectory(g, i - 1, x, piece, gr->puissance)){
          printf("VICTOIRE LLOOOL\n");
          return 2;
      }
      g->filled++;
    return 1;
  } else {
    return 0;
  }
}

//test la victoire
//0 mouvement invalide
//1 joué
//2 gagné
int play(Player *p, Grid *g, int x, gameRules *gr){
    //le jouer player joue sa piece en position x
    //le plateau est mis à jour
    //retourne 0 si mouvement invalide 1 si valide 
    if (g->filled + 1 == g->columns * g->rows){
        //match nul
        return 3;
    }
    return play_piece(g, p->symbol, x, gr);
}