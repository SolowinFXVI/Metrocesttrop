#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  initialiser_sommets(metro.txt);
  initialiser_arcs();
  calcul_trajet();
  afficher_trajet();

  return 0;
}
