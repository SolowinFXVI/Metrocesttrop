#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "mct.h"

TAB initialise_sommets(char *str, TAB M){
  M=init_s(M);
  return initialiser_sommets(str, M);
}

ARCS initialise_arcs(char *str,ARCS A, TAB M){
  A=init_a(A);
  return initialiser_arcs(str,A,M);
}

int main(int argc, char *argv[]) {
  TAB M;
  ARCS A;
  M=initialise_sommets("metro.txt",M);
  A=initialise_arcs("metro.txt",A,M);
  initialiser_graph(G);
  printf("showme: %s %s %s\n", G[34][31].sm1.nom,G[34][31].sm2.nom,G[34][31].temps);
  return 0;
}
