#include <stdio.h>
#include "menu.h"

void cleanScreen(){

	//For linux:
	//printf("\033[H\033[J");

	//Windows lame debug mode:
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void printOptions(){
	printf("\n\nTabela de operacoes:\n");
	printf("Adicionar dois polinomios <1>\n");
	printf("Calcular a derivada de um polinomio <2>\n");
	printf("Calcular a integral de um polinomio <3>\n\n");
}

void printPrompt(){
	printf("<Manipulador_algebrico> ");
}

int askAgain(){
	char c = getchar(); //consumir \n anterior
	printf("Deseja voltar ao menu? <y/n> ");
	scanf("%c",&c);

	switch(c){
		case 'y':
		return 1;
		break;
		case 'n':
		return 0;
		break;
		default:
		return askAgain();
	}
	
}

void adicionarPolinomios(){

	//printf("adicionarPolinomios()\n");

	printf("Lendo do standard input o polinomio 1...\n");

		//Scanner from poly 1 goes here
		MonomioVariable *var_1 = createMonomioVariable('x',2);
		MonomioVariable *var_2 = createMonomioVariable('z',1);
		MonomioVariable *var_3 = createMonomioVariable('y',3);

		MonomioVariables *variaveis = createVariableList(var_1);
		variaveis = addMonomioVariable(variaveis,var_2);
		variaveis = addMonomioVariable(variaveis,var_3);

		Monomio *mono_um = createMonomio(10,variaveis);
		Polinomio *poly_um = createPolinomio(mono_um);

	printf("Lendo do standard input o polinomio 2...\n");

		//Scanner from poly 2 goes here
		MonomioVariable *var_4 = createMonomioVariable('x',6);
		MonomioVariable *var_5 = createMonomioVariable('y',1);
		MonomioVariable *var_6 = createMonomioVariable('z',4);

		MonomioVariables *variaveis2 = createVariableList(var_4);
		variaveis2 = addMonomioVariable(variaveis2,var_5);
		variaveis2 = addMonomioVariable(variaveis2,var_6);

		Monomio *mono_dois = createMonomio(2,variaveis2);
		Polinomio *poly_dois = createPolinomio(mono_dois);

	printf("Adicionando polinomios...\n");
	printf("Resultado: ");
	printPolinomio(addPolinomios(poly_um,poly_dois));
}

void calcularDerivada(){

	char ordem;

	//printf("calcularDerivada()\n");

	printf("Lendo do standard input o polinomio...\n");

		//Scanner from poly goes here
		MonomioVariable *var_1 = createMonomioVariable('x',2);
		MonomioVariable *var_2 = createMonomioVariable('z',1);
		MonomioVariable *var_3 = createMonomioVariable('y',3);

		MonomioVariables *variaveis = createVariableList(var_1);
		variaveis = addMonomioVariable(variaveis,var_2);
		variaveis = addMonomioVariable(variaveis,var_3);

		Monomio *mono_um = createMonomio(10,variaveis);
		Polinomio *poly_um = createPolinomio(mono_um);

	printf("Deseja derivar em ordem a que variavel? ");
	ordem = getchar(); //consumir \n
	scanf("%c",&ordem);

	printf("\nDerivando polinomio...\n");
	printf("Resultado: \n");
	printPolinomio(derivatePolinomio(poly_um,ordem));
}


void calcularIntegral(){

	char ordem;

	//printf("calcularIntegral()\n");

	printf("Lendo do standard input o polinomio...\n");

		//Scanner from poly goes here
		MonomioVariable *var_1 = createMonomioVariable('x',2);
		MonomioVariable *var_2 = createMonomioVariable('z',1);
		MonomioVariable *var_3 = createMonomioVariable('y',3);

		MonomioVariables *variaveis = createVariableList(var_1);
		variaveis = addMonomioVariable(variaveis,var_2);
		variaveis = addMonomioVariable(variaveis,var_3);

		Monomio *mono_um = createMonomio(10,variaveis);
		Polinomio *poly_um = createPolinomio(mono_um);

	printf("Deseja integrar em ordem a que variavel? ");
	ordem = getchar(); //consumir \n
	scanf("%c",&ordem);

	printf("\nIntegrando polinomio...\n");
	printf("Resultado: \n");
	printPolinomio(integratePolinomio(poly_um,ordem));
}


void menu(){

	cleanScreen();

	int c;

	printOptions();

	printPrompt();
	scanf("%d",&c);

	while(c<1 || c>3){
		printPrompt();
		scanf("%d",&c);
	}

	switch(c){
		case 1:
		adicionarPolinomios();
		break;
		case 2:
		calcularDerivada();
		break;
		case 3:
		calcularIntegral();
		break;
	}

	int ask = askAgain();

	if(ask){
		menu();
	}

}