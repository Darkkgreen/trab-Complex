//Algoritmos e Complexidade - Turma Ex - 2/2015
//Gustavo Almeida Rodrigues - 48999
//Problema - Motoboy (Problema da Mochila)

#include <stdio.h>
#include <stdlib.h>

int algoritmoSack(int tempos[], int pizzas[], int numero_pizzas, int numero_pedidos)
{
	int linhas, colunas;
	int matrix[numero_pedidos+1][numero_pizzas+1];

	for(linhas = 0; linhas <= numero_pedidos; linhas++)
	{
		matrix[linhas][0] = 0;
	}

	for(colunas = 0; colunas <= numero_pizzas; colunas++)
	{
		matrix[0][colunas] = 0;
	}

	for(linhas = 1; linhas <= numero_pedidos; linhas++)
	{
		for(colunas = 1; colunas <= numero_pizzas; colunas++)
		{
			matrix[linhas][colunas] = matrix[linhas-1][colunas];

			if( (pizzas[linhas] <= colunas) &&
				(tempos[linhas] + matrix[linhas-1][colunas-pizzas[linhas]] > matrix[linhas][colunas]))
			{
				matrix[linhas][colunas] = tempos[linhas] + matrix[linhas-1][colunas-pizzas[linhas]];
			}
		}
	}

	return matrix[numero_pedidos][numero_pizzas];
}

int main()
{
	int *tempos, *pizzas;
	int numero_pizzas;
	int numero_pedidos;
	int contador;
	int resultado;

	while(1)
	{
		scanf("%d", &numero_pedidos);
		if(numero_pedidos == 0)
		{
			return 0;
		}
		scanf("%d", &numero_pizzas);

		tempos = malloc((numero_pedidos+1)*sizeof(int));
		pizzas = malloc((numero_pedidos+1)*sizeof(int));

		for(contador = 0; contador <= numero_pedidos; contador++)
		{
			if(contador == 0)
			{
				tempos[0] = 0;
				pizzas[0] = 0;
			}
			else
			{
				scanf("%d %d", &tempos[contador], &pizzas[contador]);
			}		
		}

		resultado = algoritmoSack(tempos, pizzas, numero_pizzas, numero_pedidos);

		printf("%d min.\n", resultado);
	}
}