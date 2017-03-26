#include "polinomio.h"
#include <stdlib.h>
#include <stdio.h>

Polinomio* createPolinomio(Monomio* monomio)
{
	return createList(monomio);
}

Polinomio* prependMonomio(Polinomio * polinomio, Monomio * monomio)
{
	return prependList(polinomio, monomio);
}

Polinomio* createEmptyPolinomio()
{
	return createEmptyList();
}

Polinomio* normalizePolinomio(Polinomio * polinomio)
{
	if (polinomio->value == NULL)
		return polinomio;
	
	Polinomio* normalized = createEmptyPolinomio();
	Polinomio* auxPointer = createEmptyPolinomio();

	while(polinomio != NULL)
	{
		auxPointer = polinomio->next;
		double coeficiente = ((Monomio*)(polinomio->value))->coeficient;
		while (auxPointer != NULL)
		{

			if (monomioCanSum(auxPointer->value, polinomio->value) && !((Monomio *)auxPointer->value)->isNormalized)
			{

				coeficiente += ((Monomio*)(auxPointer->value))->coeficient;
				((Monomio*)(auxPointer->value))->isNormalized = 1;
			}

			auxPointer = auxPointer->next;
		}
		if (!(((Monomio *)polinomio->value)->isNormalized))
		{
			Monomio* newMonomio = createMonomio(coeficiente, ((Monomio*)polinomio->value)->variables);
			normalized = prependMonomio(normalized, newMonomio);
		}
		polinomio = polinomio->next;
	}
	return normalized;
}

Polinomio * concatenatePolinomios(Polinomio * polinomio1, Polinomio * polinomio2)
{
	Polinomio* concatenated = createEmptyPolinomio();

	while(polinomio1 != NULL)
	{
		Monomio* monomio1 = polinomio1->value;
		Monomio* newMonomio = createMonomio(monomio1->coeficient, monomio1->variables);
		concatenated = prependMonomio(concatenated, newMonomio);
		polinomio1 = polinomio1->next;
	}
	while (polinomio2 != NULL)
	{
		Monomio* monomio2 = polinomio2->value;
		Monomio* newMonomio2 = createMonomio(monomio2->coeficient, monomio2->variables);
		concatenated = prependMonomio(concatenated, newMonomio2);
		polinomio2 = polinomio2->next;
	}


	return concatenated;
}

Polinomio * addPolinomios(Polinomio * polinomio1, Polinomio * polinomio2)
{
	return normalizePolinomio(concatenatePolinomios(polinomio1, polinomio2));
}

Polinomio * derivatePolinomio(Polinomio * polinomio1, char ordem){

	Polinomio* derivative = createEmptyPolinomio();

		while(polinomio1!=NULL){

			Monomio* aux = ((Monomio*)(polinomio1->value));
			MonomioVariables* aux_variables = aux->variables;

			if(exponentOfVariable(aux_variables,ordem) == -1){
				//ignorar este membro
				polinomio1=polinomio1->next;
				continue;
			}

			else{
				if(exponentOfVariable(aux_variables,ordem) == 1){
						MonomioVariables* newVariables = removeVariable(aux->variables,ordem);
						Monomio* newMonomio = createMonomio(aux->coeficient,newVariables);
						derivative = prependMonomio(derivative, newMonomio);
				}
				else{
						int aux_coef = exponentOfVariable(aux_variables,ordem)-1;
						MonomioVariables * newVariables = changeExponent(aux->variables,aux_coef,ordem);
						Monomio* newMonomio = createMonomio(aux->coeficient*(double)(aux_coef+1),newVariables);
						derivative = prependMonomio(derivative, newMonomio);
				}
			}
			polinomio1=polinomio1->next;
		}

	return derivative;
}

Polinomio * integratePolinomio(Polinomio * polinomio1, char ordem){

	Polinomio* integral = createEmptyPolinomio();

	while(polinomio1!=NULL)
	{

		Monomio* aux = ((Monomio*)(polinomio1->value));
		MonomioVariables* aux_variables = aux->variables;

		if(exponentOfVariable(aux_variables,ordem) == -1){
			MonomioVariable * new_var = createMonomioVariable(ordem, 1);
			MonomioVariables* new_vars = addMonomioVariable(aux_variables, new_var);
			Monomio* newMonomio = createMonomio(aux->coeficient,new_vars);
			integral = prependMonomio(integral,newMonomio);
		}
		else{
			int aux_exp = exponentOfVariable(aux_variables,ordem)+1;
			MonomioVariables * new_vars = changeExponent(aux_variables,aux_exp,ordem);
			Monomio* newMonomio = createMonomio(aux->coeficient/(double)aux_exp,new_vars); 	
			integral = prependMonomio(integral,newMonomio);
		}

		polinomio1=polinomio1->next;
	}

	//Adicionar a constante de integracao C:

	MonomioVariable * constant_var = createMonomioVariable('C', 1);
	MonomioVariables * constant_vars = createVariableList(constant_var);
	Monomio* constant_monomio = createMonomio(1,constant_vars);
	integral = prependMonomio(integral,constant_monomio); 

	return integral;
}

int isNull(Polinomio * polinomio1) {

	while (polinomio1 != NULL) {
		Monomio * temp = (Monomio *)polinomio1->value;

		if (temp->coeficient != 0) {
			return 0;
		}

		polinomio1 = polinomio1->next;
	}

	return 1;

}

void printPolinomio(Polinomio * polinomio1)
{

	if (isNull(polinomio1)) {
		printf("0.0\n");
		return;
	}

	while(polinomio1!=NULL){

				Monomio * temp = (Monomio *)polinomio1->value;

				if(temp->coeficient == 0){
					polinomio1 = polinomio1->next;
					continue;
				}

				if(isConstant(temp)){
						printf("%.1lf",temp->coeficient);
				}
					else{
							if(temp->coeficient == 1){
								//printf("%c^%d",list->variavel,list->expoente);
								printVariables(temp->variables);
							}
								else{
									printf("%.1lf",temp->coeficient);
									printVariables(temp->variables);
								}	
					}


				if(polinomio1->next!=NULL){
					if((((Monomio *)(polinomio1->next)->value)->coeficient) == 0){
					}
					else{
					printf(" + ");
					}
				}

				polinomio1 = polinomio1->next;

		}

		printf("\n");
}
