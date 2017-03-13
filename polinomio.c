#include "polinomio.h"
#include <stdlib.h>

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

			if (monomioCanSum(auxPointer->value, polinomio->value)) // TODO: && !(auxPointer->normalized))
			{

				coeficiente += ((Monomio*)(auxPointer->value))->coeficient;
				//auxPointer->normalized = 1;
			}

			auxPointer = auxPointer->next;
		}
		if (1)//TODO: (!polinomio->normalized)
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
		prependMonomio(concatenated, newMonomio);
		polinomio1 = polinomio1->next;
	}
	while (polinomio2 != NULL)
	{
		Monomio* monomio2 = polinomio2->value;
		Monomio* newMonomio = createMonomio(monomio2->coeficient, monomio2->variables);
		prependMonomio(concatenated, newMonomio);
		polinomio1 = polinomio1->next;
	}
	return concatenated;
}

Polinomio * addPolinomios(Polinomio * polinomio1, Polinomio * polinomio2)
{
	return normalizePolinomio(concatenatePolinomios(polinomio1, polinomio2));
}
