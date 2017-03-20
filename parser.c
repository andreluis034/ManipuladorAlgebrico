#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INITIAL_SIZE 100
#define bzero(a, b) memset(a,0,b)
#define ERROR_EXPECTED(a) fprintf(stderr, "Expected %s in position %d got '%c' instead.\n",a, i, input[i])

int isContained(char c, char* string)
{
	int i;
	for (i = 0; string[i] != '\0'; ++i)
	{
		if (c == string[i])
			return 1;
	}
	return 0;
}

int MonomioEnds(char c)
{
	return isContained(c, "+-") || c == '\0';
}

int digitBegins(char c)
{
	return isdigit(c) || c == '.';
}

char* readInput(int ignoreSpace, int* inputSize)
{
	int size = INITIAL_SIZE;
	char* input = (char*)malloc(size); input[0] = '\0';
	char c;
	int i = 0;
	while ((c = getchar()) != '\n')
	{
		if (i >= size)
			input = (char*)realloc(input, (size += 16));
		if (ignoreSpace && isspace(c))
			continue;

		input[i++] = c;
	}
	input[i] = '\0';
	if (inputSize != NULL)
		*inputSize = i;
	return input;
}

Polinomio* parseInput()
{
	int success;
	char* input = readInput(1, NULL);
	char* next = input;
	Monomio* aux = parseOne(next, 0, &next, &success);
	Polinomio* pol = createEmptyPolinomio();
	while(aux != NULL)
	{
		if(success == 0)
			return NULL;

		pol = prependMonomio(pol, aux);
		aux = parseOne(next, 1, &next, &success);
	}

	free(input);
	return pol;
}
Monomio* parseOne(char* input, int forceSinal, char **rest, int* success)
{
	int n = strlen(input);
	int i;
	int isPositive = 0;
	*success = 0;

	char coeficiente[n]; 
	bzero(coeficiente, n);
	coeficiente[0] = '0'; //For compatbility with .5
	int coeficientePos = 1;

	char variavel[n]; 
	bzero(variavel, n);
	int variavelPos = 0;

	char expoente[n]; 
	bzero(expoente, n);
	int expoentePos = 0;

	MonomioVariables* s = NULL;
	Monomio* monomio = NULL;

	ReadStage stage = Sinal;
	for(i = 0; i < n; ++i)
	{
		if(stage == Fim)
			break;
		switch(stage)
		{
			case Sinal:
				if(!isContained(input[i], "+-"))
				{
					if(forceSinal)
					{
						ERROR_EXPECTED("operator + or -");
						return;
					}
					if(digitBegins(input[i]))
						stage = CoeficienteUnitario;
					else
						stage = Variavel;
					--i;
					isPositive = 1;
					break;
				}
				isPositive = input[i] == '+';

				if (digitBegins(input[i+1]))
					stage = CoeficienteUnitario;
				else
					stage = Variavel;
				break;
			case CoeficienteUnitario:
				if (input[i] == '.')
				{
					coeficiente[coeficientePos++] = input[i]; 
					stage = CoeficienteDecimal;
					continue;
				}
			case CoeficienteDecimal:
				if (!isdigit(input[i]))
				{
					ERROR_EXPECTED("digit");
					return;
				}
				coeficiente[coeficientePos++] = input[i];
				if (!isdigit(input[i + 1]) && input[i + 1] != '.' )
				{
					if (MonomioEnds(input[i + 1]))
						stage = Fim;
					else
						stage = Variavel;

					double s = atof(coeficiente) * (isPositive ? 1 : -1);
					monomio = createConstant(s);
				}
				break;
			case Variavel:
				variavel[0] = input[i];
				if(MonomioEnds(input[i + 1]))
				{
					MonomioVariable* var = createMonomioVariable(variavel[0], 1);
					monomio = monomioAddVariable(monomio, var);
					stage = Fim;
				}
				else if(isalpha(input[i + 1])) // new variavel
				{
					stage = Variavel;
				}
				else
				{
					stage = ExpoenteOperador;
				}
				break;
			case ExpoenteOperador:
				if(input[i] != '^')
				{
					ERROR_EXPECTED("operador ^");
					return;
				}
				bzero(expoente, n);
				expoentePos = 0;
				stage = ExpoenteNumero;
				break;
			case ExpoenteNumero:
				if(!isdigit(input[i]))
				{
					ERROR_EXPECTED("digit");
					return;
				}
				expoente[expoentePos++] = input[i];
				if(!isdigit(input[i+1]))
				{
					MonomioVariable* var = createMonomioVariable(variavel[0], atoi(expoente));
					monomio = monomioAddVariable(monomio, var);
					if(isalpha(input[i+1]))
						stage = Variavel;
					else
						stage = Fim;
				}
				break;
		}
	}
	*rest = input + i;
	*success = 1;
	return monomio;
}