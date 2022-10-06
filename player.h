#IFNDEF PLAYER_H
#DEFINE PLAYER_H

typedef struct {
    char symbol;
    char *name;
} Player;

Player *create_player(char *name, char symbole);
void free_player(Player *p);
int play(Player *p, Grid *g, int x);

#ENDIF