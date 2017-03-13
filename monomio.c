#include "monomio.h"
#include <stdlib.h>

MonomioVariable* createMonomioVariable(char variable, int expoente)
{
    MonomioVariable* monomioVariable = malloc(sizeof(MonomioVariable));
    monomioVariable->Variable = variable;
    monomioVariable->Expoente = expoente;
    return monomioVariable;
}

MonomioVariables* createVariableList(MonomioVariable* monomioVariable)
{
    return createList(monomioVariable);
}

MonomioVariables* addMonomioVariable(MonomioVariables* monomioVariable, MonomioVariable* toPrepend)
{
    MonomioVariables* variableList = createVariableList(toPrepend);
    variableList->next = monomioVariable;
    return variableList;
}

int monomioVariablesEquals(MonomioVariables * monomioVariables1, MonomioVariables * monomioVariables2)
{
	//TO DO
	return 0;
}

Monomio * createEmptyMonomio()
{
	Monomio* monomio = malloc(sizeof(Monomio));
	monomio->isPositive = 0;
	monomio->coeficient = 0;
	monomio->variables = NULL;
	return monomio;
}

Monomio* createConstant(double constant)
{
    Monomio* monomio = createEmptyMonomio();
	monomio->isPositive = constant >= 0;
    monomio->coeficient = constant;
    return monomio;
}

Monomio* createMonomio(double coeficient, MonomioVariables* addMonomioVariable)
{
    Monomio* monomio = createConstant(coeficient);
    monomio->variables = addMonomioVariable;
    return monomio;
}

Monomio* monomioAddVariable(Monomio* monomio, MonomioVariable* variable)
{
    monomio->variables = addMonomioVariable(monomio->variables, variable);
    return monomio;
}

int monomioCanSum(Monomio * monomio1, Monomio * monomio2)
{
	return monomioVariablesEquals(monomio1->variables, monomio2->variables);
}
