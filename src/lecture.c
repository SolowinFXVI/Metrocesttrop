#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

TAB init(TAB M){
  int i;
  for(i=0; i<NBR_STATIONS-1; i++){
    strcpy(M.TAB[i].index,"UNKNOWN");
    strcpy(M.TAB[i].nom,"UNKNOWN");
    strcpy(M.TAB[i].ligne,"UNKNOWN");
    strcpy(M.TAB[i].status,"UNKNOWN");
  }


    strcpy(M.TAB[15].nom,"baboo");
    return M;
}

TAB initialiser_sommets_et_arcs(char *str, TAB M){ //bug!!!!!!!!!!!!!!!
  int i=0;
  char type[128];
  char index[128];
  char nom[128];
  char ligne[128];
  char status[128];
  FILE* fic = fopen(str, "r");

  if (fic == NULL) {
		printf("echec ouverture fichier%s\n", str);
		exit(EXIT_FAILURE);
	}

  for(i=0;i<NBR_STATIONS;i++){
    fscanf(fic,"%s %s %s %s %s\n", &type[0], &index[0], &nom[0], &ligne[0], &status[0]);
    strcpy(M.TAB[i].index,index);
    strcpy(M.TAB[i].nom,nom);
    strcpy(M.TAB[i].ligne,ligne);
    strcpy(M.TAB[i].status,status);
  }

fclose(fic);
return M;
}
