//Algoritmos e Complexidade - Turma Ex - 2/2015
//Gustavo Almeida Rodrigues - 48999
//Problema - Lucro (Max Range Sum Query)

#include <stdio.h>
#include <stdlib.h>

#define max(A,B) ((A>B) ? (A):(B))

int calculaMaxRSQ(int Valores[], int Dias, int custoDia)
{
	int soma = 0;
	int maior = 0;
	int contador;

	for(contador = 0; contador < Dias; contador++)
	{
		soma = (Valores[contador] - custoDia) + soma;
		maior = max(maior,soma);
		if( soma < 0 )
		{	
			soma = 0;
		}
	}

	return maior;
}

int main()
{
	int dias;
	int custoDia;
	int Valores[50];
	int contador;

	while(scanf("%d", &dias) != EOF)
	{
		scanf("%d", &custoDia);

		for(contador = 0; contador < dias; contador++)
		{
			scanf("%d", &Valores[contador]);
		}

		printf("%d\n", calculaMaxRSQ(Valores, dias, custoDia));
	}
}