#include <stdio.h>
#include "menu.h"
#include "parser.h"

void cleanScreen(){

#ifdef __WINDOWS__
	//Windows lame mode:
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
#else
	printf("\033[H\033[J");
#endif


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
	char c;
	printf("\n\nDeseja voltar ao menu? <y/n> ");
	scanf("%c",&c); getchar(); //consumir \n

	switch(c){
		case 'y':
		return 1;
		case 'n':
		return 0;
		default:
		return askAgain();
	}
	
}

void adicionarPolinomios(){

	printf("Introduza o primeiro polinomio: \n");
	Polinomio* poly_um = parseInput();
	if (poly_um == NULL)	//Parse do polinomio falhou
		return;
#ifdef DEBUG
	printPolinomio(poly_um);
#endif

	printf("Introduza o segundo polinomio \n");
	Polinomio* poly_dois = parseInput();
	if (poly_dois == NULL)	//Parse do polinomio falhou
		return;
#ifdef DEBUG
	printPolinomio(poly_dois);
#endif

	printf("Adicionando polinomios...\n");
	printf("Resultado: \n");
	printPolinomio(addPolinomios(poly_um,poly_dois));
}

void calcularDerivada(){

	char ordem;

	printf("Introduza o polinomio: \n");

	Polinomio* poly_um = parseInput();
	if (poly_um == NULL)	//Parse do polinomio falhou
		return;
	poly_um = normalizePolinomio(poly_um);

#ifdef DEBUG
	printPolinomio(poly_um);
#endif

	printf("Deseja derivar em ordem a que variavel? ");
	scanf("%c",&ordem); getchar(); //consumir \n

	printf("\nDerivando polinomio...\n");
	printf("Resultado: \n");
	printPolinomio(derivatePolinomio(poly_um,ordem));
}


void calcularIntegral(){

	char ordem;

	printf("Introduza o polinomio: \n");

	Polinomio* poly_um = parseInput();
	if (poly_um == NULL)	//Parse do polinomio falhou
		return;
	poly_um = normalizePolinomio(poly_um);

#ifdef DEBUG
	printPolinomio(poly_um);
#endif

	printf("Deseja integrar em ordem a que variavel? ");
	scanf("%c",&ordem); getchar(); //consumir \n

	printf("\nIntegrando polinomio...\n");
	printf("Resultado: \n");
	printPolinomio(integratePolinomio(poly_um,ordem));
}


void menu(){

	cleanScreen();

	int c;

	printOptions();

	printPrompt();
	scanf("%d",&c); getchar(); //consumir \n

	while(c<1 || c>3){
		printPrompt();
		scanf("%d",&c); getchar(); //consumir \n
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