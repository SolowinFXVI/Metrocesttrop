#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "structures.h"
#include "string.h"

List fill_start(List l, int a){
  Element* new= malloc(sizeof(Element));
  new->val = a;
  new->next=l;
  l=new;
  return l;
}

void print_list_path(List l, TAB M,ARC G[NBR_ARCS][NBR_ARCS],char *temps_total){
  if(l==NULL || l->next == NULL){
    printf("liste vide\n");
    exit(013);
  }


    while(l->next != NULL){
      printf("en partant de %s allez jusqu'a %s par la ligne %s\n",M.TAB[l->val].nom, M.TAB[l->next->val].nom, G[l->val][l->next->val].sm2.ligne);
    }
}

int conversion_temps_min(int temps_total){
  int minutes;
  minutes=temps_total/60;
  return minutes;
}

int converison_temps_sec(int temps_total){
  int secondes;
  secondes=temps_total%60;
  return secondes;
}



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


void dijkstra(int pere[NBR_STATIONS], int sommet_depart){

  int sommets_traites[NBR_STATIONS]={0};

  int plus_courte_distance[NBR_STATIONS];
  init_pere(pere);

  sommets_traites[sommet_depart] = 1;

  int i;

  for(i=0; i < NBR_STATIONS; i++){
    if(strcmp(G[sommet_depart][i].temps,"99999")!= 0){
      plus_courte_distance[i]=atoi(G[sommet_depart][i].temps);
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
      if(strcmp(G[a_traiter][i].temps,"99999") != 0){
        if(plus_courte_distance[i] >= plus_courte_distance[a_traiter] + atoi(G[a_traiter][i].temps)){
          plus_courte_distance[i] = plus_courte_distance[a_traiter] + atoi(G[a_traiter][i].temps);
          pere[i] = a_traiter;
        }
      }
    }
  }
}

void plus_court_chemin(ARC G[NBR_ARCS][NBR_ARCS],TAB M, int sommet_depart, int sommet_arrivee)
{
  if(sommet_depart == sommet_arrivee){
    printf("Vous etes deja arrivé...");
    exit(1337);
  }

  int pere[NBR_ARCS];
  List path = NULL;
  int temps_total = 0;

  dijkstra(pere,sommet_depart);

  int depart, arrivee = sommet_arrivee;

  path = fill_start(path,arrivee);

  do {
    depart = pere[arrivee];
    if(depart == -1){
      printf("Pas de chemin possible entre %s et %s\n",M.TAB[sommet_depart].nom, M.TAB[sommet_arrivee].nom);
      exit(94);
    }
    temps_total += atoi(G[depart][arrivee].temps);
    path=fill_start(path,depart);
    arrivee=depart;
  }while(depart != sommet_depart);
  printf("temps de trajet %d minutes et %d secondes\n",conversion_temps_min(temps_total),converison_temps_sec(temps_total));

}
