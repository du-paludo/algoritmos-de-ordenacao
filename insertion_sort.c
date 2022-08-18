#include <stdio.h>

void imprime_vetor (int v[], int n)
{
        for (int i = 0; i < n; i++)
                printf("%d ", v[i]);
        printf("\n");
}

void troca (int v[], int a, int b)
{
	int aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

int busca (int x, int v[], int n, int* numComparacoes)
{
	if (n < 0)
		return -1;
	(*numComparacoes)++;
	if (x >= v[n])
		return n;
	return busca(x, v, n-1, numComparacoes);
}


void insere (int v[], int n, int* numComparacoes)
{
	int x = busca(v[n], v, n-1, numComparacoes);
	for (int i = n; i > x+1; i--)
		troca(v, i, i-1);
}

int ordena (int v[], int n, int* numComparacoes)
{
	n--;
	if (n > 0)
	{
		ordena(v, n, numComparacoes);
		insere(v, n, numComparacoes);
	}
	return *numComparacoes;
}

int main()
{
	int v[] = {15, 12, 11, 7, 5};
	int n = 5;
	int numComparacoes = 0;
	ordena(v, n, &numComparacoes);
	imprime_vetor(v, n);
	printf("%d\n", numComparacoes);
	return 0;
}
