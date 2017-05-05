#ifndef __MCT_H
#define  __MCT_H

struct sommet{ //structure contenant les informations relatives a un sommet
  char index[128];
  char nom[128];
  char ligne[128];
  char status[128];
};
typedef struct sommet SOMMET;

struct tab{//structure contenant les informations relatives a tous les sommets
  struct sommet TAB[377];
};
typedef struct tab TAB;

struct arc{//structure contenant les informations relatives a l'existance d'un arc
  struct sommet sm1;
  struct sommet sm2;
  char temps[128];
};
typedef struct arc ARC;

ARC G[472][472]; //Matrice d'adjascence utilisée par la partie dijkstra

struct element{ //liste pour stocker le trajet
  int val;
  struct element* next;
};

typedef struct element Element;
typedef Element* List;

#endif
