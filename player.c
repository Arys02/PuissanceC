#include "player.h"


Player *create_player(char *name, char symbole){
    Player *p = malloc(sizeof(Player));
    p->name = name;
    p->symbol = symbole;
    return p;
}

void free_player(Player *p){
    free(p);
}

int play(Player *p, Grid *g, int x){
    //le jouer player joue sa piece en position x
    //le plateau est mis à jour
    //retourne 0 si mouvement invalide 1 si valide 
    //TODO
}