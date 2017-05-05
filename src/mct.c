#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"
#include "mct.h"
#include "dijkstra.h"

TAB initialise_sommets(char *str, TAB M){
  printf("initialise_sommets\n");
  M=init_s(M);
  return initialiser_sommets(str, M);
}

int conversion_sommet_str_sommet_int(TAB M, char *sommet_str){
  printf("conversion_sommet_str_sommet_int\n");
  int sommet=-1;
  int i;

  for(i=0; i<NBR_STATIONS;i++){
    if(strcmp(sommet_str,M.TAB[i].nom)==0){
      sommet = atoi(M.TAB[i].index);
      return sommet;
    }
  }
  if(sommet == -1){
    printf("sommet inconnu ou mal orthographié\n");
    printf("ex1: Basilique de Saint-Denis -> Basilique_de_Saint-Denis\n");
    printf("ex2: Place d'Italie -> Place_d'Italie\n");
    exit(EXIT_FAILURE);
  }
  return sommet;
}

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
  TAB M;
  char *sommet_depart_str;
  char *sommet_arrivee_str;

  if(argc < 3){
    printf("Trop peut d'arguments\n");
    printf("utilisation :\n");
    printf("mct station_de_depart station_d'arrivee\n");
    exit(EXIT_FAILURE);
  }

  if(argc == 3){
    sommet_depart_str=argv[1];
    sommet_arrivee_str=argv[2];
  }

  if(argc>3){
    printf("Trop d'arguments\n");
    printf("utilisation :\n");
    printf("mct station_de_depart station_d'arrivee\n");
    exit(EXIT_FAILURE);
  }

  M=initialise_sommets("metro.txt",M);
  printf("sommets M initialisés\n");
  initialise_graph("metro.txt",G,M);
  printf("graph initialisé\n");
  plus_court_chemin(G,M,conversion_sommet_str_sommet_int(M,sommet_depart_str),conversion_sommet_str_sommet_int(M,sommet_arrivee_str));
  printf("fin algorithme\n");
  printf("showme: %s %s %s\n", G[238][0].sm1.nom,G[238][0].sm2.nom,G[238][0].temps);
  return 0;
}
////////////////////////////////////////////////////////////////////////////////
//DEMONTIS BOUZIANE JACQUET
