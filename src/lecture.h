#ifndef __LECTURE_H
#define __LECTURE_H

#include "constantes.h"
#include "structures.h"

TAB init_s(TAB M);
TAB initialiser_sommets(char *str, TAB M);
TAB cleanup(TAB M);

ARCS initialiser_arcs(char *str, ARCS A,TAB M);
ARCS init_a(ARCS A);

#endif
