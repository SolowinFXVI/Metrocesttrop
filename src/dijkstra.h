#ifndef __DIJKSTRA_H
#define __DIJKSTRA_H

#include "structures.h"
void print_list_path(List path,TAB M,ARC G[NBR_ARCS][NBR_ARCS],int temps_total);
void dijkstra(int pere[NBR_STATIONS], int sommet_depart);

void plus_court_chemin(ARC G[NBR_ARCS][NBR_ARCS],TAB M, int sommet_depart, int sommet_arrivee);

#endif
