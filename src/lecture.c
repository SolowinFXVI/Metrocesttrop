#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

TAB init_s(TAB M){ //remplie le tableau des sommet d'un marqueur "UNKNOWN"
  int i;
  for(i=0; i<NBR_STATIONS-1; i++){
    strcpy(M.TAB[i].index,"UNKNOWN");
    strcpy(M.TAB[i].nom,"UNKNOWN");
    strcpy(M.TAB[i].ligne,"UNKNOWN");
    strcpy(M.TAB[i].status,"UNKNOWN");
  }
  return M;
}

void init_g(ARC G[NBR_ARCS][NBR_ARCS]){
  int i;
  int j;
  for(i=0;i<NBR_ARCS;i++){
    for(j=0;j<NBR_ARCS;j++){
      strcpy(G[i][j].sm1.index,"UNKNOWN");
      strcpy(G[i][j].sm1.nom,"UNKNOWN");
      strcpy(G[i][j].sm1.ligne,"UNKNOWN");
      strcpy(G[i][j].sm1.status,"UNKNOWN");
      strcpy(G[i][j].sm2.index,"UNKNOWN");
      strcpy(G[i][j].sm2.nom,"UNKNOWN");
      strcpy(G[i][j].sm2.ligne,"UNKNOWN");
      strcpy(G[i][j].sm2.status,"UNKNOWN");
      strcpy(G[i][j].temps,"99999");

    }
  }
}

TAB initialiser_sommets(char *str, TAB M){ //extrait les données de "metro.txt" et les stock dans le tableau des sommets
  int i;
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

  for(i=0;i<NBR_STATIONS;i++){ //ignore ce qu'il y a après la derniere station
    fscanf(fic,"%s %s %s %s %s\n", &type[0], &index[0], &nom[0], &ligne[0], &status[0]);
    strcpy(M.TAB[i].index,index);
    strcpy(M.TAB[i].nom,nom);
    strcpy(M.TAB[i].ligne,ligne);
    strcpy(M.TAB[i].status,status);
  }

fclose(fic);
return M;
}

void associer_graph_data(char *sm1, char *sm2,ARC G[NBR_ARCS][NBR_ARCS],TAB M){
  int i;
  for(i=0;i<NBR_STATIONS;i++){
    if(atoi(sm1) == atoi(M.TAB[i].index)){
      strcpy(G[atoi(sm1)][atoi(sm2)].sm1.index,M.TAB[i].index);
      strcpy(G[atoi(sm1)][atoi(sm2)].sm1.nom,M.TAB[i].nom);
      strcpy(G[atoi(sm1)][atoi(sm2)].sm1.ligne,M.TAB[i].ligne);
      strcpy(G[atoi(sm1)][atoi(sm2)].sm1.status,M.TAB[i].status);
    }
    if(atoi(sm2) == atoi(M.TAB[i].index)){
      strcpy(G[atoi(sm1)][atoi(sm2)].sm2.index,M.TAB[i].index);
      strcpy(G[atoi(sm1)][atoi(sm2)].sm2.nom,M.TAB[i].nom);
      strcpy(G[atoi(sm1)][atoi(sm2)].sm2.ligne,M.TAB[i].ligne);
      strcpy(G[atoi(sm1)][atoi(sm2)].sm2.status,M.TAB[i].status);
    }
  }
}

void initialiser_graph(char *str,ARC G[NBR_ARCS][NBR_ARCS], TAB M){ //extrait les données de "metro.txt" et les stock dans le tableau des arcs
  int i=0;
  char type[128];
  char sm1[128];
  char sm2[128];
  char temps[128];
  char garbage[128];
  FILE* fic = fopen(str, "r");

  if (fic == NULL) {
		printf("echec ouverture fichier%s\n", str);
		exit(EXIT_FAILURE);
	}

  while(fscanf(fic,"%s %s %s %s %s\n", &type[0], &sm1[0], &sm2[0], &temps[0], &garbage[0]) != EOF){
      if(i>=376){ //ignore toute la partie sur les sommets
        associer_graph_data(sm1,sm2,G,M);
        associer_graph_data(sm2,sm1,G,M);
        strcpy(G[atoi(sm1)][atoi(sm2)].temps,temps);
        strcpy(G[atoi(sm2)][atoi(sm1)].temps,temps);
        i++;
      }
    i++;
  }
fclose(fic);
}

void initialise_graph(char *str,ARC G[NBR_ARCS][NBR_ARCS],TAB M){
  printf("initialise_graph\n");
  init_g(G);
  initialiser_graph(str,G,M);
}
