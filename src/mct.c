#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "mct.h"


void initialise(){
  int i;
  for(i=0; i<NBR_STATIONS; i++){
    STATION[i].index="UNKNOWN";
    STATION[i].nom="UNKNOWN";
    STATION[i].ligne="UNKNOWN";
    STATION[i].status="UNKNOWN";
  }
}

int main(int argc, char *argv[]) {

  initialise();

  //j'ai testé jusqu'ici et la théorie fonctionne : je peux rentrer manuellement des noms et ca fonctionne, et je peux initialiser et ca vide comme il faut mais quand je fais initialiser_sommets_et_arcs ca remplie
  //mon tableau du dernier point vu.

  initialiser_sommets_et_arcs("metro.txt"); //bug!!!!!!!!!!!!!!!!!
  /*calcul_trajet();
  afficher_trajet();*/
  printf("nom sommet 15 = %s\n",STATION[15].nom); //devrait afficher le nom de la station 15
  printf("nom sommet 16 = %s\n",STATION[16].nom); //devrait afficher le nom de la station 16
  return 0;
}
