#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

void initialiser_sommets_et_arcs(char *str){ //bug!!!!!!!!!!!!!!!
  int i;
  char type[256];
  char index[256];
  char nom[256];
  char ligne[256];
  char status[256];
  FILE* fic = fopen(str, "r");

  if (fic == NULL) {
		printf("echec ouverture fichier%s\n", str);
		exit(EXIT_FAILURE);
	}

for(i = 0; i<NBR_STATIONS; i++ ){
    fscanf(fic,"%s %s %s %s %s", type, index, nom, ligne, status);
    STATION[i].index=index;
    STATION[i].nom=nom;
    STATION[i].ligne=ligne;
    STATION[i].status=status;
    printf("type = %s\n",type);
    printf("index = %s\n",STATION[i].index);
    printf("nom = %s\n",STATION[i].nom);
    printf("ligne = %s\n",STATION[i].ligne);
    printf("status = %s\n",STATION[i].status);
  }

fclose(fic);
}
