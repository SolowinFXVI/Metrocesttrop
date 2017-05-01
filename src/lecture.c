#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

STATIONS initialiser_sommets_et_arcs(char *str, STATIONS M){
  int i;
  char type;
  int index;
  char nom[200];
  char ligne[5];
  char status;
  FILE* fic = fopen(str, "r");

  if (fic == NULL) {
		printf("echec ouverture fichier%s\n", str);
		exit(EXIT_FAILURE);
	}

for(i = 0; i <= NBR_STATIONS; i++ ){
    fscanf(fic,"%s %d  %s  %s  %s", &type, &index, &nom[200], &ligne[5], &status);
    M.S[i].index=index;
    M.S[i].nom=nom;
    M.S[i].ligne=ligne;
    M.S[i].status=status;
  }


fclose(fic);
return M;
}
