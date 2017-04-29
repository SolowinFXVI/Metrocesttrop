#ifndef __MCT_H
#define  __MCT_H

struct sommet{
  int index;
  char* nom;
  int ligne;
};

typedef struct sommmet SOMMET;

struct arc{
  int index1;
  int index2;
  int temps;
};

typedef struct arc ARC;

#endif
