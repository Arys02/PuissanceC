#include "grid.h"
#include <stdio.h>

#include "grid.h"
// Sarah
int check_verticale_bas(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;

  if (x == g->rows) {
    return occ;
  }

  while (g->grid[x][y] == c && occ != puissance-1 && x != g->rows) {

    occ++;
    x++;
  }

  return occ;
}


int check_verticale_haut(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;

  if (x == 0) {
    return occ;
  }

  while (g->grid[x][y] == c && occ != puissance-1 && x !=0) {

    occ++;
    x--;
  }

  return occ;
}

int check_horizontale_droite(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;

  if (y == g->columns) {
    return occ;
  }

  while (g->grid[x][y] == c && occ != puissance-1 && y  != g->columns) {

    occ++;
    y ++;
  }

  return occ;
}


int check_horizontale_gauche(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;

  if (y == 0) {
    return occ;
  }

  while (g->grid[x][y] == c && occ != puissance-1 &&   y !=0) {

    occ++;
    y--;
  }

  return occ;
}


// Yahia

// retourne 0 si y'a pas de correspondance sinon le nombre de récurrence
// existant dans cette partie

int check_diag_haut_gauche(Grid *g, int x, int y, char c, int puissance) {

  int ligne = g->rows;
  int columns = g->columns;
  int occ = 0;
  if (x == 0) {
    return occ;
  } else {
    x--;
    y--;
    while (x > 0 && occ < puissance-1) {
      if (g->grid[x][y] == c) {
        occ++;
        x--;
        y--;
      } else {
        return occ;
      }
    }
  }


  return occ;
}


int check_diag_haut_droite(Grid *g, int x, int y, char c, int puissance) {

  int ligne = g->rows;
  int columns = g->columns;
  int occ = 0;
  if (x == 0) {
    return occ;
  } else {
    x--;
    y++;
    while (x > 0 && occ < puissance-1) {
      if (g->grid[x][y] == c) {
        occ++;
        x--;
        y++;
      } else {
        return occ;
      }
    }
  }

  return occ;
}

int check_diag_bas_gauche(Grid *g, int x, int y, char c, int puissance) {
  int ligne = g->rows;
  int columns = g->columns;
  int occ = 0;
  if (x == g->rows) {
    return occ;
  } else {
    x++;
    y--;
    while (x < g->rows && occ < puissance-1) {
      if (g->grid[x][y] == c) {
        occ++;
        x++;
        y--;
      } else {
        return occ;
      }
    }
  }

  return occ;

}


int check_diag_bas_droite(Grid *g, int x, int y, char c, int puissance) {
  
  int ligne = g->rows;
  int columns = g->columns;
  int occ = 0;
  if (x == g->rows) {
    return occ;
  } else {
    x++;
    y++;
    while (x < g->rows && occ < puissance-1) {
      if (g->grid[x][y] == c) {
        occ++;
        x++;
        y++;
      } else {
        return occ;
      }
    }
  }

  return occ;

  
}

int check_vectory(Grid* g, int x, int y, char c, int puissance){

  int diag_droite, diag_gauche, horiz, vert;
  
  horiz = check_horizontale_droite(g,  x,  y,  c,  puissance) + horiz + check_horizontale_gauche(g,  x,  y,  c,  puissance) + 1;
  if(horiz == puissance){
    return 1;
  }

  vert = check_verticale_haut(g,  x,  y,  c,  puissance) + check_verticale_bas(g,  x,  y,  c,  puissance);
  if(vert == puissance){
    return 1;
  }

  diag_droite = check_diag_haut_droite(g,  x,  y,  c,  puissance) + check_diag_bas_gauche(g,  x,  y,  c,  puissance);
  if(diag_droite == puissance){
    return 1;
  }

  diag_gauche = check_diag_haut_gauche(g,  x,  y,  c,  puissance) + check_diag_bas_droite(g,  x,  y,  c,  puissance);
  if(diag_gauche == puissance){
    return 1;
  }

  return 0;
  
  
}

int play_piece(Grid *g, char piece, int x) {
  /* x doit etre entre zero et col.
      determiner si g[]

*/
  if (x >= 0 && x <= g->columns) {
    for (int i = 0; i < g->rows; i++) {
      if (g->grid[i][x] != 0) {
        continue;
      }
      g->grid[i - 1][x] = piece;
    }
    return 1;
  } else {
    return 0;
  }
}
