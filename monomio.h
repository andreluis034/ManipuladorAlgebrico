#include "list.h"
typedef struct _monomioVariavel
{
    char variavel;
    int expoente;
} MonomioVariavel;

typedef List MonomioVariaveis;

typedef struct _monomio
{
	double coeficiente;
    MonomioVariaveis variaveis;
} Monomio;

MonomioVariavel* CreateMonomioVariable(char variable, int expoente);
MonomioVariavel* addMonomioVariable(MonomioVariavel* monomioVariavel, MonomioVariavel* variavelPrep);

Monomio* CreateConstant(double constant);
Monomio* CreateMonomio(double coeficient);
Monomio* MonomioAddVariable(Monomio* addMonomioVariable);