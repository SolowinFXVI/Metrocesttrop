#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "mct.h"

STATIONS initialise(STATIONS M){
  int i;
  for(i=0; i<=NBR_STATIONS; i++){
    M.S[i].index=0;
    M.S[i].nom="UNKNOWN";
    M.S[i].ligne="UNKNO";
    M.S[i].status='F';
  }
  return M;
}

int main(int argc, char *argv[]) {
  STATIONS M;
  M = initialise(M);
  printf("fuckoff");
  M = initialiser_sommets_et_arcs("metro.txt",M);
  /*calcul_trajet();
  afficher_trajet();*/

  return 0;
}
