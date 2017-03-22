#include "monomio.h"
#include <stdlib.h>
#include <stdio.h>

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

MonomioVariables* removeVariable(MonomioVariables * monomioVariables1, char variavel_to_remove){

    MonomioVariables* final = createVariableList(NULL);

    while(monomioVariables1!=NULL){
        MonomioVariable * aux = (MonomioVariable*)monomioVariables1->value;
        if(aux->Variable != variavel_to_remove){
            final = addMonomioVariable(final,aux);
        }
         monomioVariables1=monomioVariables1->next;
    }

    return final;

}

MonomioVariables * changeExponent(MonomioVariables * monomioVariables1 ,int new_exp, char var_to_change){

    MonomioVariables* final = createVariableList(NULL);

    while(monomioVariables1!=NULL){
        MonomioVariable * aux = (MonomioVariable*)monomioVariables1->value;
        if(aux->Variable == var_to_change){
            final = addMonomioVariable(final,createMonomioVariable(var_to_change,new_exp));
        }
        else{
            final = addMonomioVariable(final,aux);
        }
        monomioVariables1=monomioVariables1->next;
    }

    return final;
}

int exponentOfVariable(MonomioVariables * monomioVariables1, char variavel){

       while(monomioVariables1!=NULL)
       {
            MonomioVariable * aux = (MonomioVariable*)monomioVariables1->value;
            if(aux->Variable == variavel){
                return aux->Expoente;
            }
            monomioVariables1=monomioVariables1->next;
       }    

       return -1;
}

int monomioVariablesEquals(MonomioVariables * monomioVariables1, MonomioVariables * monomioVariables2)
{
    int equal_term; // Booleano para saber se ha um termo no outro polinomio com variavel e expoente igual.

	while(monomioVariables1!=NULL)
    {
        equal_term = 0;
        MonomioVariable * to_compare = (MonomioVariable*)monomioVariables1->value;
        MonomioVariables * looks_for_equal = monomioVariables2;

        while(looks_for_equal!=NULL){
                MonomioVariable * aux = (MonomioVariable*)looks_for_equal->value;
                if((aux->Variable == to_compare->Variable) && (aux->Expoente == to_compare->Expoente)){
                    equal_term = 1;
                    break;
                }
                looks_for_equal=looks_for_equal->next;
        }

        if(equal_term==0){
            return 0;
        }

        monomioVariables1=monomioVariables1->next;
    }

    return 1;
}

void printVariables(MonomioVariables * monomioVariables1)
{
    while(monomioVariables1){
        MonomioVariable * temp = (MonomioVariable*)monomioVariables1->value;
        if(temp->Expoente == 1){
            printf("(%c)",temp->Variable);
        }
        else{
            printf("(%c^%d)",temp->Variable,temp->Expoente);
        }
        monomioVariables1 = monomioVariables1->next;
    }
}

Monomio * createEmptyMonomio()
{
	Monomio* monomio = malloc(sizeof(Monomio));
	monomio->coeficient = 0;
    monomio->isNormalized = 0;
	monomio->variables = NULL;
	return monomio;
}

Monomio* createConstant(double constant)
{
    Monomio* monomio = createEmptyMonomio();
    monomio->coeficient = constant;
    monomio->isNormalized = 0;
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

int isConstant(Monomio * monomio1)
{
    return (monomio1->variables == NULL);
}


