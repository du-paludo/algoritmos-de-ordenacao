#include <stdio.h>

int buscaSequencial (int vetor[], int tam, int valor, int* numComparacoes)
{
	if (tam == 0)
		return -1;
	(*numComparacoes)++;
	if (vetor[tam-1] == valor)
		return tam-1;
	return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int main()
{
        int vetor[] = {4, 6, 9, 11, 12};
        int tam = 5;
        int numComparacoes = 0;
        printf("%d \n", buscaSequencial(vetor, tam, 84, &numComparacoes));
        printf("%d \n", numComparacoes);
        return 0;
}
