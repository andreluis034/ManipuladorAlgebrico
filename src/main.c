#include "stdio.h"
#include "menu.h"

int main(int argc, char const *argv[])
{

	char c;

	printf("Bem-vindo ao manipulador algebrico!\n");
	printf("NOTA: Todos os polinomios inseridos pelo utilizador sao automaticamente normalizados.\n\n");
	printf("Este manipulador aceita monomios com multiplas variaveis.\n");

	while(1){

	printf("Deseja continuar? <y/n> ");

	scanf("%c",&c);

		if(c == 'y'){
			menu();
			break;
		}

		else{
			if(c == 'n'){
				return 0;
			}

			else{
				c = getchar(); //consumir \n
			}
		}

	}

	/*
	MonomioVariable *var_1 = createMonomioVariable('x',2);
	MonomioVariable *var_2 = createMonomioVariable('z',1);
	MonomioVariable *var_3 = createMonomioVariable('y',3);

	MonomioVariables *variaveis = createVariableList(var_1);
	variaveis = addMonomioVariable(variaveis,var_2);
	variaveis = addMonomioVariable(variaveis,var_3);

	Monomio *mono_um = createMonomio(10,variaveis);
	Polinomio *poly_um = createPolinomio(mono_um);

	//printVariables(mono_um->variables);
	//printf("Is constant? %d\n",isConstant(mono_um));

	MonomioVariable *var_4 = createMonomioVariable('x',6);
	MonomioVariable *var_5 = createMonomioVariable('y',1);
	MonomioVariable *var_6 = createMonomioVariable('z',4);

	MonomioVariables *variaveis2 = createVariableList(var_4);
	variaveis2 = addMonomioVariable(variaveis2,var_5);
	variaveis2 = addMonomioVariable(variaveis2,var_6);

	Monomio *mono_dois = createMonomio(2,variaveis2);
	
	poly_um = prependMonomio(poly_um,mono_dois);

	printPolinomio(poly_um);
	


	char ordem = 'h';

	MonomioVariable *var_1 = createMonomioVariable('x',2);
	MonomioVariable *var_2 = createMonomioVariable('z',1);
	MonomioVariable *var_3 = createMonomioVariable('y',3);

	MonomioVariables *variaveis = createVariableList(var_1);
	variaveis = addMonomioVariable(variaveis,var_2);
	variaveis = addMonomioVariable(variaveis,var_3);


	MonomioVariable *var_4 = createMonomioVariable('x',2);
	MonomioVariable *var_5 = createMonomioVariable('y',3);
	MonomioVariable *var_6 = createMonomioVariable('z',1);

	MonomioVariables *variaveis2 = createVariableList(var_4);
	variaveis2 = addMonomioVariable(variaveis2,var_5);
	variaveis2 = addMonomioVariable(variaveis2,var_6);

	Monomio* um = createMonomio(2, variaveis);
	Monomio* dois = createMonomio(3,variaveis);

	Polinomio * ump = createPolinomio(um);
	Polinomio * doisp = createPolinomio(dois);

	printPolinomio(ump);

	printPolinomio(doisp);

	//printf("Derivada em ordem a %c\n",ordem);

	//printPolinomio(derivatePolinomio(ump,ordem));

	//printf("Primitiva em ordem a %c\n",ordem);

	//printPolinomio(integratePolinomio(ump,ordem));

	printf("Somando os dois polinomios...\n");

	printPolinomio(addPolinomios(ump,doisp));

	*/

	return 0;
}