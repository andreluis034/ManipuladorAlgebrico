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
	int isNormalized;
    MonomioVariables* variables;
} Monomio;

MonomioVariable* createMonomioVariable(char variable, int expoente);
MonomioVariables* createVariableList(MonomioVariable* monomioVariable);
MonomioVariables* addMonomioVariable(MonomioVariables* monomioVariable, MonomioVariable* VariablePrep);
MonomioVariables* removeVariable(MonomioVariables * monomioVariables1,char variavel_to_remove);
MonomioVariables * changeExponent(MonomioVariables * monomioVariables1 ,int new_exp, char var_to_change);
int exponentOfVariable(MonomioVariables * monomioVariables1, char variavel);
int monomioVariablesEquals(MonomioVariables* monomioVariables1, MonomioVariables* monomioVariables2);
void printVariables(MonomioVariables * monomioVariables1);

Monomio* createEmptyMonomio();
Monomio* createConstant(double constant);
Monomio* createMonomio(double coeficient, MonomioVariables* addMonomioVariable);
Monomio* monomioAddVariable(Monomio* monomio, MonomioVariable* variable);
int monomioCanSum(Monomio* monomio1, Monomio* monomio2);
int isConstant(Monomio * monomio1);
