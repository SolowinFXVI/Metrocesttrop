#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "structures.h"
#include "string.h"

List fill_start(List l, int a){ //implementation classique d'une liste
  printf("fill_start\n");
  Element* new= malloc(sizeof(Element));
  new->val = a;
  new->next=l;
  l=new;
  return l;
}

void print_list_path(List l, TAB M,ARC G[NBR_ARCS][NBR_ARCS],int temps_total){//affiche la liste
  if(l==NULL || l->next == NULL){
    printf("liste vide\n");
    return ;
  }
    while(l->next != NULL){
      printf("De  %s  allez jusqu'a  %s ligne %s\n",M.TAB[l->val].nom, M.TAB[l->next->val].nom, G[l->val][l->next->val].sm2.ligne);
      l=l->next;
    }
}

int conversion_temps_min(int temps_total){ //simple conversion du temps en minutes
  int minutes;
  minutes=temps_total/60;
  return minutes;
}

int conversion_temps_sec(int temps_total){//va de paire avec la fonction conversion_temps_min et renvoie les secondes restantes
  int secondes;
  secondes=temps_total%60;
  return secondes;
}



int sommets_tous_traites(int sommets_traites[NBR_STATIONS]){//test si le tableau ne contient que des 1 -> retourne 1
  int i;
  for(i=0; i<NBR_STATIONS; i++){
    if(sommets_traites[i]==0){
      return 0;
    }
  }
  return 1;
}

void init_pere(int pere[NBR_ARCS]){//initialise le tableau pere a -1
  printf("init_pere \n");
  int i;
  for(i=0; i<NBR_STATIONS; i++){
    pere[i]=-1;
  }
}


void dijkstra(int pere[NBR_STATIONS], int sommet_depart){//Transforme le tabelau pere en tableau des plus courts chemins
  printf("dijkstra \n");

  int sommets_traites[NBR_STATIONS]={0};
  int plus_courte_distance[NBR_STATIONS];
  sommets_traites[sommet_depart] = 1;
  int i;

  init_pere(pere);

  for(i=0; i < NBR_STATIONS; i++){ //initialisation du tableau plus courte distance
    if(atoi(G[sommet_depart][i].temps) != INFINI){//si i successeur du sommet de depart
      plus_courte_distance[i]=atoi(G[sommet_depart][i].temps);//alors plus courte distance vaut le poids de l'arc
      pere[i]= sommet_depart;
    }
    else{ //sinon plus courte distance vaut l'infini
      plus_courte_distance[i]=INFINI;
    }
  }

  plus_courte_distance[sommet_depart] = 0;

////////////////////////////////////////////////////////////////////////////////
  while(!sommets_tous_traites(sommets_traites)){
    printf("tours de while\n");
    //recherche du prochain sommet
    int min = INFINI, a_traiter;

    for(i=0; i<NBR_STATIONS; i++){//pour toutes les stations

      if(sommets_traites[i] == 0){//si le sommet n'est pas traité
        if(plus_courte_distance[i] <= min){//si la plus courte distance est inferieure au minimum actuel
          a_traiter = i;
          min=plus_courte_distance[i];
        }
      }
    }

    sommets_traites[a_traiter] = 1;

    for(i=0; i<NBR_STATIONS;i++){//pour les successeurs du sommet a_traiter
      if(atoi(G[a_traiter][i].temps) != INFINI){//test si la distance de ce sommet au sommet de depart est plus grande que celle passant par le sommet a_traiter
        if(plus_courte_distance[i] >= plus_courte_distance[a_traiter] + atoi(G[a_traiter][i].temps)){
          //mise a jour de la distance
          plus_courte_distance[i] = plus_courte_distance[a_traiter] + atoi(G[a_traiter][i].temps);
          //donne le pere
          pere[i] = a_traiter;
        }
      }
    }
  }
////////////////////////////////////////////////////////////////////////////////
}

void plus_court_chemin(ARC G[NBR_ARCS][NBR_ARCS],TAB M, int sommet_depart, int sommet_arrivee){//calcul le plus court chemin entre deux sommets
  printf(" plus_court_chemin\n");
  if(sommet_depart == sommet_arrivee){
    printf("Vous etes deja arrivé...");
    return ;
  }

  int pere[NBR_ARCS]; //tableau utilisé par dijkstra
  List path = NULL;//liste de stockage du plus court chemin
  int temps_total = 0;

  dijkstra(pere,sommet_depart); //COEUR DU PROGRAMME : modifie le tableau pere

  int depart, arrivee = sommet_arrivee;

  path = fill_start(path,arrivee);//remplissage du debut de la liste

  do {
    depart = pere[arrivee]; //sommet de depart actuel est le pere du sommet d'arrivée
    if(depart == -1){
      printf("Pas de chemin possible entre %s et %s\n",M.TAB[sommet_depart].nom, M.TAB[sommet_arrivee].nom);
      return ;
    }
    temps_total += atoi(G[depart][arrivee].temps); //incrémentation du temps
    path=fill_start(path,depart);//remplissage de la liste
    arrivee=depart;
  }while(depart != sommet_depart);
  printf("\n");
  print_list_path(path,M,G,temps_total);//affichage du trajet
  printf("\n");
  printf("temps de trajet : %d minutes et %d secondes\n",conversion_temps_min(temps_total),conversion_temps_sec(temps_total));
  //affichage du temps de trajet
  printf("\n");
}
//DEMONTIS BOUZIANE JACQUET
