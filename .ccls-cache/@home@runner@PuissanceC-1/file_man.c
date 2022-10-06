#include "game_rules.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

gameRules * getRules(char* file){
  FILE *f = fopen(file, "r");
  if(f != NULL){
    gameRules *game_rules = malloc(sizeof(gameRules));
    char *ligne = malloc(sizeof(char) * 10);
    int cpt = 1;
    while(fgets(ligne, 20, f) && cpt < 4){
      if(cpt == 1){
        char *token = strtok(ligne, "=");
        token = strtok(NULL, "=");
        game_rules->nbPlayer = atoi(token);
        cpt++;
      }
      else if(cpt == 2){
        char *token = strtok(ligne, "=");
        token = strtok(NULL, "=");
        game_rules->rows = atoi(token);
        cpt++;
      }
      else if(cpt == 3){
        char *token = strtok(ligne, "=");
        token = strtok(NULL, "=");
        game_rules->columns = atoi(token);
        cpt++;
      }
      
    }
    return game_rules;
  }
  else{
    return NULL;
  }
}


