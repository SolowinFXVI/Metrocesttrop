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
  struct sommet TAB[378];
};

typedef struct tab TAB;

typedef struct arc{
  int index1;
  int index2;
  int temps;
}ARC;


#endif
