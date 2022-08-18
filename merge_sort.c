#include <stdio.h>

void imprime_vetor (int vetor[], int tam)
{
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void intercala (int vetor[], int a, int m, int b, int* numComparacoes)
{
	if (a < b)
	{
		int aux[b - a + 1];
        int i = a;
       	int j = m + 1;
        int k;
		for (k = 0; k <= b-a; k++)
		{
			(*numComparacoes)++;
			if ((j > b) || (i <= m && vetor[i] <= vetor[j]))
			{
				aux[k] = vetor[i];
				i++;
			}
			else
			{
				aux[k] = vetor[j];
				j++;
			}
		}
		i = 0;
		for (k = a; k <= b; k++)
			vetor[k] = aux[i++];
	}
}

int mergeSort_ (int vetor[], int a, int b, int* numComparacoes)
{
	if (a < b)
	{
		int m = (a + b) / 2;
		mergeSort_(vetor, a, m, numComparacoes);
		mergeSort_(vetor, m + 1, b, numComparacoes);
		intercala(vetor, a, m, b, numComparacoes);
	}
	return *numComparacoes;
}

int main()
{
	int vetor[] = {13, 7, 19, 4};
	int tam = 4;
	int numComparacoes = 0;
	mergeSort_(vetor, 0, tam-1, &numComparacoes);
	imprime_vetor(vetor, tam);
	printf("%d\n", numComparacoes);
	return 0;
}
