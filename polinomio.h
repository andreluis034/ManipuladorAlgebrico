#pragma once
#include "list.h"
#include "monomio.h"

typedef List Polinomio;

Polinomio* createPolinomio(Monomio* monomio);
Polinomio* prependMonomio(Polinomio* polinomio, Monomio* monomio);
Polinomio* createEmptyPolinomio();
Polinomio* normalizePolinomio(Polinomio* polinomio);
Polinomio* concatenatePolinomios(Polinomio* polinomio1, Polinomio* polinomio2);
Polinomio* addPolinomios(Polinomio* polinomio1, Polinomio* polinomio2);
Polinomio * derivatePolinomio(Polinomio * polinomio1, char ordem);
Polinomio * integratePolinomio(Polinomio * polinomio1, char ordem);
void printPolinomio(Polinomio * polinomio1);