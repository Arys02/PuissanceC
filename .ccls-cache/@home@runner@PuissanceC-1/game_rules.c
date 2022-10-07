#include "game_rules.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


gameRules *create_gameRules(int nbplayer, int rows, int columns, int puissance){
  gameRules *rules  = malloc(sizeof(gameRules));

  if(rules != NULL){
    if((rows >= puissance) || (columns>= puissance)){
    rules->nbPlayer = nbplayer;
    rules->rows = rows;
    rules->columns = columns;
    rules->puissance = puissance;
    return rules;
  }
  else{
    return NULL;
  }
    
  }
  else{
    return NULL;
  }
}

void free_gameRules(gameRules* game_rules){
  free(game_rules);
}

int update_nb_player(gameRules* game_rules, int new_nb_player){
  if(new_nb_player >= 2){
    game_rules->nbPlayer = new_nb_player;
    return 1;
  }
  else{
    return 0;
  }
}

int update_nb_rows(gameRules* game_rules, int new_nb_rows){
  if((game_rules->puissance > game_rules->columns) && (new_nb_rows < game_rules->puissance)){
    return 0;
  }
  else{
    game_rules->rows = new_nb_rows;
    return 1;
  }
}

int update_nb_columns(gameRules* game_rules, int new_nb_columns){
  if((game_rules->puissance > game_rules->rows) && (new_nb_columns < game_rules->puissance)){
    return 0;
  }
  else{
    game_rules->rows = new_nb_columns;
    return 1;
  }
}
