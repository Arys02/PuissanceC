#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"
#include "victory_check.h"

typedef struct {
    char symbol;
    char *name;
} Player;

Player *create_player(char *name, char symbole);
Player **create_players(int n);
void free_player(Player *p);
void free_players(Player **p, int n);
int play(Player *p, Grid *g, int x, gameRules *gr);

#endif