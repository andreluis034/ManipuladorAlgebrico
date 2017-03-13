#pragma once
#include "list.h"
typedef struct _monomioVariable
{
    char Variable;
    int Expoente;
} MonomioVariable;

typedef List MonomioVariables;

typedef struct _monomio
{
	unsigned char isPositive;
	double coeficient;
    MonomioVariables* variables;
} Monomio;

MonomioVariable* createMonomioVariable(char variable, int expoente);
MonomioVariables* createVariableList(MonomioVariable* monomioVariable);
MonomioVariables* addMonomioVariable(MonomioVariables* monomioVariable, MonomioVariable* VariablePrep);
int monomioVariablesEquals(MonomioVariables* monomioVariables1, MonomioVariables* monomioVariables2);

Monomio* createEmptyMonomio();
Monomio* createConstant(double constant);
Monomio* createMonomio(double coeficient, MonomioVariables* addMonomioVariable);
Monomio* monomioAddVariable(Monomio* monomio, MonomioVariable* variable);
int monomioCanSum(Monomio* monomio1, Monomio* monomio2);