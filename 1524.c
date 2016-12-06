//Algoritmos e Complexidade - Turma Ex - 2/2015
//Gustavo Almeida Rodrigues - 48999
//Problema - Fila de Bandejão

#include <stdio.h>
#include <stdlib.h>

int menorDistancia(int *Pessoas, int numeroPessoas, int numeroGrupos)
{
	int i, aux;
	int contador;
	int resposta;
	int *vetor;

	vetor = malloc(sizeof(int)*(numeroPessoas-1));

	for(contador = 0; contador < numeroPessoas - 1; contador++)
	{
		if(contador != 0)
		{
			vetor[contador] = Pessoas[contador] - Pessoas[contador-1];
		}
		else
		{
			vetor[0] = Pessoas[0] - 0;
		}
	}

	for(contador = 0; contador < numeroPessoas - 1; contador++)
	{
		for(i = 0; contador < numeroPessoas - 2; i++)
		{
			if(vetor[i] > vetor[i+1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}

	for(contador = numeroPessoas - (numeroGrupos - 1); contador >= 0; contador--)
	{
		resposta += vetor[contador];
	}

	free(vetor);

	return resposta;
}

int main()
{
	int numeroPessoas;
	int numeroGrupos;
	int contador;
	int Pessoas[1000];

	while(scanf("%d", &numeroPessoas) != EOF)
	{
		scanf("%d", &numeroGrupos);

		for(contador = 0; contador < (numeroPessoas - 1); contador++)
		{
			scanf("%d", &Pessoas[contador]);
		}

		printf("%d\n",menorDistancia(Pessoas, numeroPessoas, numeroGrupos));
	}

	return 0;
}