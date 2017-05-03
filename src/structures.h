#ifndef __MCT_H
#define  __MCT_H

struct sommet{
  char index[128];
  char nom[128];
  char ligne[128];
  char status[128];
};
typedef struct sommet SOMMET;

struct tab{
  struct sommet TAB[377];
};
typedef struct tab TAB;

struct arc{
  struct sommet sm1;
  struct sommet sm2;
  char temps[128];
};
typedef struct arc ARC;

struct arcs{
  struct arc ARCS[472];
};
typedef struct arcs ARCS;

ARC G[377][377]; //Matrice d'adjascence


#endif
