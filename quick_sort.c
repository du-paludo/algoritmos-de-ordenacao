#include <stdio.h>

void imprime_vetor (int vetor[], int tam)
{
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void troca (int vetor[], int a, int b)
{
	int aux;
	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

int particiona (int vetor[], int a, int b, int x, int* numComparacoes)
{
	int m = a - 1;
	for (int i = a; i <= b; i++)
	{
		(*numComparacoes)++;
		if (vetor[i] <= x)
		{
			m++;
			troca(vetor, m, i);
		}
	}
	return m;
}

int quickSort_ (int vetor[], int a, int b, int* numComparacoes)
{
	if (a < b)
	{
		int m = particiona (vetor, a, b, vetor[b], numComparacoes);
		quickSort_ (vetor, a, m - 1, numComparacoes);
		quickSort_ (vetor, m + 1, b, numComparacoes);
	}
	return *numComparacoes;
}

int main()
{
	int vetor[] = {5, 33, 12, 6, 9, 1};
	int tam = 6;
	int numComparacoes = 0;
	quickSort_ (vetor, 0, tam-1, &numComparacoes);
	imprime_vetor (vetor, tam);
	printf("%d\n", numComparacoes);
	return 0;
}
