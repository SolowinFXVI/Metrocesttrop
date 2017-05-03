#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "mct.h"

TAB initialise(char *str, TAB M){
  M=init(M);
  return initialiser_sommets_et_arcs(str, M);
}

int main(int argc, char *argv[]) {

  TAB M;
  M=initialise("metro.txt",M);

  //j'ai testé jusqu'ici et la théorie fonctionne : je peux rentrer manuellement des noms et ca fonctionne, et je peux initialiser et ca vide comme il faut mais quand je fais initialiser_sommets_et_arcs ca remplie
  //mon tableau du dernier point vu.

  //M=initialiser_sommets_et_arcs("metro.txt",M); //bug!!!!!!!!!!!!!!!!!
  /*calcul_trajet();
  afficher_trajet();*/
  printf("nom sommet 15 = %s\n",M.TAB[15].index); //devrait afficher le nom de la station 15
  printf("nom sommet 15 = %s\n",M.TAB[15].nom); //devrait afficher le nom de la station 15
  printf("nom sommet 15 = %s\n",M.TAB[15].ligne); //devrait afficher le nom de la station 15
  printf("nom sommet 15 = %s\n",M.TAB[15].status); //devrait afficher le nom de la station 15
  printf("nom sommet 16 = %s\n",M.TAB[16].index); //devrait afficher le nom de la station 16
  printf("nom sommet 16 = %s\n",M.TAB[15].nom); //devrait afficher le nom de la station 15
  printf("nom sommet 16 = %s\n",M.TAB[15].ligne); //devrait afficher le nom de la station 15
  printf("nom sommet 16 = %s\n",M.TAB[15].status); //devrait afficher le nom de la station 15
  printf("nom sommet 376 = %s\n",M.TAB[NBR_STATIONS-1].index); //devrait afficher le nom de la station 16
  printf("nom sommet 376 = %s\n",M.TAB[NBR_STATIONS-1].nom); //devrait afficher le nom de la station 16
  printf("nom sommet 376 = %s\n",M.TAB[NBR_STATIONS-1].ligne); //devrait afficher le nom de la station 16
  printf("nom sommet 376 = %s\n",M.TAB[NBR_STATIONS-1].status); //devrait afficher le nom de la station 16

  return 0;
}
