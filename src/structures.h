#ifndef __MCT_H
#define  __MCT_H

struct sommet{ //la structure
  char *index;
  char *nom;
  char *ligne;
  char *status;
};

struct sommet STATION[378]; //crée un tableau de la structure

typedef struct arc{
  int index1;
  int index2;
  int temps;
}ARC;


#endif
