#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

SOMMET initialiser_sommets(char* str){

  FILE* fic = fopen(str, "r");

  if (fic == NULL) {
		printf("echec ouverture fichier%s\n", str);
		exit(EXIT_FAILURE);
	}



  fscanf(fic,"%d %s %d %s", &index, &nom, &ligne, &terminus);


}
