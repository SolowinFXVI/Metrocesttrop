#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "structures.h"

int sommets_tous_traites(int sommets_traites[NBR_STATIONS]){
  int i;
  for(i=0; i<NBR_STATIONS; i++){
    if(sommets_traites[i]==0){
      return 0;
    }
  }
  return 1;
}

void init_pere(int pere[NBR_STATIONS]){
  int i;
  for(i=0; i<NBR_STATIONS; i++){
    pere[i]=-1;
  }
}

void dijkstra(int père, char *sommet_depart){

  int sommets_traites[NBR_STATIONS]={0};

  int plus_courte_distance[NBR_STATIONS];
  init_pere(pere);

  sommets_traites[sommet_depart] = 1;

  int i;

  for(i=0; i < NBR_STATIONS; i++){
    if(G[sommet_depart][i].temps!=99999){
      plus_courte_distance[i]=G[sommet_depart][i].temps;
      pere[i]= sommet_depart;
    }
    else{
      plus_courte_distance[i]=99999;
    }
  }

  plus_courte_distance[sommet_depart] = 0;

/////////////////////
  while(!sommets_tous_traites(sommets_traites)){
    int min = 99999, a_traiter;

    for(i=0; i<NBR_STATIONS; i++){

      if(sommets_traites[i] == 0){
        if(plus_courte_distance[i] <= min){
          a_traiter = 1;
          min=plus_courte_distance[i];
        }
      }
    }

    sommets_traites[a_traiter] = 1;

    for(i=0; i<NBR_STATIONS;i++){
      if(G[a_traiter][i].temps != 99999){
        if(plus_courte_distance[i] >= plus_courte_distance[a_traiter] + G[a_traiter][i].temps){
          plus_courte_distance[i] = plus_courte_distance[a_traiter] + G[a_traiter][i].temps;
          pere[i] = a_traiter;
        }
      }
    }
  }
}
