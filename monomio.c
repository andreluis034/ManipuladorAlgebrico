#include "monomio.h"
#include <stdlib.h>

MonomioVariable* CreateMonomioVariable(char variable, int expoente)
{
    MonomioVariable* monomioVariable = malloc(sizeof(MonomioVariable));
    monomioVariable->Variable = variable;
    monomioVariable->Expoente = expoente;
    return monomioVariable;
}

MonomioVariables* createVariableList(MonomioVariable* monomioVariable)
{
    MonomioVariables* variableList = malloc(sizeof(MonomioVariable));
    variableList->Value = monomioVariable;
    variableList->Next = NULL;
    return variableList;
}

MonomioVariable* addMonomioVariable(MonomioVariables* monomioVariable, MonomioVariable* toPrepend)
{
    MonomioVariable* variableList = createVariableList(toPrepend);
    variableList->Next = monomioVariable;
    return variableList;
}

Monomio* CreateConstant(double constant)
{
    Monomio* monomio = malloc(sizeof(Monomio));
    monomio->Coeficiente = constant;
    monomio->Variables = NULL;
    return monomio;
}

Monomio* CreateMonomio(double coeficient, MonomioVariables* addMonomioVariable)
{
    Monomio* monomio = CreateConstant(coeficient);
    monomio->Variables = addMonomioVariable;
    return monomio;
}

Monomio* MonomioAddVariable(Monomio* monomio, MonomioVariable* variable)
{
    monomio->Variables = addMonomioVariable(monomio->Variables, variable);
    return monomio;
}