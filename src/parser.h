#include "polinomio.h"

typedef enum _readStage
{
	Sinal,
	CoeficienteUnitario,
	CoeficienteDecimal,
	Variavel,
	ExpoenteOperador,
	ExpoenteNumero,
	Fim

} ReadStage;

char* readInput(int ignoreSpace, int* inputSize);
Polinomio* parseInput();
Monomio* parseOne(char* input, int forceSinal, char **rest,  int* sucess);