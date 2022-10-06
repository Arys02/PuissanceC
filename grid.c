#include "grid.h"

Grid *create_grid(gameRules *gr){
    //printf("ici2");
    Grid *new_g = malloc(sizeof(Grid));
    //printf("ici-1");
    new_g->grid = malloc(sizeof(char*) * gr->columns);
    
    //printf("ici0");
    for(int i = 0; i < gr->rows; i ++){
        new_g->grid[i] = malloc(sizeof(char*) * gr->columns);
    }
    for(int i = 0; i < gr->rows; i++){
        //printf("[%d, %d]", i, 0);
        for(int j = 0; j < gr->columns; j++){
            new_g->grid[i][j] = ' ';
        }
    }
     
    new_g->columns = gr->columns;
    new_g->rows = gr->rows;
    new_g->filled = 0;
    
    return new_g; 
}
void free_grid(Grid *g){
    for(int i = 0; i < g->rows; i++){
        free(g->grid[i]);
    }
    free(g->grid);
    free(g);
}

int update_grid(Grid *g, int x, int y, char c){
    if (x >= g->rows || x < 0 || y >= g->columns || y < 0)
        return 0;
    g->grid[x][y] = c;
    return 1;
}

char *get_value(Grid *g, int x, int y){
    if (x >= g->rows || x < 0 || y >= g->columns || y < 0)
        return -1;
    return g->grid[x][y];
    
}