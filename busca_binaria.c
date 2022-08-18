#include <stdio.h>

int binario(int vetor[], int a, int b, int valor, int* numComparacoes)
{
	if (a > b)
		return -1;
	int m = (a + b) / 2;
	(*numComparacoes)++;
	if (vetor[m] == valor)
		return m;
        (*numComparacoes)++;
	if (vetor[m] < valor)
		return binario(vetor, m + 1, b, valor, numComparacoes);
	return binario(vetor, a, m - 1, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes)
{
	int a = 0;
	int b = tam - 1;
	return binario(vetor, a, b, valor, numComparacoes);
}

int main()
{
        int vetor[] = {4, 6, 9, 11, 13, 15};
        int tam = 6;
	int numComparacoes = 0;
        printf("%d \n", buscaBinaria(vetor, tam, 9, &numComparacoes));
        printf("%d \n", numComparacoes);
	return 0;
}
