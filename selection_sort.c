#include <stdio.h>

int minimo (int v[], int a, int b, int* numComparacoes)
{
	int m = a;
	for (int i = a + 1; i <= b; i++)
	{
		(*numComparacoes)++;
		if (v[i] < v[m])
			m = i;
	}
	return m;
}

int troca (int v[], int a, int b)
{
	int tmp;
	tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
	return 0;
}

int selection (int vetor[], int a, int b, int* numComparacoes)
{
	if (a < b)
	{
		int m = minimo(vetor, a, b, numComparacoes);
		troca(vetor, a, m);
		selection(vetor, a + 1, b, numComparacoes);
	}
	return *numComparacoes;
}

int ordena (int vetor[], int tam)
{
	int numComparacoes = 0;
	return selection (vetor, 0, tam-1, &numComparacoes);
}

void imprime_vetor (int vetor[], int tam)
{
        for (int i = 0; i < tam; i++)
                printf("%d ", vetor[i]);
        printf("\n");
}

int main()
{
	int vetor[] = {10, 7, 4, 9, 15, 13};
	int tam = 6;
	printf("%d\n", ordena(vetor, tam));
	imprime_vetor(vetor, tam);
	return 0;
}
