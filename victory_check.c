#include "victory_check.h"

int check_verticale_bas(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;

  if (x + 1 == g->rows) {
    return occ;
  } else {
    x++;
    while (x < g->rows && (g->grid[x][y] == c) && (occ <= puissance - 2)) {
      occ++;
      x++;
    }
    return occ;
  }
}

int check_horizontale_droite(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;

  if (y == g->columns) {
    return occ;
  } else {
    y++;
    while (y < g->columns && g->grid[x][y] == c && occ <= puissance - 2) {

      occ++;
      y++;
    }
  }

  return occ;
}

int check_horizontale_gauche(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;
  if (y == 0) {
    return occ;
  } else {
    y--;
    while (y >= 0 && g->grid[x][y] == c && occ <= puissance - 2) {

      occ++;
      y--;
    }
  }

  return occ;
}

// Yahia

// retourne 0 si y'a pas de correspondance sinon le nombre de récurrence
// existant dans cette partie
//ARYS
int check_diag_gauche_haut_1(Grid *g, int x, int y, char c, int puissance) {
  if ( x < 0 || y < 0 || x >= g->rows || y >= g->columns || g->grid[x][y] != c)
    return 0;
  return 1 + check_diag_gauche_haut_1(g, x + 1, y + 1, c, puissance);
}
int check_diag_gauche_bas_1(Grid *g, int x, int y, char c, int puissance) {
  if ( x < 0 || y < 0 || x >= g->rows || y >= g->columns || g->grid[x][y] != c)
    return 0;
  return 1 + check_diag_gauche_bas_1(g, x - 1, y - 1, c, puissance);
}
int check_diag_gauche_1(Grid *g, int x, int y, char c, int puissance){
  if (check_diag_gauche_haut_1(g, x+1, y+1, c, puissance) + check_diag_gauche_bas_1(g, x, y, c, puissance)
    >= puissance)
    return 1;
  return 0;
}

int check_diag_droit_haut_1(Grid *g, int x, int y, char c, int puissance) {
  if ( x < 0 || y < 0 || x >= g->rows || y >= g->columns || g->grid[x][y] != c)
    return 0;
  return 1 + check_diag_droit_haut_1(g, x + 1, y - 1, c, puissance);
}
int check_diag_droit_bas_1(Grid *g, int x, int y, char c, int puissance) {
  if ( x < 0 || y < 0 || x >= g->rows || y >= g->columns || g->grid[x][y] != c)
    return 0;
  return 1 + check_diag_droit_bas_1(g, x - 1, y + 1, c, puissance);
}
int check_diag_droit_1(Grid *g, int x, int y, char c, int puissance){
  if (check_diag_droit_haut_1(g, x+1, y+1, c, puissance) + check_diag_droit_bas_1(g, x, y, c, puissance)
    >= puissance)
    return 1;
  return 0;
}
//FIN ARYS

int check_diag_haut_gauche(Grid *g, int x, int y, char c, int puissance) {

  int occ = 0;
  if (x == 0) {
    return occ;
  } else {
    x--;
    y--;
    while (x > 0 && occ <= puissance - 2 && g->grid[x][y] == c) {
        occ++;
        x--;
        y--;
    }
  }

  return occ;
}

int check_diag_haut_droite(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;
  if (x == 0) {
    return occ;
  } else {
    x--;
    y++;
    while (x > 0 && occ <= puissance - 2 && g->grid[x][y] == c) {
        occ++;
        x--;
        y++;
    }
  }
  return occ;
}

int check_diag_bas_gauche(Grid *g, int x, int y, char c, int puissance) {
  int occ = 0;
  if (x == g->rows) {
    return occ;
  } else {
    x++;
    y--;
    while (x < g->rows && y >= 0 && g->grid[x][y] == c &&
           occ <= puissance - 2) {
      occ++;
      x++;
      y--;
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
    while (x < g->rows && occ <= puissance - 2 && g->grid[x][y] == c) {
        occ++;
        x++;
        y++;   
    }
  }

  return occ;
}

int check_vectory(Grid *g, int x, int y, char c, int puissance) {

  int diag_droite = 0;
  int diag_gauche = 0;
  int horiz = 0;
  int vert = 0;
  printf ("%d\n", puissance);
  // Normalement on rajoute -2 car les deux fonctions droite et gauche rentrent
  // au moins une seule fois, mais j'ai eu un problème de segmentation jsp prk

  // dans la boucle while donc occ++
  // + 1 pour le caractère courant qu'on vient de rajouter

  horiz = check_horizontale_droite(g, x, y, c, puissance) + check_horizontale_gauche(g, x, y, c, puissance) + 1;

  if (horiz == puissance) {
    return 1;
  }

  vert += check_verticale_bas(g, x, y, c, puissance) + 1;

  if (vert == puissance) {

    return 1;
  }

  /*
    if (check_diag_droit_1(g,  x, y,  c, puissance) 
    || check_diag_gauche_1(g,  x, y, c, puissance))
    return 1;
  return 0;*/
  diag_droite += check_diag_bas_gauche(g, x, y, c, puissance) + check_diag_haut_droite(g, x, y, c, puissance) + 1;
    
  if (diag_droite == puissance) {
    return 1;
  }

   diag_gauche = check_diag_haut_gauche(g, x, y, c, puissance) +
   check_diag_bas_droite(g, x, y, c, puissance) + 1;
  if (diag_gauche == puissance) {
    return 1;
  }

  return 0;
}
