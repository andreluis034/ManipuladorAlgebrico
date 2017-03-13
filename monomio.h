#include "list.h"
typedef struct _monomioVariable
{
    char Variable;
    int Expoente;
} MonomioVariable;

typedef List MonomioVariables;

typedef struct _monomio
{
	double Coeficient;
    MonomioVariables Variables;
} Monomio;

MonomioVariable* CreateMonomioVariable(char variable, int expoente);
MonomioVariables* createVariableList(MonomioVariable* monomioVariable);
MonomioVariable* addMonomioVariable(MonomioVariables* monomioVariable, MonomioVariable* VariablePrep);

Monomio* CreateConstant(double constant);
Monomio* CreateMonomio(double coeficient, MonomioVariables* addMonomioVariable);
Monomio* MonomioAddVariable(Monomio* monomio, MonomioVariable* variable);