#ifndef GAME_RULES_H
#define GAME_RULES_H


typedef  struct{
  int nbPlayer;
  int rows;
  int columns;
  int puissance;
}gameRules;

gameRules *create_gameRules(int nbplayer, int rows, int columns, int puissance);



#endif