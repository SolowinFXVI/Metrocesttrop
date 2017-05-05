#ifndef __LECTURE_H
#define __LECTURE_H

#include "constantes.h"
#include "structures.h"

TAB init_s(TAB M);
TAB initialiser_sommets(char *str, TAB M);
TAB cleanup(TAB M);

void initialise_graph(char *str, ARC G[NBR_ARCS][NBR_ARCS], TAB M);
void init_g(ARC G[NBR_ARCS][NBR_ARCS]);

#endif
//DEMONTIS BOUZIANE JACQUET
