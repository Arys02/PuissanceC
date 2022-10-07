#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "game_rules.h"
#include "grid.h"
#include "player.h"
#include "display_grid.h"

int game_loop(Grid *g, gameRules * gr, Player **p_list, int lenP_list);

#endif