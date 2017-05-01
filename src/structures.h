#ifndef __MCT_H
#define  __MCT_H

typedef struct sommet{
  int index;
  char *nom;
  char *ligne;
  char status;
}SOMMET;

typedef struct stations{
  SOMMET S[318];
}STATIONS;

typedef struct arc{
  int index1;
  int index2;
  int temps;
}ARC;


#endif
